#pragma comment(lib, "ws2_32.lib") // 명시적인 라이브러리의 링크. 윈속 라이브러리 참조

#include <WinSock2.h>
#include <string>
#include <iostream>
#include <thread>
#include <vector>
#include <sstream>
#include <mutex>
#include <atomic>
#include <Ws2tcpip.h>

#include "main.h"
#include "MySQL.h"
#include "myVar.h"

#define MAX_SIZE 1024
#define MAX_CLIENT 100

using std::cout;
using std::cin;
using std::endl;
using std::string;
std::vector<SOCKET_INFO> sck_list; // 연결된 클라이언트 소켓들을 저장할 배열 선언.
std::mutex sck_list_mutex;

SOCKET_INFO server_sock; // 서버 소켓에 대한 정보를 저장할 변수 선언.
std::atomic<int> client_count{ 0 }; // 클라이언트 수를 추적하는 원자 변수

void add_client();
void server_init(); // socket 초기화 함수. socket(), bind(), listen() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
void send_msg(const char* msg); // send() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
void recv_msg(int idx); // recv() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
void del_client(int idx); // 소켓에 연결되어 있는 client를 제거하는 함수. closesocket() 실행됨. 자세한 내용은 함수 구현부에서 확인.

int main() {
    WSADATA wsa;
    int code = WSAStartup(MAKEWORD(2, 2), &wsa);

    if (code == 0) {
        server_init();

        std::vector<std::thread> th_pool;
        for (int i = 0; i < MAX_CLIENT; i++) {
            th_pool.push_back(std::thread(add_client));
        }

        for (auto& th : th_pool) {
            th.join();
        }

        closesocket(server_sock.sck);
    }
    else {
        cout << "프로그램 종료. (Error code : " << code << ")";
    }

    WSACleanup();

    return 0;
}


void server_init() {
    server_sock.sck = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_sock.sck == INVALID_SOCKET) {
        cout << "소켓 생성 실패. (Error code : " << WSAGetLastError() << ")" << endl;
        exit(EXIT_FAILURE);
    }

    SOCKADDR_IN server_addr = {};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7777);

    // 특정 IP 주소로 바인딩 (예: 127.0.0.1 또는 192.168.0.5)
    const char* ip_address = "192.168.1.125";
    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        cout << "IP 주소 설정 실패." << endl;
        closesocket(server_sock.sck);
        exit(EXIT_FAILURE);
    }

    // bind 함수 호출 수정
    if (::bind(server_sock.sck, (sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        cout << "바인드 실패. (Error code : " << WSAGetLastError() << ")" << endl;
        closesocket(server_sock.sck);
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock.sck, SOMAXCONN) == SOCKET_ERROR) {
        cout << "리스닝 실패. (Error code : " << WSAGetLastError() << ")" << endl;
        closesocket(server_sock.sck);
        exit(EXIT_FAILURE);
    }

    server_sock.ui.setName("server");
    cout << "Server On" << endl;
}


void add_client() {
    while (true) {
        SOCKADDR_IN addr = {};
        int addrsize = sizeof(addr);
        char buf[MAX_SIZE] = {};

        ZeroMemory(&addr, addrsize);

        SOCKET_INFO new_client = {};
        new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);

        if (new_client.sck == INVALID_SOCKET) {
            cout << "클라이언트 소켓 생성 실패. (Error code : " << WSAGetLastError() << ")" << endl;
            continue;
        }

        {
            std::lock_guard<std::mutex> lock(sck_list_mutex);

            if (client_count >= MAX_CLIENT) {
                cout << "최대 클라이언트 수 초과." << endl;
                closesocket(new_client.sck);
                continue;
            }

            sck_list.push_back(new_client);
            client_count++;
        }

        cout << "accept" << endl;

        std::thread th(recv_msg, client_count - 1); // 인덱스를 0부터 시작하도록 변경
        th.detach();
    }
}

void send_msg(const char* msg, int idx) {
    size_t length = strlen(msg);

    //std::lock_guard<std::mutex> lock(sck_list_mutex);
     send(sck_list[idx].sck, msg, length, 0);
    //}
}

void recv_msg(int idx) {
    char buf[MAX_SIZE] = {};

    string msg = "";
    MySQL* mySQL = new MySQL();
    mySQL->Init_Mysql();
    mySQL->set_database("chat");

    while (true) {
        ZeroMemory(&buf, MAX_SIZE);
        if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0) {
            IniMsg();
            multimsg = false;
            msg = buf;
            cout << "========================" << endl;
            cout << "받은 매세지 : " << msg << endl;
            std::stringstream ss(msg);
            cout << "MySQL 전\n";
            sqlMsg = mySQL->QuerySql(msg, idx);
            cout << "MySQL 후 : " << sqlMsg << endl;
            if (!multimsg) { send_msg(sqlMsg.c_str(),idx); }
            cout << client_count << endl;
        }
        else {
            msg = "server notice : " + sck_list[idx].ui.getName() + " 님이 퇴장했습니다.";
            cout << msg << endl;         

            del_client(idx);
            delete mySQL;


            return;
        }
    }
}

void del_client(int idx) {
    std::lock_guard<std::mutex> lock(sck_list_mutex);
    if (idx >= 0 && idx < sck_list.size()) {
        closesocket(sck_list[idx].sck);
        sck_list.erase(sck_list.begin() + idx);
        client_count--;
    }
}
