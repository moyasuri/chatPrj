#pragma once
#include <string>


using namespace std;
extern int client_count; // 현재 접속해 있는 클라이언트를 count 할 변수 선언.

extern std::string isTrue;
extern std::string svrMsg;
extern std::string sqlMsg;
extern bool multimsg;
extern const std::string trueStr;
extern const std::string falseStr;
extern const std::string elseStr;
extern const char* __true;
extern const char* __false;

void clrisTrue();
void clrsvrMsg();
void clrsqlMsg();
void IniMsg();
extern std::string _id_from, _nick_from, _msg;
extern std::string _id_temp, _msg_temp, result;
extern const char nullChar;


bool isNumeric(const std::string& str);

enum SignUp
{
    e_signup_IDchk = 11,
    e_signup_NickNamechk,
    e_signup_Submit,
};


enum ID
{
    e_id_try_Signin = 21,
    e_id_find_ID,
    e_id_find_PW,

};

enum EditInfo
{
    e_edit_PWchk = 31,
    e_edit_NickNamechk,
    e_edit_Confirm,

};


enum ShortMessage
{
    e_message_List = 410,
    e_message_Read,
    e_message_Send,
    e_message_Delete,
    e_message_Sent_list,
    e_message_Sent_msg,
    e_message_Sent_msg_delete,
    e_message_UGiven_list,
    e_message_UGiven_msg,
    e_message_UGiven_msg_delete,
    e_message_UGiven_Read,
    e_message_RGiven_list,
    e_message_RGiven_msg,
    e_message_RGiven_msg_delete,
    e_message_Cnt,

};

enum Friends
{
    e_friends_List = 510,
    e_friends_Delete,
    e_friends_search,
    e_friends_Request_Send,
    e_friends_Request_List,
    e_friends_Request_Accept,
    e_friends_Request_Decline,
    e_friends_Request,
    e_friends_Response_List,
    e_friends_Accept,

};

enum RoomList
{
    e_room_Create = 60,
    e_room_Exit,
    e_room_Enter,
    e_room_Delete,
    e_room_List,
    e_room_myList,
    e_room_Chat,
    e_room_show_whole_Text,
    e_room_Chat_send,

};

class User {
public:
    string getMember_ID() {
        return member_ID;
    }
    string getEmail() {
        return email;
    }
    string getPhone() {
        return phone;
    }
    string getBirth() {
        return birth;
    }
    string getNickname() {
        return nickname;
    }
    string getCha_num() {
        return member_ID;
    }
    string getMember_PW() {
        return member_ID;
    }
    string getJoin_room_index() {
        return member_ID;
    }

    string setMember_ID(string member_ID) {
        this->member_ID = member_ID;
    }
    string setEmail(string email) {
        this->email = email;
    }
    string setPhone(string phone) {
        this->phone = phone;
    }
    string setBirth(string birth) {
        this->birth = birth;
    }
    string setNickname(string nickname) {
        this->nickname = nickname;
    }
    string setCha_num(string cha_num) {
        this->cha_num = cha_num;
    }
    string setMember_PW(string pw) {
        this->member_PW = member_PW;
    }
    string setJoin_room_index(string join_room_index) {
        this->join_room_index = join_room_index;
    }

private:
    string member_ID = "";
    string member_PW = "";
    string email = "";
    string phone = "";
    string birth = "";
    string nickname = "";
    string cha_num = "";
    string join_room_index = "";



};

class UserInfo {
public:

    void init() {
        name.clear();
        birth.clear();
        id.clear();
        pw.clear();
        phone.clear();
        nickName.clear();
        joinRoomIndex.clear();
        chaNum.clear();
        email.clear();
    }

    // Getter 함수
    std::string getName() const {
        return name;
    }

    std::string getID() const {
        return id;
    }

    std::string getPW() const {
        return pw;
    }

    std::string getPhone() const {
        return phone;
    }

    std::string getBirth() const {
        return birth;
    }

    std::string getNickName() const {
        return nickName;
    }

    std::string getChaNum() const {
        return chaNum;
    }

    std::string getJoinRoomIndex() const {
        return joinRoomIndex;
    }

    std::string getEmail() const {
        return email;
    }

    // Setter 함수
    void setName(const std::string& newName) {
        name = newName;
    }

    void setID(const std::string& newID) {
        id = newID;
    }

    void setPW(const std::string& newPW) {
        pw = newPW;
    }

    void setPhone(const std::string& newPhone) {
        phone = newPhone;
    }

    void setBirth(const std::string& newBirth) {
        birth = newBirth;
    }

    void setEmail(const std::string& newEmail) {
        email = newEmail;
    }

    void setNickName(const std::string& newNickName) {
        nickName = newNickName;
    }

    void setChaNum(const std::string& newChaNum) {
        chaNum = newChaNum;
    }

    void setJoinRoomIndex(const std::string& newJoinRoomIndex) {
        joinRoomIndex = newJoinRoomIndex;
    }

private:
    std::string name;
    std::string id;
    std::string pw;
    std::string phone;
    std::string email;
    std::string birth;
    std::string nickName;
    std::string chaNum;
    std::string joinRoomIndex;

};

class Room {
public:
    void room_init() {
    }
    int getRoom_Index() const {
        return Room_Index;
    }
    int getRoom_Type() const {
        return Room_Type;
    }
    std::string getRoom_Title() const {
        return Room_Title;
    }
    std::string getRoom_Master() const {
        return Room_Master;
    }
    std::string getRoom_Date() const {
        return Room_Date;
    }
    std::string getRoom_PW() const {
        return Room_PW;
    }

    void setRoom_Index(const int& Room_Index) {
        this->Room_Index = Room_Index;
    }
    void setRoom_Type(const int& Room_Type) {
        this->Room_Type = Room_Type;
    }
    void setRoom_Title(const std::string& Room_Title) {
        this->Room_Master = Room_Title;
    }
    void setRoom_Master(const std::string& Room_Master) {
        this->Room_Master = Room_Master;
    }
    void setRoom_Date(const std::string& Room_Date) {
        this->Room_Date = Room_Date;
    }

    void setRoom_PW(const std::string& Room_PW)
    {
        this->Room_PW = Room_PW;
    }







private:
    int Room_Index;
    int Room_Type;
    std::string Room_Title;
    std::string Room_Master;
    std::string Room_Date;
    std::string Room_PW;

};