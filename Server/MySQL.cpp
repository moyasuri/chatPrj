#pragma comment(lib, "ws2_32.lib") //명시적인 라이브러리의 링크. 윈속 라이브러리 참조

#include "MySQL.h"
#include "main.h"
#include <mysql/jdbc.h>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include "main.h"
#include "myVar.h"

using std::cout;
using std::endl;
using std::string;

extern const char nullChar;

std::vector<ROOM_INFO> workingRoom_list(100);
extern std::string _id_from, _nick_from, _msg;
extern std::string _id_temp, _msg_temp, result;


extern bool multimsg;
#define MAX_SIZE 1024 //소켓 박스크기
#define SERVER_INDEX 0








// int타입을 string으로 만들어주는 함수
string MySQL::s_(int e_num) {
    return std::to_string(e_num);
}


// 2024-05-23
// 퍼블릭에 접속해있는 사람만 메세지를 주게 바꾸자

void MySQL::_send_msg(const char* msg, int room_Index) {
    size_t length = strlen(msg);

    // client_cnt 범위 체크
    
    for (int i = 0; i < client_count; i++) {
        try {


            // join_client 멤버들의 소켓으로 메시지 전송
            send(sck_list[i].sck, msg, length, 0);
        }
        catch (const std::exception& e) {
            // 에러 발생 시 처리 (예: 로그 출력, 메시지 전송 실패 알림 등)
            // 예시: 로그 출력
            std::cerr << "Error: sending message to client " << i << ": " << e.what() << std::endl;
        }
    }
}






void MySQL::room_activate(int roomIndex, string myID) {
    
    if (isWorkingRoomIndexExist(roomIndex) == false) {
        workingRoom_list[roomIndex].Room_Index = roomIndex;
    }
    workingRoom_list[roomIndex].join_client.push_back(myID);
}



bool MySQL::isWorkingRoomIndexExist(int roomIndex) {
    for (auto roomInfo : workingRoom_list) {
        if (roomInfo.Room_Index == roomIndex) {
            return true;
        }
    }
    return false;
}



MySQL::MySQL() {
    // 생성자에서 초기화
    driver = nullptr;
    con = nullptr;
    stmt = nullptr;
    pstmt = nullptr;
    res = nullptr;
    res2 = nullptr;

    string _date = "";
    string _id = "";


}

MySQL::~MySQL() {
    // 소멸자에서 메모리 정리
    delete pstmt;
    delete con;
}


void MySQL::Init_Mysql() {
    try {
        // MySQL에 연결
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException& e) {
        std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
        exit(1);
    }
}


void MySQL::set_database(string str) {

    try {
        // 데이터베이스 선택
        con->setSchema(str);
        // db 한글 저장을 위한 셋팅 
        stmt = con->createStatement();
        //stmt->execute("set names euckr");
        stmt->execute("set names 'utf8'");
        // if (stmt) { delete stmt; stmt = nullptr; }
    }
    catch (sql::SQLException& e) {
        // 예외 처리
        std::cerr << "Error setting database schema: " << e.what() << std::endl;
        // 예외 처리 후 필요한 작업을 수행
    }
}



//Room_Index, Room_Type, Room_Title 반환해줌  >> date 추가하기
string MySQL::room_List() {
    int room_Index;
    string room_Title;
    int room_Type;
    string room_Date;
    string line = "";
    string _rlresult = "";
    sql::ResultSet* res = stmt->executeQuery("SELECT Room_Index, Room_Type, Room_Title, Room_Date FROM room_list WHERE (Room_Index>1) ;");

    while (res->next())
    {
        room_Index = res->getInt(1);
        room_Type = res->getInt(2);
        room_Title = res->getString(3);
        room_Date = res->getString(4);
        line = line + "\n" + s_(room_Index) + "*/" + s_(room_Type) + "*/" + room_Title + "*/" + room_Date;
        // ex) 17*/2*/welcome my home*/20211012 3033\n
    }
    if (line.size() > 0)
    {
        _rlresult = s_(e_room_List) + delim + trueStr + delim + line;
    }
    else
    {
        _rlresult = s_(e_room_List) + delim + falseStr;
    }

    return _rlresult;
}


string MySQL::getCurrentTime() {
    std::time_t now = std::time(nullptr);
    struct tm timeInfo;
    localtime_s(&timeInfo, &now);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S", &timeInfo);
    return buffer;
}

