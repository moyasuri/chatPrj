#pragma once


#include "enum.h"
#include "MyFunction.h"
#include "FindAccount.h"
#include "SignupForm.h"
#include "MainForm.h"


namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
		MyForm(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//

			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &MyForm::ReceivedMsg);
			

			//this->AcceptButton = btnSignIn; // 테두리가 생겨서 삭제
		
			IntroImageSound = gcnew SoundPlayer;

			currentDirectory = System::Environment::CurrentDirectory;
					
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\main.gif");
			PicBoxIntro->ImageLocation = relativePath;
			
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\Button\\signin.png");
			btnSignIn->BackgroundImage = Image::FromFile(relativePath);
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\Button\\signup.png");
			btnSignUp->BackgroundImage = Image::FromFile(relativePath);
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\Button\\findaccount.png");
			btnFindAccount->BackgroundImage = Image::FromFile(relativePath);
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\Button\\exit.png");
			btnExit->BackgroundImage = Image::FromFile(relativePath);

			// 필요에 따라 버튼의 크기 모드를 설정합니다.
			btnSignIn->BackgroundImageLayout = ImageLayout::Stretch;
			btnSignUp->BackgroundImageLayout = ImageLayout::Stretch;
			btnFindAccount->BackgroundImageLayout = ImageLayout::Stretch;
			btnExit->BackgroundImageLayout = ImageLayout::Stretch;


			timerDeletePicBoxIntro = gcnew System::Windows::Forms::Timer();
			timerDeletePicBoxIntro->Interval = 6000;
			timerDeletePicBoxIntro->Tick += gcnew System::EventHandler(this, &MyForm::timerDeletePicBoxIntro_Tick);
			timerDeletePicBoxIntro->Start();

		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm()
		{
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &MyForm::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
				delete IntroImageSound;
		

			}
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtBoxID;
	private: System::Windows::Forms::TextBox^ txtBoxPW;

	private: System::Windows::Forms::Button^ btnSignUp;
	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Button^ btnFindAccount;
		   SignupForm^ signupForm = nullptr;
		   FindAccount^ findaccount = nullptr;
		   MainForm^ mainForm = nullptr;
	private: MyFunction^ _my;



	private: System::Windows::Forms::Timer^ timerDeletePicBoxIntro;
	private: bool isFirstActivation = true;
	private: System::Windows::Forms::Button^ btnSignIn;

	private: SoundPlayer^ IntroImageSound;
	private: System::Windows::Forms::PictureBox^ PicBoxIntro;



	private: System::String^ currentDirectory;
	private: System::String^ relativePath;

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtBoxID = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxPW = (gcnew System::Windows::Forms::TextBox());
			this->btnSignUp = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnFindAccount = (gcnew System::Windows::Forms::Button());
			this->btnSignIn = (gcnew System::Windows::Forms::Button());
			this->PicBoxIntro = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBoxIntro))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Corbel", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(155, 387);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"User   ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Corbel", 11.25F));
			this->label2->Location = System::Drawing::Point(150, 439);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Password";
			// 
			// txtBoxID
			// 
			this->txtBoxID->Location = System::Drawing::Point(260, 385);
			this->txtBoxID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxID->Name = L"txtBoxID";
			this->txtBoxID->Size = System::Drawing::Size(152, 21);
			this->txtBoxID->TabIndex = 1;
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->Location = System::Drawing::Point(260, 438);
			this->txtBoxPW->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->PasswordChar = '*';
			this->txtBoxPW->Size = System::Drawing::Size(152, 21);
			this->txtBoxPW->TabIndex = 2;
			// 
			// btnSignUp
			// 
			this->btnSignUp->BackColor = System::Drawing::Color::Transparent;
			this->btnSignUp->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSignUp->FlatAppearance->BorderSize = 0;
			this->btnSignUp->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSignUp->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSignUp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignUp->ForeColor = System::Drawing::Color::Black;
			this->btnSignUp->Location = System::Drawing::Point(625, 373);
			this->btnSignUp->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSignUp->Name = L"btnSignUp";
			this->btnSignUp->Size = System::Drawing::Size(112, 53);
			this->btnSignUp->TabIndex = 4;
			this->btnSignUp->UseVisualStyleBackColor = false;
			this->btnSignUp->Click += gcnew System::EventHandler(this, &MyForm::btnSignUp_Click);
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::Color::Transparent;
			this->btnExit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnExit->FlatAppearance->BorderSize = 0;
			this->btnExit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnExit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnExit->ForeColor = System::Drawing::Color::Black;
			this->btnExit->Location = System::Drawing::Point(625, 423);
			this->btnExit->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(112, 53);
			this->btnExit->TabIndex = 6;
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
			// 
			// btnFindAccount
			// 
			this->btnFindAccount->BackColor = System::Drawing::Color::Transparent;
			this->btnFindAccount->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnFindAccount->FlatAppearance->BorderSize = 0;
			this->btnFindAccount->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnFindAccount->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnFindAccount->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFindAccount->ForeColor = System::Drawing::Color::Black;
			this->btnFindAccount->Location = System::Drawing::Point(479, 423);
			this->btnFindAccount->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnFindAccount->Name = L"btnFindAccount";
			this->btnFindAccount->Size = System::Drawing::Size(112, 53);
			this->btnFindAccount->TabIndex = 5;
			this->btnFindAccount->UseVisualStyleBackColor = false;
			this->btnFindAccount->Click += gcnew System::EventHandler(this, &MyForm::btnFindAccount_Click);
			// 
			// btnSignIn
			// 
			this->btnSignIn->BackColor = System::Drawing::Color::Transparent;
			this->btnSignIn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSignIn->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->btnSignIn->FlatAppearance->BorderSize = 0;
			this->btnSignIn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSignIn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSignIn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignIn->ForeColor = System::Drawing::Color::Black;
			this->btnSignIn->Location = System::Drawing::Point(479, 373);
			this->btnSignIn->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSignIn->Name = L"btnSignIn";
			this->btnSignIn->Size = System::Drawing::Size(112, 53);
			this->btnSignIn->TabIndex = 3;
			this->btnSignIn->UseVisualStyleBackColor = false;
			this->btnSignIn->Click += gcnew System::EventHandler(this, &MyForm::btnSignIn_Click);
			// 
			// PicBoxIntro
			// 
			this->PicBoxIntro->Location = System::Drawing::Point(0, 0);
			this->PicBoxIntro->Margin = System::Windows::Forms::Padding(2);
			this->PicBoxIntro->Name = L"PicBoxIntro";
			this->PicBoxIntro->Size = System::Drawing::Size(408, 203);
			this->PicBoxIntro->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PicBoxIntro->TabIndex = 7;
			this->PicBoxIntro->TabStop = false;
			this->PicBoxIntro->WaitOnLoad = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(796, 493);
			this->Controls->Add(this->btnFindAccount);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnSignIn);
			this->Controls->Add(this->btnSignUp);
			this->Controls->Add(this->txtBoxPW);
			this->Controls->Add(this->txtBoxID);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->PicBoxIntro);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->VisibleChanged += gcnew System::EventHandler(this, &MyForm::MyForm_VisibleChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBoxIntro))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



		// Img 관련

		//private: bool isFirstActivation = true;




		public: void SendMessageForm(int index)
		{

			switch (index)
			{
			case e_id_try_Signin:
				String^ tmptxt_1 = txtBoxID->Text; // textBox는 해당 텍스트 상자의 이름입니다.
				String^ tmptxt_2 = txtBoxPW->Text; // textBox는 해당 텍스트 상자의 이름입니다.

				int t_index = e_id_try_Signin;

				String^ buffer = t_index.ToString() + " " + tmptxt_1 + " " + tmptxt_2;
				_my->SendMessage(buffer);
				break;
			}

		}

			  //public: void SetMyFunction(MyFunction^ my)
			  //{
			  //	_my = my;
			  //	_my->MyEvent += gcnew Action<String^>(this, &MyForm::ReceivedMsg);
			  //}


		public: void ReceivedMsg(String^ message)
		{
			String^ inputString = message;

			array<String^>^ subString = inputString->Split(' ');

			String^ index_s = subString[0];
			String^ isTrue = subString[1];
			int index = Int32::Parse(index_s);

			switch (index)
			{
				// Hide 할때의 동작			

				case e_id_try_Signin:
				{

					if (isTrue == "true")
					{
						this->Invoke(gcnew MethodInvoker(this, &MyForm::MainFormShow));

					}
					else
					{
						System::Windows::Forms::MessageBox::Show("Check the ID and Password", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
					break;
				}

			}

		}

		public: void MainFormShow()
		{
			if (mainForm == nullptr || mainForm->IsDisposed) {
				mainForm = gcnew MainForm(_my);
				mainForm->Owner = this; // Owner를 설정해야 가능
				this->Hide();
				//this->HomeImageSound->Stop();
				mainForm->Show();
			}
			return;
		}



		private: System::Void btnSignUp_Click(System::Object^ sender, System::EventArgs^ e) {
						btnSignUp->NotifyDefault(false);

			if (signupForm == nullptr || signupForm->IsDisposed) {
				signupForm = gcnew SignupForm(_my);
				signupForm->Show();

			}
			// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
			else {
				signupForm->Activate();
			}
		}



		private: System::Void btnSignIn_Click(System::Object^ sender, System::EventArgs^ e) {
				_my->init();

				if (_my->Connect()) // 이거 자체는 버튼으로 처리하고싶긴해
				{
					btnSignIn->NotifyDefault(false);
					SendMessageForm(e_id_try_Signin);
				}
				else
				{
					System::Windows::Forms::MessageBox::Show("Server is shut down", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

				}
				
		}

		private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();

		}
		private: System::Void btnFindAccount_Click(System::Object^ sender, System::EventArgs^ e) {
			btnFindAccount->NotifyDefault(false);

			if (findaccount == nullptr || findaccount->IsDisposed) {
				findaccount = gcnew FindAccount(_my);
				findaccount->Show();
			}
			// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
			else {
				findaccount->Activate();
			}
		}
		private: System::Void timerDeletePicBoxIntro_Tick(System::Object^ sender, System::EventArgs^ e) {

			this->Controls->Remove(PicBoxIntro); // 컨트롤을 폼에서 제거
			delete PicBoxIntro; // 메모리에서 해제
			// Timer를 중지합니다.
			//timerDeletePicBoxIntro->Stop();
			//IntroImageSound->Stop();
			


		}



	private: System::Void MyForm_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {
		this->txtBoxID->Clear();
		this->txtBoxPW->Clear();
		
		if (isFirstActivation) {
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\BGM\\Theme_152.wav");
			IntroImageSound->SoundLocation = relativePath;

			IntroImageSound->Load();
			IntroImageSound->PlayLooping();


			isFirstActivation = false; // 처음 활성화 시 함수 실행을 건너뛰기
		}


		//HomeImageSound->Play(); // 잠시
	}

};
}

