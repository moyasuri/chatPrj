#include "MyForm.h"
#include "MyFunction.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Client;




[STAThread]


void main(array<String^>^ args) {



	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Client::MyFunction myfunc;

	MyForm my(% myfunc);
	Application::Run(% my);




}