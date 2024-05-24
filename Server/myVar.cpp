#include "myVar.h"
#include <string>
#include <atomic>



std::string isTrue = "";
std::string svrMsg = "";
std::string sqlMsg = "";

const char* __true = trueStr.c_str();
const char* __false = falseStr.c_str();
bool multimsg = false;

std::string _id_from = "", _nick_from = "", _msg = "";
std::string _id_temp = "", _msg_temp = "", result = "";

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

bool isNumeric(const std::string& str) {
	for (char c : str) {
		if (!std::isdigit(c)) {
			return false;
		}
	}
	return true;
}