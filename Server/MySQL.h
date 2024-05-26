#pragma once

#include <string>
#include <mysql/jdbc.h>
#include <vector>

using std::string;


const string IDENTIFIER = " ";
const string delim = " ";
const string server = "tcp://127.0.0.1:3306"; // 데이터베이스 주소
const string username = "codingon"; // 데이터베이스 사용자
const string password = "1q2w3e4r5t"; // 데이터베이스 접속 비밀번호

const string trueStr = "true";
const string falseStr = "false";
const string elseStr = "else";



extern std::atomic<int> client_count;







class MySQL {
public:

    MySQL();
    ~MySQL();


    void Init_Mysql();
    void set_database(string str);
    void room_activate(int roomIndex, int idx, string myID);
    void _send_msg(const char* msg, int room_Index);
    
    string QuerySql(string msg, int idx);
    string room_List();
    string room_Delete(string roomidx, int idx);
    string room_myList(int index);
    string s_(int e_num);

    static string getCurrentTime();
     
    
    bool isWorkingRoomIndexExist(int roomIndex);
private:
    // MySQL Connector/C++ 초기화
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;
    sql::ResultSet* res;
    sql::ResultSet* res2;
    
    
private:
    string _from_nickname;
    string _date;
    string myID;

};



struct ROOM_INFO {
    int Room_Index = 0;
    std::vector<std::string> join_client;

};

class USERROOMINFO
{
public:


    USERROOMINFO()
    {
        room_date = MySQL::getCurrentTime();
    }


public:

    int i_room_Type = 0;
    int room_Index = 0;
    string room_Type = "";
    string room_PW = "";
    string room_Title = "";
    string room_date;
    std::vector<string> room_info;


};