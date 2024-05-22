#pragma once


extern std::string isTrue;
extern std::string svrMsg;
extern std::string sqlMsg;
extern bool multimsg;



const std::string trueStr = "true";
const std::string falseStr = "false";
const std::string elseStr = "else";
// const char* __true = trueStr.c_str();
// const char* __false = falseStr.c_str();


extern std::string _id_from, _nick_from, _msg;
extern std::string _id_temp, _msg_temp, result;

const char nullChar = '\0';


void clrisTrue()
{
    isTrue.clear();
}


void clrsvrMsg()
{

    svrMsg.clear();
}

void clrsqlMsg()
{

    sqlMsg.clear();
}

void IniMsg()
{
    clrisTrue();
    clrsvrMsg();
    clrsqlMsg();
}