string MySQL::QuerySql(string msg, int idx) {

    // indxe retrun값 선언
    string _Index, _ret;
    string getString;
    std::stringstream ss(msg);
    



    ss >> _Index;
    int _Index_Int = stoi(_Index);
    //multimsg = true; // 여러번 보내야할때 잠깐 false로바뀜
    
    switch (_Index_Int)
    {

        // Sign in
    case e_id_try_Signin:
    {
        string _id, _pw;
        ss >> _id >> _pw;
        pstmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = ? AND Member_PW = ?");
        pstmt->setString(1, _id);
        pstmt->setString(2, _pw);
        sql::ResultSet* res = pstmt->executeQuery();

        if (res->next())
        {
            sck_list[idx].ui.setID(_id);
            stmt->execute("UPDATE member SET Join_Room_Index = NULL WHERE Member_ID = '" + _id + "';");// 추가열
            std::string query = "SELECT Nickname, Name FROM member WHERE Member_ID = '" + _id + "'";
            res = stmt->executeQuery(query);


            while (res->next()) {
                sck_list[idx].ui.setNickName(res->getString("Nickname"));
                sck_list[idx].ui.setName(res->getString("Name"));
            }

            myID = sck_list[idx].ui.getID();
            myNICK = sck_list[idx].ui.getNickName();
            cout << myID + "로그인 성공" << endl;
            _ret = s_(e_id_try_Signin) + delim + trueStr;
            break;

        }
        else
        {
            _ret = s_(e_id_try_Signin) + delim + falseStr;
            break;
        }

    }
    case e_id_find_ID:
    {
        string _name, _email;
        ss >> _name >> _email;

        res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Email = '" + _email + "' AND Name = '" + _name + "'");
        if (res->next()) {
            _ret = s_(e_id_find_ID) + delim + trueStr + delim + res->getString("Member_ID");
            break;
        }
        else
        {
            _ret = s_(e_id_find_ID) + delim + falseStr;
            break;
        }
    }
    case e_id_find_PW:
    {
        string _id, _birth, _phone;
        ss >> _id >> _birth >> _phone;

        string respw = "";
        result = "";
        res = stmt->executeQuery("SELECT Member_PW FROM member WHERE Member_ID = '" + _id + \
            "' AND Birth = '" + _birth + "' AND Phone = '" + _phone + "'");

        if (res->next()) {
            _ret = s_(e_id_find_PW) + delim + trueStr + delim + res->getString("Member_PW");
            break;
        }
        else
        {
            _ret = s_(e_id_find_PW) + delim + falseStr;
            break;
        }
    }
    
    // Sign up
    case e_signup_IDchk:
    {
        string _id;
        ss >> _id;
        sql::ResultSet* res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Member_ID = '" + _id + "'");

        // Database에 이미 있는아이디 = true;
        if (res->next()) {
            _ret = s_(e_signup_IDchk) + delim + falseStr;
            break;
        }
        else
        {
            _ret = s_(e_signup_IDchk) + delim + trueStr;
            break;
        }
    }

    case e_signup_NickNamechk:
    {
        string _nickname;
        ss >> _nickname;
        sql::ResultSet* res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Nickname = '" + _nickname + "'");

        // Database에 이미 있는 Nickname =  false;
        if (res->next()) {
            _ret = s_(e_signup_NickNamechk) + delim + falseStr;
            break;
        }
        else
        {
            _ret = s_(e_signup_NickNamechk) + delim + trueStr;
            break;
        }
    }

    case e_signup_Submit:
    {
        pstmt = con->prepareStatement("INSERT INTO member VALUES (?,?,NULL,?,?,?,?,?,NULL,?);");
        string data;
        // ss >> _id >> _email >> _phone >> _birth >> _nickname >> _cha_num >> _pw >> _name;

        int cnt = 1;
        while (ss >> data)
        {
            pstmt->setString(cnt, data);
            cnt++;
        }

        if (pstmt->executeUpdate())
        {
            _ret = s_(e_signup_Submit) + delim + trueStr; //회원가입 등록 완
            break;
        }
        else
        {
            _ret = s_(e_signup_Submit) + delim + falseStr;
            break;
        }
    }

    // editinfo
    case e_edit_PWchk:
    {
        string _pw;
        ss >> _pw;
        pstmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = ? AND Member_PW = ?");
        pstmt->setString(1, myID);
        pstmt->setString(2, _pw);
        sql::ResultSet* res = pstmt->executeQuery();
        if ((res->next()))
        {
            _ret = s_(e_edit_PWchk) + delim + trueStr;
            break;
        }
        else
        {
            _ret = s_(e_edit_PWchk) + delim + falseStr;
            break;
        }
    }

    case e_edit_NickNamechk:
    {
        string _nickname;
        
        ss >> _nickname;
        pstmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Nickname = ?");
        pstmt->setString(1, _nickname);
        cout << "pstmt = con->prepareStatement : " << myID << " " << _nickname << endl;
        sql::ResultSet* res = pstmt->executeQuery();
        if ((res->next()))
        {
            _ret = s_(e_edit_NickNamechk) + delim + falseStr;
            break;
        }
        else
        {
            _ret = s_(e_edit_NickNamechk) + delim + trueStr;
            break;
        }
    }

    case e_edit_Confirm:
    {
        
        // 순서 Email; Phone; Nickname; Cha_Num; Member_PW;        

        string _email, _phone, _nickname, _cha_num, _pw;

        ss >> _email >> _phone >> _nickname >> _cha_num >> _pw;
        pstmt = con->prepareStatement("update member set Email = ?, Phone =?, Nickname = ?,Cha_Num = ?,Member_PW=? WHERE  Member_ID = ?");

        pstmt->setString(1, _email);
        pstmt->setString(2, _phone);
        pstmt->setString(3, _nickname);
        pstmt->setString(4, _cha_num);
        pstmt->setString(5, _pw);
        pstmt->setString(6, myID);

        if (pstmt->executeUpdate())
        {

            sck_list[idx].ui.setChaNum(_cha_num);
            sck_list[idx].ui.setEmail(_email);
            sck_list[idx].ui.setNickName(_nickname);
            sck_list[idx].ui.setPhone(_phone);
            sck_list[idx].ui.setPW(_pw);
            _ret = s_(e_edit_Confirm) + delim + trueStr;
            break;
        }
        else
        {
            _ret = s_(e_edit_Confirm) + delim + falseStr;
            break;
        }
    }
    case e_friends_List:
    {

        
        string query = "SELECT m.Nickname FROM friend_list f INNER JOIN member m ON f.My_Friend_ID\
 = m.Member_ID WHERE f.My_ID = '" + myID + "'";
        res = stmt->executeQuery(query);

        result = "";

        while (res->next()) {
            result += res->getString("Nickname") + delim;
        }

        if (!result.empty()) {
            _ret = s_(e_friends_List) + delim + trueStr + delim + result;
            break;
        }
        else {
            // 친구 아이디를 찾지 못했을 때
            _ret = s_(e_friends_List) + delim + falseStr;
            break;
        }
    }
    case e_friends_Request:
    {
        string reqNick = "";
        string reqID = "";
        string tmp = "";
        _msg = "";
        ss >> reqNick >> std::ws;
        getline(ss, _msg, '\0');

        // 회원 목록에서 지정한 닉네임이 있는지 확인
        string query = "SELECT Member_ID FROM member WHERE Nickname = ?";
        pstmt = con->prepareStatement(query);
        pstmt->setString(1, reqNick);
        res = pstmt->executeQuery();

        if (res->next()) {
            // 닉네임에서 아이디 가져오기
            reqID = res->getString("Member_ID");

            query = "SELECT My_ID FROM friend_list WHERE My_Friend_ID = ?";
            pstmt = con->prepareStatement(query);
            pstmt->setString(1, reqID);
            res = pstmt->executeQuery();

            if (res->next()) {
                // 입력한 회원 닉네임이 이미 친구인 경우
                tmp = res->getString("My_ID");
                if (tmp == myID)
                {
                    _ret = s_(e_friends_Request) + delim + elseStr;
                    break;
                    cout << "Already friends with: " << reqNick << endl;

                }
                else
                {

                }
               
            }

            // 중복된 친구 요청이 있는지 확인 후 요청 추가
            query = "INSERT INTO friend_request (From_Friend_Request_ID, To_Friend_Request_ID, Request_Msg) "
                "SELECT ?, ?, ? WHERE NOT EXISTS (SELECT 1 FROM friend_request WHERE (From_Friend_Request_ID = ? AND To_Friend_Request_ID = ?) OR (From_Friend_Request_ID = ? AND To_Friend_Request_ID = ?))";
            pstmt = con->prepareStatement(query);
            pstmt->setString(1, myID);
            pstmt->setString(2, reqID);
            pstmt->setString(3, _msg);
            pstmt->setString(4, myID);
            pstmt->setString(5, reqID);
            pstmt->setString(6, reqID);
            pstmt->setString(7, myID);

            int updateCount = pstmt->executeUpdate();

            if (updateCount > 0) {
                _ret = s_(e_friends_Request) + delim + trueStr;
                cout << "Friend request sent to: " << reqNick << endl;
            }
            else {
                _ret = s_(e_friends_Request) + delim + elseStr;
                cout << "Failed to send friend request to: " << reqNick << endl;
            }
        }
        else {
            _ret = s_(e_friends_Request) + delim + falseStr;
            cout << "No member found with nickname: " << reqNick << endl;
        }

        break;
    }


    case e_friends_Response_List:
    {

        string query = "SELECT From_Friend_Request_ID, Request_Msg FROM friend_request WHERE To_Friend_Request_ID =  '" + myID + "'";
        stmt = con->createStatement();
        res = stmt->executeQuery(query);

        std::stringstream ss_id_from, ss_msg_from;

        while (res->next()) {
            ss_id_from << res->getString("From_Friend_Request_ID") + delim; // 결과 값을 스트림에 추가
            ss_msg_from << res->getString("Request_Msg") + "\n";
        }

        _id_from = "";
        _nick_from = "";
        _msg = "";
        _id_temp = "";
        _msg_temp = "";
        result = "";

        while (ss_id_from >> _id_temp)
        {
            string query = "SELECT Nickname FROM Member WHERE Member_ID =  '" + _id_temp + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);
            if (res->next()) {
                _nick_from = "*/" + res->getString("Nickname");
                getline(ss_msg_from, _msg_temp);
                result += _nick_from + delim + _msg_temp + delim;
            }
            
        }

        if (!result.empty())
        {
            _ret = s_(e_friends_Response_List) + delim + trueStr + delim + result;
            break;

        }
        else
        {
            _ret = s_(e_friends_Response_List) + delim + falseStr;
            break;
        }
    }

    case e_friends_Accept:
    {
        
        _nick_from = "";
        ss >> _nick_from;

        string query = "SELECT Member_ID FROM member WHERE Nickname = '" + _nick_from + "'";
        stmt = con->createStatement();
        res = stmt->executeQuery(query);

        if (res->next()) {

            string b_id = res->getString("Member_ID");
            sql::PreparedStatement* pstmt;
            pstmt = con->prepareStatement("SELECT From_Friend_Request_ID, To_Friend_Request_ID FROM friend_request WHERE From_Friend_Request_ID = ? AND To_Friend_Request_ID = ?");
            pstmt->setString(1, b_id);
            pstmt->setString(2, myID);


            res = pstmt->executeQuery();

            if (res->next()) {

                pstmt = con->prepareStatement("DELETE FROM friend_request WHERE From_Friend_Request_ID = ? AND To_Friend_Request_ID = ?");
                pstmt->setString(1, b_id);
                pstmt->setString(2, myID);

                int deleteCount = pstmt->executeUpdate();

                if (deleteCount > 0) {

                    pstmt = con->prepareStatement("INSERT INTO friend_list (My_ID, My_Friend_ID) VALUES (?, ?)");
                    pstmt->setString(1, b_id);
                    pstmt->setString(2, myID);
                    pstmt->executeUpdate();
                    pstmt->setString(1, myID);
                    pstmt->setString(2, b_id);
                    pstmt->executeUpdate();

                    // 요청이 성공적으로 삭제되었음을 나타내는 처리
                    _ret = s_(e_friends_Accept) + delim + trueStr;
                    break;
                }
            }
        }
        else
        {
            _ret = s_(e_friends_Accept) + delim + falseStr;
            break;
        }
    }

    case e_friends_Request_Decline:
    {
        
        _nick_from = "";
        ss >> _nick_from;

        string query = "SELECT Member_ID FROM member WHERE Nickname = '" + _nick_from + "'";
        stmt = con->createStatement();
        res = stmt->executeQuery(query);

        if (res->next()) {

            string b_id = res->getString("Member_ID");
            
            // friend request list에서 그 애를 지워야 해.
            pstmt = con->prepareStatement("SELECT From_Friend_Request_ID, To_Friend_Request_ID FROM friend_request WHERE From_Friend_Request_ID = ? AND To_Friend_Request_ID = ?");
            pstmt->setString(1, b_id);
            pstmt->setString(2, myID);


            res = pstmt->executeQuery();

            if (res->next()) {

                pstmt = con->prepareStatement("DELETE FROM friend_request WHERE From_Friend_Request_ID = ? AND To_Friend_Request_ID = ?");
                pstmt->setString(1, b_id);
                pstmt->setString(2, myID);
                pstmt->executeUpdate();

                _ret = s_(e_friends_Request_Decline) + delim + trueStr;
                break;
            }
        }
        else // database에 있는 아이니까 이럴일은 없겠지만.
        {
            _ret = s_(e_friends_Request_Decline) + delim + falseStr;
            break;
        }
    }



    case e_friends_Delete:
    {


        
        string _to_nickname, _msg;

        ss >> _to_nickname;

        string query = "SELECT Member_ID FROM Member WHERE Nickname =  '" + _to_nickname + "'";
        stmt = con->createStatement();
        res = stmt->executeQuery(query);

        if (res->next()) {
            _id_temp = res->getString("Member_ID");

            pstmt = con->prepareStatement("DELETE From friend_list WHERE My_ID = ? AND My_Friend_ID = ?;");
            pstmt->setString(1, myID);
            pstmt->setString(2, _id_temp);
            int rows_affected = pstmt->executeUpdate();
            pstmt = con->prepareStatement("DELETE From friend_list WHERE My_ID = ? AND My_Friend_ID = ?;");
            pstmt->setString(1, _id_temp);
            pstmt->setString(2, myID);
            int rows_affected2 = pstmt->executeUpdate();
            if (rows_affected2 > 0) {
                _ret = s_(e_friends_Delete) + delim + trueStr;
            }
            else
            {
                _ret = s_(e_friends_Delete) + delim + falseStr;
            }
        }
        break;
    }


    case e_message_Cnt:
    {

        
        string _to_nickname, _msg;


        std::stringstream ss_id, ss_date;
        pstmt = con->prepareStatement("SELECT * FROM short_note WHERE To_Short_Note_ID = ? AND (Respond_Short_Note = 0 OR Respond_Short_Note = 4);");
        pstmt->setString(1, myID);
        res = pstmt->executeQuery();

        int cntUnreadMsg = 0;
        while (res->next()) {

            cntUnreadMsg++;
            // 결과 처리
        }
        result = s_(cntUnreadMsg);

        if (!result.empty())
        {
            _ret = s_(e_message_Cnt) + delim + trueStr + delim + result;
            break;

        }
        else
        {
            _ret = s_(e_message_Cnt) + delim + falseStr;
            break;
        }

    }
    case e_message_Send: // 매새지 보내기
    {
        
        string _to_nickname;

        ss >> _to_nickname >> std::ws;;
        getline(ss, _msg, '\0');

        string query = "SELECT Member_ID FROM member WHERE Nickname = '" + _to_nickname + "'";
        stmt = con->createStatement();
        res = stmt->executeQuery(query);



        if (res->next()) {

            string b_id = res->getString("Member_ID");



            
            pstmt = con->prepareStatement("INSERT INTO short_note(From_Short_Note_ID, To_Short_Note_ID, Respond_Short_Note, Short_Note_Datetime, Short_Note_Text) VALUES(?, ? , 0, ?, ? );");
            pstmt->setString(1, myID);
            pstmt->setString(2, b_id);
            pstmt->setString(3, getCurrentTime());
            pstmt->setString(4, _msg);
            //datetime 서버에서 설정 
            int rows_affected = pstmt->executeUpdate();
            if (rows_affected > 0)
            {
                _ret = s_(e_message_Send) + delim + trueStr;
                break;
            }


        }
        else
        {
            _ret = s_(e_message_Send) + delim + falseStr;
        }
        break;
    }
    case e_message_Sent_list: // 보낸 메세지
    {
        
        string _to_nickname, _msg;


        /*string query = "SELECT Member_ID FROM member WHERE Nickname = '" + _to_nickname + "'";
        stmt = con->createStatement();
        res = stmt->executeQuery(query);*/

        std::stringstream ss_id_from, ss_date_from, ss_status;
        pstmt = con->prepareStatement("SELECT * FROM short_note WHERE From_Short_Note_ID = ? AND (Respond_Short_Note = 0 OR Respond_Short_Note = 1 OR Respond_Short_Note = 2 OR Respond_Short_Note = 3);");
        pstmt->setString(1, myID);

        res = pstmt->executeQuery();

        // 이거는 엔터가 들어간 메세지를 구분해야하는 다른곳에서도 쓰일수 있어.
        while (res->next()) {

            ss_id_from << res->getString("To_Short_Note_ID") + delim; // 결과 값을 스트림에 추가
            ss_status << res->getString("Respond_Short_Note") + delim;
            ss_date_from << res->getString("Short_Note_Datetime") + "\n";

            // 결과 처리
        }
        _id_from = "", _nick_from = "";
        _id_temp = "", _msg_temp = "", result = "";
        string _date_from;

        while (ss_id_from >> _id_temp)
        {
            if (ss_status >> _msg_temp)
            {
                if (getline(ss_date_from, _date_from))
                {

                    string query = "SELECT Nickname FROM Member WHERE Member_ID =  '" + _id_temp + "'";
                    stmt = con->createStatement();
                    res = stmt->executeQuery(query);
                    if (res->next()) {
                        _nick_from = "*/" + res->getString("Nickname");
                        result += "\n" + _nick_from + delim + _msg_temp + delim + _date_from;
                    }
                }
            }
        }

        if (!result.empty())
        {
            _ret = s_(e_message_Sent_list) + delim + trueStr + delim + result;
            break;

        }
        else
        {
            _ret = s_(e_message_Sent_list) + delim + falseStr;
            break;
        }

    }
    case e_message_Sent_msg: // 보낸메세지 메세지 보기
    {
        
        string _to_nickname, _msg, _date;
        result = "";

        ss >> _to_nickname;
        getline(ss, _date);
        string query = "SELECT Member_ID FROM Member WHERE Nickname =  '" + _to_nickname + "'";
        stmt = con->createStatement();
        res = stmt->executeQuery(query);

        if (res->next()) {
            _id_temp = res->getString("Member_ID");
            string query = "SELECT Short_Note_Text FROM short_note WHERE To_Short_Note_ID =  '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
            stmt = con->createStatement();
            res2 = stmt->executeQuery(query);
            if (res2->next()) {
                _msg_temp = res2->getString("Short_Note_Text");
                cout << "_msg_temp = " << _msg_temp << endl;
                result += _msg_temp;
            }

        }

        if (!result.empty())
        {
            _ret = s_(e_message_Sent_msg) + delim + trueStr + delim + result;
            break;

        }
        else
        {
            _ret = s_(e_message_Sent_msg) + delim + falseStr;
            break;
        }
    }
    case e_message_Sent_msg_delete: // 보낸메세지 메세지 삭제
    {
        
        string _to_nickname, _msg, _date;
        result = "";

        ss >> _to_nickname;
        getline(ss, _date);
        string query = "SELECT Member_ID FROM Member WHERE Nickname =  '" + _to_nickname + "'";
        cout << "_to_nickname :  " << _to_nickname << endl;
        stmt = con->createStatement();
        res = stmt->executeQuery(query);

        if (res->next()) {
            _id_temp = res->getString("Member_ID");
            string query = "SELECT Short_Note_Text, Respond_Short_Note FROM short_note WHERE To_Short_Note_ID =  '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
            stmt = con->createStatement();
            res2 = stmt->executeQuery(query);
            if (res2->next()) {
                int respondValue = res2->getInt("Respond_Short_Note");
                string updateQuery;
                string deleteQuery;
                stmt = con->createStatement();
                if (respondValue == 0) {
                    updateQuery = "UPDATE short_note SET Respond_Short_Note = 4 WHERE To_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                    int rowsAffected = stmt->executeUpdate(updateQuery); // 업데이트 쿼리 실행
                    if (rowsAffected > 0) {
                        // 업데이트 성공
                        _ret = s_(e_message_Sent_msg_delete) + delim + trueStr;
                        break;
                    }
                    else {
                        // 업데이트 실패
                        _ret = s_(e_message_Sent_msg_delete) + delim + falseStr;
                        break;
                    }
                }
                else if (respondValue == 1) {
                    updateQuery = "UPDATE short_note SET Respond_Short_Note = 5 WHERE To_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                    int rowsAffected = stmt->executeUpdate(updateQuery); // 업데이트 쿼리 실행
                    if (rowsAffected > 0) {
                        // 업데이트 성공
                        _ret = s_(e_message_Sent_msg_delete) + delim + trueStr;
                        break;
                    }
                    else {
                        // 업데이트 실패
                        _ret = s_(e_message_Sent_msg_delete) + delim + falseStr;
                        break;
                    }
                }
                else if ((respondValue == 2 || respondValue == 3)) {
                    deleteQuery = "DELETE FROM short_note WHERE To_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                    int rowsDeleted = stmt->executeUpdate(deleteQuery); // 삭제 쿼리 실행
                    if (rowsDeleted > 0) {
                        // 삭제 성공
                        _ret = s_(e_message_Sent_msg_delete) + delim + trueStr;
                        break;
                    }
                    else {
                        // 삭제 실패
                        _ret = s_(e_message_Sent_msg_delete) + delim + falseStr;
                        break;
                    }
                }
                else
                {
                    break;
                }

            }
        }
        break;
    }
    case e_message_UGiven_list: // 안읽은 메세지 리스트
    {
        
        string _to_nickname, _msg;


        std::stringstream ss_id, ss_date;
        pstmt = con->prepareStatement("SELECT * FROM short_note WHERE To_Short_Note_ID = ? AND (Respond_Short_Note = 0 OR Respond_Short_Note = 4);");
        pstmt->setString(1, myID);
        res = pstmt->executeQuery();

        while (res->next()) {

            ss_id << res->getString("From_Short_Note_ID") + delim; // 결과 값을 스트림에 추가
            ss_date << res->getString("Short_Note_Datetime") + "\n";

            // 결과 처리
        }
        _id_from = "", _nick_from = "";
        _id_temp = "", _msg_temp = "", result = "";

        while (ss_id >> _id_temp)
        {
            string query = "SELECT Nickname FROM Member WHERE Member_ID =  '" + _id_temp + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);
            if (res->next()) {
                getline(ss_date, _msg_temp);
                _nick_from = "*/" + res->getString("Nickname");
                result += "\n" + _nick_from + delim + _msg_temp;

            }
        }

        if (!result.empty())
        {
            _ret = s_(e_message_UGiven_list) + delim + trueStr + delim + result;
            break;

        }
        else
        {
            _ret = s_(e_message_UGiven_list) + delim + falseStr;
            break;
        }

    }
    case e_message_UGiven_msg_delete: // 안읽은 메세지 삭제
    {

        std::stringstream ssa(msg);
        string index_temp;
        
        result = "";
        ss >> _from_nickname;
        getline(ss, _date);
        string query = "SELECT Member_ID FROM Member WHERE Nickname =  '" + _from_nickname + "'";
        stmt = con->createStatement();
        res = stmt->executeQuery(query);

        if (res->next()) {
            _id_temp = res->getString("Member_ID");
            string query = "SELECT Short_Note_Text, Respond_Short_Note FROM short_note WHERE From_Short_Note_ID =  '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
            stmt = con->createStatement();
            res2 = stmt->executeQuery(query);
            if (res2->next()) {
                int respondValue = res2->getInt("Respond_Short_Note");
                string updateQuery;
                string deleteQuery;
                stmt = con->createStatement();
                if (respondValue == 0) {
                    updateQuery = "UPDATE short_note SET Respond_Short_Note = 2 WHERE From_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                    int rowsAffected = stmt->executeUpdate(updateQuery); // 업데이트 쿼리 실행
                    if (rowsAffected > 0) {
                        // 업데이트 성공
                        _ret = s_(e_message_UGiven_msg_delete) + delim + trueStr;
                        break;
                    }
                    else {
                        // 업데이트 실패
                        _ret = s_(e_message_UGiven_msg_delete) + delim + falseStr;
                        break;
                    }
                }
                else if (respondValue == 4) {
                    deleteQuery = "DELETE FROM short_note WHERE From_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                    int rowsDeleted = stmt->executeUpdate(deleteQuery); // 삭제 쿼리 실행
                    if (rowsDeleted > 0) {
                        // 삭제 성공
                        _ret = s_(e_message_UGiven_msg_delete) + delim + trueStr;
                        break;
                    }
                    else {
                        // 삭제 실패
                        _ret = s_(e_message_UGiven_msg_delete) + delim + falseStr;
                        break;
                    }
                }
                else
                {
                    break;
                }

            }
        }
    }
    case e_message_RGiven_list: // 읽은 메세지 리스트
    {
        
        string _to_nickname, _msg;


        std::stringstream ss_id, ss_date;
        pstmt = con->prepareStatement("SELECT * FROM short_note WHERE To_Short_Note_ID = ? AND (Respond_Short_Note = 1 OR Respond_Short_Note = 5);");
        pstmt->setString(1, myID);
        res = pstmt->executeQuery();

        while (res->next()) {

            ss_id << res->getString("From_Short_Note_ID") + delim; // 결과 값을 스트림에 추가
            ss_date << res->getString("Short_Note_Datetime") + "\n";

            // 결과 처리
        }
        _id_from = "", _nick_from = "", _msg = "";
        _id_temp = "", _msg_temp = "", result = "";

        while (ss_id >> _id_temp)
        {
            string query = "SELECT Nickname FROM Member WHERE Member_ID =  '" + _id_temp + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);
            if (res->next()) {
                getline(ss_date, _msg_temp, '\n');
                _nick_from = "*/" + res->getString("Nickname");
                result += "\n" + _nick_from + delim + _msg_temp;

            }
        }

        if (!result.empty())
        {
            _ret = s_(e_message_RGiven_list) + delim + trueStr + delim + result;
            break;

        }
        else
        {
            _ret = s_(e_message_RGiven_list) + delim + falseStr;
            break;
        }

    }
    case e_message_UGiven_msg: // 읽지않은 받은 메세지 보기 *
    {
        
        result = "";

        ss >> _from_nickname;
        getline(ss, _date);
        string query = "SELECT Member_ID FROM Member WHERE Nickname =  '" + _from_nickname + "'";
        stmt = con->createStatement();
        res = stmt->executeQuery(query);

        if (res->next()) {
            _id_temp = res->getString("Member_ID");
            string query = "SELECT Short_Note_Text FROM short_note WHERE From_Short_Note_ID =  '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
            stmt = con->createStatement();
            res2 = stmt->executeQuery(query);
            if (res2->next()) {
                _msg_temp = res2->getString("Short_Note_Text");
                cout << "_msg_temp = " << _msg_temp << endl;
                result += _msg_temp;
            }

        }

        if (!result.empty())
        {
            _ret = s_(e_message_UGiven_msg) + delim + trueStr + delim + result;
            break;

        }
        else
        {
            _ret = s_(e_message_UGiven_msg) + delim + falseStr;
            break;
        }
    }

    case e_message_UGiven_Read: // 읽기
    {
        

        result = "";
        ss >> _from_nickname;
        getline(ss, _date);
        string query = "SELECT Member_ID FROM Member WHERE Nickname =  '" + _from_nickname + "'";
        stmt = con->createStatement();
        res = stmt->executeQuery(query);

        if (res->next()) {
            _id_temp = res->getString("Member_ID");
            string query = "SELECT Respond_Short_Note FROM short_note WHERE From_Short_Note_ID =  '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
            stmt = con->createStatement();
            res2 = stmt->executeQuery(query);
            if (res2->next()) {
                int respondValue = res2->getInt("Respond_Short_Note");
                string updateQuery;
                string deleteQuery;
                stmt = con->createStatement();
                if (respondValue == 0) {
                    updateQuery = "UPDATE short_note SET Respond_Short_Note = 1 WHERE From_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                    int rowsAffected = stmt->executeUpdate(updateQuery); // 업데이트 쿼리 실행
                    if (rowsAffected > 0) {
                        //업데이트 성공
                        _ret = s_(e_message_UGiven_Read) + delim + trueStr;
                        break;
                    }
                    else {
                        //업데이트 실패
                        _ret = s_(e_message_UGiven_Read) + delim + falseStr;
                        break;
                    }
                }
                if (respondValue == 4) {
                    updateQuery = "UPDATE short_note SET Respond_Short_Note = 5 WHERE From_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                    int rowsAffected = stmt->executeUpdate(updateQuery); // 업데이트 쿼리 실행
                    if (rowsAffected > 0) {
                        //업데이트 성공
                        _ret = s_(e_message_UGiven_Read) + delim + trueStr;
                        break;
                    }
                    else {
                        //업데이트 실패
                        _ret = s_(e_message_UGiven_Read) + delim + falseStr;
                        break;
                    }
                }
                else
                {
                    break;
                }

            }
        }
    }
    case e_message_RGiven_msg: // 읽은 받은 메세지 보기 *
    {
        
        string _from_nickname, _msg, _date;
        result = "";

        ss >> _from_nickname;
        getline(ss, _date);
        string query = "SELECT Member_ID FROM Member WHERE Nickname =  '" + _from_nickname + "'";
        stmt = con->createStatement();
        res = stmt->executeQuery(query);

        if (res->next()) {
            _id_temp = res->getString("Member_ID");
            string query = "SELECT Short_Note_Text FROM short_note WHERE From_Short_Note_ID =  '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
            stmt = con->createStatement();
            res2 = stmt->executeQuery(query);
            if (res2->next()) {
                _msg_temp = res2->getString("Short_Note_Text");
                cout << "_msg_temp = " << _msg_temp << endl;
                result += _msg_temp;
            }

        }

        if (!result.empty())
        {
            _ret = s_(e_message_RGiven_msg) + delim + trueStr + delim + result;
            break;

        }
        else
        {
            _ret = s_(e_message_RGiven_msg) + delim + falseStr;
            break;
        }
    }
    case e_message_RGiven_msg_delete: // 읽은 메세지 삭제
    {
        
        string _from_nickname, _msg, _date;
        result = "";

        ss >> _from_nickname;
        getline(ss, _date);
        string query = "SELECT Member_ID FROM Member WHERE Nickname =  '" + _from_nickname + "'";
        stmt = con->createStatement();
        res = stmt->executeQuery(query);

        if (res->next()) {
            _id_temp = res->getString("Member_ID");
            string query = "SELECT Short_Note_Text, Respond_Short_Note FROM short_note WHERE From_Short_Note_ID =  '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
            stmt = con->createStatement();
            res2 = stmt->executeQuery(query);
            if (res2->next()) {
                int respondValue = res2->getInt("Respond_Short_Note");
                string updateQuery;
                string deleteQuery;
                stmt = con->createStatement();
                if (respondValue == 1) {
                    updateQuery = "UPDATE short_note SET Respond_Short_Note = 3 WHERE From_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                    int rowsAffected = stmt->executeUpdate(updateQuery); // 업데이트 쿼리 실행
                    if (rowsAffected > 0) {
                        // 업데이트 성공
                        _ret = s_(e_message_RGiven_msg_delete) + delim + trueStr;
                        break;
                    }
                    else {
                        // 업데이트 실패
                        _ret = s_(e_message_RGiven_msg_delete) + delim + falseStr;
                        break;
                    }
                }
                else if (respondValue == 5) {
                    deleteQuery = "DELETE FROM short_note WHERE From_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                    int rowsDeleted = stmt->executeUpdate(deleteQuery); // 삭제 쿼리 실행
                    if (rowsDeleted > 0) {
                        // 삭제 성공
                        _ret = s_(e_message_RGiven_msg_delete) + delim + trueStr;
                        break;
                    }
                    else {
                        // 삭제 실패
                        _ret = s_(e_message_RGiven_msg_delete) + delim + falseStr;
                        break;
                    }
                }
                else
                {
                    break;
                }

            }
        }
    }

    ////room type (서버 1 공개 2 비공개 3)  - room_PW(없으면 0(공개방))- room_Name 순으로 보내주세요! room_name 에 띄어쓰기 포함 가능해서 뒤로 빼주세요
    //// 방을 만들경우 바로 해당 방으로 입장됨( 해당 방 index가 내가 속한 방 index가 됨
    ////반환값 e_num + IDENTIFIER + True/False + IDETIFIER + 내가 속한 방 index
    ////클라이언트 :같은 방 타입에서 방 이름 중복되면 못들어오게 처리 추가해야됨

    //room list
    case e_room_Create:
    {
        // roomtype + (0 비번없을때)pw(not null) + name
        // roomtype은 1이들어갈수없다.
        // 
        // std::stringstream ss(recv_content); //  없어도돼

        string result = "";

        USERROOMINFO UroomInfo;
        
        int room_Index;
        int count = 0;

        while (ss >> getString) {
            UroomInfo.room_info.push_back(getString);
        }
        UroomInfo.room_Type = UroomInfo.room_info[0];
        UroomInfo.room_info.erase(UroomInfo.room_info.begin());
        UroomInfo.room_PW = UroomInfo.room_info[0];// PW가 없어도 0 보내주기
        UroomInfo.room_info.erase(UroomInfo.room_info.begin());
        
        
        for (auto text : UroomInfo.room_info)
            UroomInfo.room_Title = UroomInfo.room_Title + text + delim;
        
        cout << UroomInfo.room_Type << delim << UroomInfo.room_Title << delim << UroomInfo.room_PW << endl;
        UroomInfo.i_room_Type = std::stoi(UroomInfo.room_Type);
        
        cout << "i_room_Type : " << UroomInfo.i_room_Type << endl;
        if (!(UroomInfo.i_room_Type == e_RT_Server))
        {
            if (UroomInfo.i_room_Type == e_RT_Public)
                pstmt = con->prepareStatement("INSERT INTO room_list (Room_Type, Room_Title, Room_Master, Room_Date) VALUES (?,?,?,?);");
            else
            {
                pstmt = con->prepareStatement("INSERT INTO room_list (Room_Type, Room_Title, Room_Master, Room_Date, Room_PW) VALUES (?,?,?,?,?);");
                pstmt->setString(5, UroomInfo.room_PW);
            }
            pstmt->setInt(1, UroomInfo.i_room_Type);
            pstmt->setString(2, UroomInfo.room_Title);
            pstmt->setString(3, myID); // << 내가 룸마스터다 
            pstmt->setString(4, UroomInfo.room_date);

            int Updated = pstmt->executeUpdate(); // ret > 0 : 업데이트 완료,  = 0 : 실행은 되었으나 업데이트 없음, < 0 : 오류
            cout << "Updated :" << Updated << endl;

            if (Updated > 0)
            {
                pstmt = con->prepareStatement("SELECT* from room_list WHERE Room_Type =? AND Room_Title = ?;");
                pstmt->setInt(1, UroomInfo.i_room_Type);
                pstmt->setString(2, UroomInfo.room_Title);

                sql::ResultSet* res = pstmt->executeQuery();
                
                if ((res->next()))
                {
                    room_Index = res->getInt(1);
                    sck_list[idx].room.setRoom_Index(res->getInt(1));
                    sck_list[idx].room.setRoom_Index(room_Index);
                    sck_list[idx].room.setRoom_Type(res->getInt(2));
                    sck_list[idx].room.setRoom_Title(res->getString(3));
                    sck_list[idx].room.setRoom_Master(res->getString(4));
                    sck_list[idx].room.setRoom_Date(res->getString(5));
                    if (UroomInfo.i_room_Type == e_RT_Private)
                    {
                        sck_list[idx].room.setRoom_PW(res->getString(6));
                    }
                    
                    //sck_list[idx].ui.setJoinRoomIndex(s_(sck_list[idx].room.getRoom_Index()));


   /*                 pstmt = con->prepareStatement("UPDATE member set Join_Room_Index = ? WHERE member_ID = ? ");
                    pstmt->setInt(1, std::stoi(sck_list[idx].ui.getJoinRoomIndex()));
                    pstmt->setString(2, myID);
                    
                    Updated = pstmt->executeUpdate();*/
                    
                    cout << "update member query 완료;" << endl;
                    
                    room_activate(room_Index, myID); // 방 활성화 해주기
                    result = s_(e_room_Create) + delim + trueStr;/*+ IDENTIFIER + sck_list[idx].ui.getJoinRoomIndex(); */// * 내가 몇번방에들어갔는지 알 수 있다.

                    return result;

                    //성공시 들어가는 방의 index (room_list의 primary key) 보내줌
                }
                else {
                    cout << "등록은 성공 but 정보 저장 실패" << endl;
                    result = s_(e_room_Create) + delim + falseStr;
                    return result;
                }
            }
            else
            {
                cout << "등록은 성공 but 정보 저장 실패" << endl;
                result = s_(e_room_Create) + delim + falseStr;
                return result;
            }
        }
        else
        {
            cout << "INSERT INTO 실패" << endl;
            result = s_(e_room_Create) + IDENTIFIER + falseStr;
            return result;
        }
    }

    // enum값만 주면된다.
    case e_room_Exit:
    {
        
        string result;
        string str_room_Index;
        int count = 0;
        int i_room_Index;
        int join_client_num = 0;
        pstmt = con->prepareStatement("UPDATE member set Join_Room_Index = NULL WHERE member_ID = ? ;");
        pstmt->setString(1, myID);
        int rowUpdate = pstmt->executeUpdate();
        cout << "int rows_affected = pstmt->executeUpdate(); " << rowUpdate << endl;
        if (rowUpdate > 0) {
            sck_list[idx].room.room_init();//방정보 초기화
            str_room_Index = sck_list[idx].ui.getJoinRoomIndex();
            i_room_Index = stoi(str_room_Index);
            for (auto id : workingRoom_list[i_room_Index].join_client)
            {
                if (id == myID)
                {
                    join_client_num = count;
                    break;
                }
                count++;
            }
            workingRoom_list[i_room_Index].join_client.erase(workingRoom_list[i_room_Index].join_client.begin() + join_client_num);//내 이름 활성화된 방에서 삭제
            sck_list[idx].ui.setJoinRoomIndex("0");// 방에 안들어간 상태를 0 이라고하자
            result = s_(e_room_Exit) + IDENTIFIER + trueStr;
        }
        else
            result = s_(e_room_Exit) + IDENTIFIER + trueStr;
        return result;
    }

    // 방의 인덱스 + 타입 + 패스워드(없으면안보내도 됨)
    case e_room_Enter:
    {
        
        string result;
        string room_Type;
        string room_Title;
        string room_PW = "";
        string room_Index;
        string isServer = falseStr;
        //std::stringstream ss(recv_content);
        ss >> room_Index >> room_Type >> room_PW;

        cout << room_Index << IDENTIFIER << room_Type << IDENTIFIER << room_PW << endl;
        int i_room_Type = std::stoi(room_Type);
        int i_room_Index = std::stoi(room_Index);

        if (i_room_Type == 3)
        {
            pstmt = con->prepareStatement("SELECT* from room_list WHERE Room_Index =? AND Room_PW =?;");
            cout << "SELECT* from room_list WHERE Room_Index =? " << endl;
            pstmt->setInt(1, i_room_Index);
            pstmt->setString(2, room_PW);
            sql::ResultSet* res = pstmt->executeQuery();

            if (res->next())
                cout << "성공";
            else
            {
                result = s_(e_room_Enter) + delim + falseStr;
                cout << "index 와 pw가 맞지 않습니다" << endl;
                return result;
            }
        }
        cout << "first if -else exit" << endl;
        pstmt = con->prepareStatement("UPDATE member set Join_Room_Index = ? WHERE Member_ID=?;");
        pstmt->setInt(1, std::stoi(room_Index));
        pstmt->setString(2, myID);
        int rowUpdate = pstmt->executeUpdate();
        if (rowUpdate > 0)
            cout << "rowUpdate >0 " << endl;
        else
        {
            result = s_(e_room_Enter) + delim + falseStr;
            return result;
        }

        if (rowUpdate > 0)
        {
            pstmt = con->prepareStatement("SELECT* from room_list WHERE Room_Index =?;");
            cout << "SELECT* from room_list WHERE Room_Index =? " << endl;
            pstmt->setInt(1, i_room_Index);
            sql::ResultSet* res = pstmt->executeQuery();

            if (res->next())
            {
                cout << "  if (pstmt->execute()) : " << endl;
                sck_list[idx].room.setRoom_Index(res->getInt(1));
                sck_list[idx].room.setRoom_Type(res->getInt(2));
                sck_list[idx].room.setRoom_Title(res->getString(3));
                if (i_room_Type != 1)// 서버방은 방장이 없으니 예외 처리
                    sck_list[idx].room.setRoom_Master(res->getString(4));
                sck_list[idx].room.setRoom_Date(res->getString(5));
                if (i_room_Type == 3)// 비밀방만 비밀번호 받으므로 예외 처리
                    sck_list[idx].room.setRoom_PW(res->getString(6));
                sck_list[idx].ui.setJoinRoomIndex(room_Index);
                room_activate(stoi(room_Index), myID);
                if (i_room_Type == 1)
                {
                    isServer = elseStr;
                }
                else
                    isServer = trueStr;
                result = s_(e_room_Enter) + delim + isServer;
                cout << "result : " << result << endl;
                return result;
            }

            else
            {
                cout << "등록은 성공 but 클래스 객체에 정보 저장 실패" << endl;
                result = s_(e_room_Enter) + delim + falseStr;
                return result;
            }
        }
        else
        {
            result = s_(e_room_Enter) + delim + falseStr;
            return result;
        }
    }

    case e_room_show_whole_Text:
    {
        multimsg = true;
        string row;
        string all_Text = "";
        string result;
        string nickname, chat, chat_Data = "";
        int room_index = stoi(sck_list[idx].ui.getJoinRoomIndex());
        pstmt = con->prepareStatement("SELECT member.nickname, room_chat.Chat, room_chat.Chat_Date \
            FROM room_chat\
            JOIN member ON room_chat.Member_ID = member.Member_ID\
            WHERE room_chat.Room_Index = ? ;");
        pstmt->setInt(1, room_index);
        sql::ResultSet* res = pstmt->executeQuery();
        while (res->next())
        {
            nickname = res->getString(1);
            chat = res->getString(2);
            chat_Data = res->getString(3);
            row = s_(e_room_show_whole_Text) + delim + trueStr + delim + nickname + delim + chat + delim + chat_Data + "\n";
            Sleep(50);
            send(sck_list[idx].sck, row.c_str(), row.size(), 0);

        }
        //row = s_(e_room_show_whole_Text) + delim + elseStr;
        //send(sck_list[idx].sck, row.c_str(), row.size(), 0);

        break;
    }

    case e_room_Chat:
    {   multimsg = true;
        std::string modifiedString = msg.substr(3);
        string msg_chat = "";
        string result = "";
        int room_Type;
        string room_Date;
        string myNick;
        string date = getCurrentTime();
        string cha = "";
        cout << msg_chat << endl;
        
        pstmt = con->prepareStatement("SELECT Nickname, Cha_Num from member WHERE Member_ID = ?");
        pstmt->setString(1, myID);
        sql::ResultSet* res = pstmt->executeQuery();
        if (res->next())
        {
            myNick = res->getString(1);
            cha = res -> getString(2);
        }
            
        int room_Index = stoi(sck_list[idx].ui.getJoinRoomIndex());
        pstmt = con->prepareStatement("INSERT INTO room_chat VALUES (NULL,?,?,?,?)");
        pstmt->setString(1, myID);
        pstmt->setString(2, modifiedString);
        pstmt->setString(3, date);
        pstmt->setInt(4, room_Index);
        int rowUpdate = pstmt->executeUpdate();
        cout << "rowUpdate : " << rowUpdate << endl;


        string formattedTime = date.substr(0, 4) + "-" + \
            date.substr(4, 2) + "-" + \
            date.substr(6, 2) + " " + \
            date.substr(8, 2) + ":" + \
            date.substr(10, 2) + ":" + \
            date.substr(12, 2);


        if (rowUpdate > 0)
        {
            msg_chat = s_(e_room_Chat) + delim + trueStr + delim + myNick + delim + cha + delim + modifiedString + delim + formattedTime;
            _send_msg(msg_chat.c_str(), room_Index);// 방에 참여한 모든 사람에게 메시지를 보내는 함수
            cout << "cha num : " << cha << endl;
            
        }
        //return _ret;
        break;
    }

    case e_room_User_Enter:
    {
        // 내아이디로부터 들어가있는 방을 찾고
        // 그 번호로 되어있는 모든 유저의 Nickname을출력하자

        string query = "SELECT m.Join_Room_Index FROM member m where m.Member_ID = '" + myID + "'";
        string roomIndex;
        res = stmt->executeQuery(query);

        cout << "111111" << endl;
        
        while (res->next()) {
            roomIndex = res->getString("Join_Room_Index");
        }


        cout << "22222" << endl;

        if (!roomIndex.empty()) {


            query = "SELECT m.Nickname FROM member m where m.Join_Room_Index = '" + roomIndex + "'";
            res = stmt->executeQuery(query);
            
            result = "";
            while (res->next())
            {
                result += res->getString("Nickname") + delim;
                
            }

            cout << "33333" << endl;
            _ret = s_(e_room_User_Enter) + delim + trueStr + delim + result;

            
            cout << _ret << endl;
            cout << roomIndex << endl;
            _send_msg(_ret.c_str(), stoi(roomIndex));

            multimsg = true;
            cout << "44444" << endl;
            break;
        }
        else {
            
            _ret = s_(e_room_User_Enter) + delim + falseStr;
            cout << "55555" << endl;

            break;
        }

        break;
    }

    case e_room_User_Exit:
    {
        // 내아이디로부터 들어가있는 방을 찾고
        // 그 번호로 되어있는 모든 유저의 Nickname을출력하자

        string query = "SELECT m.Join_Room_Index FROM member m where m.Member_ID = '" + myID + "'";
        string roomIndex;
        res = stmt->executeQuery(query);

        

        while (res->next()) {
            roomIndex = res->getString("Join_Room_Index");
        }



        if (!roomIndex.empty()) {


            query = "SELECT m.Nickname FROM member m where m.Join_Room_Index = '" + roomIndex + "'";
            res = stmt->executeQuery(query);

            result = "";
            while (res->next())
            {
                if (res->getString("Nickname") == myNICK)
                    continue;
                result += res->getString("Nickname") + delim;

            }

            _ret = s_(e_room_User_Exit) + delim + trueStr + delim + result;
            _send_msg(_ret.c_str(), stoi(roomIndex));
            multimsg = true;
            break;
        }
        else {
            // 친구 아이디를 찾지 못했을 때
            _ret = s_(e_room_User_Exit) + delim + falseStr;
            break;
        }

        

        break;
    }

    // 여기 이하 어떻게 할것인지

    case e_room_List:
    {
        _ret = room_List();
        break;
    }
    case e_room_myList:
    {
        string rm_result;
        string Room_Title;
        string Room_Date;
        int Room_Index;
        int Room_Type;

        string rl_line = "";

        pstmt = con->prepareStatement("SELECT Room_Index, Room_Type, Room_Title, Room_Date FROM room_list WHERE Room_Master = ?;");
        pstmt->setString(1, myID);
        sql::ResultSet* res = pstmt->executeQuery();

        while (res->next())
        {
            Room_Index = res->getInt(1);
            Room_Type = res->getInt(2);
            Room_Title = res->getString(3);
            Room_Date = res->getString(4);
            rl_line = rl_line + "\n" + s_(Room_Index) + "*/" + s_(Room_Type) + "*/" + Room_Title + "*/" + Room_Date;
        }
        if (rl_line.size() > 0)
            result = s_(e_room_myList) + delim + trueStr + delim + rl_line;
        else
            result = s_(e_room_myList) + delim + falseStr;
        
        return result;
     
    }
    /*case e_room_Delete:
    {
        std::string roomindex;
        ss >> roomindex;

        int i_room_Index = stoi(roomindex);
        pstmt = con->prepareStatement("DELETE FROM room_list WHERE Room_Master = ? AND Room_Index = ?;");
        pstmt->setString(1, myID);
        pstmt->setInt(2, i_room_Index);
        int rowUpdate = pstmt->executeUpdate();

        if (rowUpdate > 0)
            result = s_(e_room_Delete) + delim + trueStr;
        else
            result = s_(e_room_Delete) + delim + falseStr;
        cout << "result : " << result << endl;
        return result;
    }*/

    case e_room_Delete:
    {
        try {
            std::string roomindex;
            ss >> roomindex;

            // roomindex 값 디버깅 출력
            std::cout << "roomindex: " << roomindex << std::endl;

            int i_room_Index = stoi(roomindex);

            // i_room_Index 값 디버깅 출력
            std::cout << "i_room_Index: " << i_room_Index << std::endl;

            pstmt = con->prepareStatement("DELETE FROM room_list WHERE Room_Master = ? AND Room_Index = ?;");
            pstmt->setString(1, myID);
            pstmt->setInt(2, i_room_Index);

            int rowUpdate = pstmt->executeUpdate();

            if (rowUpdate > 0)
                result = s_(e_room_Delete) + delim + trueStr;
            else
                result = s_(e_room_Delete) + delim + falseStr;

            std::cout << "result : " << result << std::endl;
            return result;
        }
        catch (sql::SQLException& e) {
            std::cerr << "SQLException: " << e.what() << std::endl;
            std::cerr << "SQLState: " << e.getSQLState() << std::endl;
            std::cerr << "ErrorCode: " << e.getErrorCode() << std::endl;
            result = s_(e_room_Delete) + delim + falseStr;
            return result;
        }
        catch (std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
            result = s_(e_room_Delete) + delim + falseStr;
            return result;
        }
    }

    default:
        break;
    }

    return _ret;
}

