#pragma once
#include "enum.h"
#include "MyFunction.h"
#include <iostream>

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// SignupForm에 대한 요약입니다.
	/// </summary>
	public ref class SignupForm : public System::Windows::Forms::Form
	{
	public:
		SignupForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
		SignupForm(MyFunction^ my)
		{
			InitializeComponent();
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &SignupForm::ReceivedMsg);

			String^ currentDirectory = System::Environment::CurrentDirectory;
			
			
			String^ relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\Button\\submit.png");
			btnSubmit->BackgroundImage = Image::FromFile(relativePath);
			
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\Button\\close.png");
			btnCancle->BackgroundImage = Image::FromFile(relativePath);
			

			// 필요에 따라 버튼의 크기 모드를 설정합니다.
			btnSubmit->BackgroundImageLayout = ImageLayout::Stretch;
			btnCancle->BackgroundImageLayout = ImageLayout::Stretch;
			

		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~SignupForm()
		{
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->clientSocket->Close();
				_my->MyEvent -= gcnew Action<String^>(this, &SignupForm::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label10;
	protected:
	private: System::Windows::Forms::TextBox^ txtBoxName;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ txtBoxEmail;
	private: System::Windows::Forms::Button^ btnCancle;
	private: System::Windows::Forms::Button^ btnSubmit;
	private: System::Windows::Forms::ComboBox^ combBoxCha;
	private: System::Windows::Forms::Button^ btnChkAvailability;
	private: System::Windows::Forms::Button^ btnNickChkAvailability;


	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtBoxBirth;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtBoxPhone;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtBoxNickName;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtBoxRechk;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtBoxPW;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtBoxID;
	private: MyFunction^ _my;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SignupForm::typeid));
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtBoxName = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtBoxEmail = (gcnew System::Windows::Forms::TextBox());
			this->btnCancle = (gcnew System::Windows::Forms::Button());
			this->btnSubmit = (gcnew System::Windows::Forms::Button());
			this->combBoxCha = (gcnew System::Windows::Forms::ComboBox());
			this->btnChkAvailability = (gcnew System::Windows::Forms::Button());
			this->btnNickChkAvailability = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtBoxBirth = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtBoxPhone = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtBoxNickName = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtBoxRechk = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtBoxPW = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtBoxID = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label10->Location = System::Drawing::Point(33, 23);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(45, 17);
			this->label10->TabIndex = 70;
			this->label10->Text = L"Name";
			// 
			// txtBoxName
			// 
			this->txtBoxName->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxName->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->txtBoxName->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxName->Location = System::Drawing::Point(37, 55);
			this->txtBoxName->Name = L"txtBoxName";
			this->txtBoxName->Size = System::Drawing::Size(130, 16);
			this->txtBoxName->TabIndex = 1;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label9->Location = System::Drawing::Point(220, 314);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(49, 17);
			this->label9->TabIndex = 68;
			this->label9->Text = L"E-mail";
			// 
			// txtBoxEmail
			// 
			this->txtBoxEmail->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxEmail->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxEmail->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->txtBoxEmail->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxEmail->Location = System::Drawing::Point(221, 342);
			this->txtBoxEmail->Name = L"txtBoxEmail";
			this->txtBoxEmail->Size = System::Drawing::Size(130, 16);
			this->txtBoxEmail->TabIndex = 7;
			// 
			// btnCancle
			// 
			this->btnCancle->BackColor = System::Drawing::Color::Transparent;
			this->btnCancle->FlatAppearance->BorderSize = 0;
			this->btnCancle->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnCancle->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnCancle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancle->Font = (gcnew System::Drawing::Font(L"Georgia", 15));
			this->btnCancle->ForeColor = System::Drawing::Color::Firebrick;
			this->btnCancle->Location = System::Drawing::Point(297, 435);
			this->btnCancle->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCancle->Name = L"btnCancle";
			this->btnCancle->Size = System::Drawing::Size(112, 53);
			this->btnCancle->TabIndex = 66;
			this->btnCancle->UseVisualStyleBackColor = false;
			this->btnCancle->Click += gcnew System::EventHandler(this, &SignupForm::btnCancle_Click);
			// 
			// btnSubmit
			// 
			this->btnSubmit->BackColor = System::Drawing::Color::Transparent;
			this->btnSubmit->FlatAppearance->BorderSize = 0;
			this->btnSubmit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSubmit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSubmit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Georgia", 15));
			this->btnSubmit->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->btnSubmit->Location = System::Drawing::Point(169, 435);
			this->btnSubmit->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(112, 53);
			this->btnSubmit->TabIndex = 65;
			this->btnSubmit->UseVisualStyleBackColor = false;
			this->btnSubmit->Click += gcnew System::EventHandler(this, &SignupForm::btnSubmit_Click);
			// 
			// combBoxCha
			// 
			this->combBoxCha->BackColor = System::Drawing::Color::Ivory;
			this->combBoxCha->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->combBoxCha->FormattingEnabled = true;
			this->combBoxCha->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"izuna", L"mari", L"hihumi" });
			this->combBoxCha->Location = System::Drawing::Point(221, 392);
			this->combBoxCha->Name = L"combBoxCha";
			this->combBoxCha->Size = System::Drawing::Size(121, 24);
			this->combBoxCha->TabIndex = 64;
			// 
			// btnChkAvailability
			// 
			this->btnChkAvailability->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnChkAvailability->Location = System::Drawing::Point(221, 114);
			this->btnChkAvailability->Name = L"btnChkAvailability";
			this->btnChkAvailability->Size = System::Drawing::Size(83, 23);
			this->btnChkAvailability->TabIndex = 63;
			this->btnChkAvailability->Text = L"Check";
			this->btnChkAvailability->UseVisualStyleBackColor = true;
			this->btnChkAvailability->Click += gcnew System::EventHandler(this, &SignupForm::btnChkAvailability_Click);
			// 
			// btnNickChkAvailability
			// 
			this->btnNickChkAvailability->Font = (gcnew System::Drawing::Font(L"Georgia", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNickChkAvailability->Location = System::Drawing::Point(221, 247);
			this->btnNickChkAvailability->Name = L"btnNickChkAvailability";
			this->btnNickChkAvailability->Size = System::Drawing::Size(83, 23);
			this->btnNickChkAvailability->TabIndex = 62;
			this->btnNickChkAvailability->Text = L"Check Availability";
			this->btnNickChkAvailability->UseVisualStyleBackColor = true;
			this->btnNickChkAvailability->Click += gcnew System::EventHandler(this, &SignupForm::btnNickChkAvailability_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Georgia", 8));
			this->label8->Location = System::Drawing::Point(68, 162);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(118, 14);
			this->label8->TabIndex = 61;
			this->label8->Text = L"(Max 16Character)";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label7->Location = System::Drawing::Point(220, 369);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(70, 17);
			this->label7->TabIndex = 60;
			this->label7->Text = L"Character";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label6->Location = System::Drawing::Point(33, 314);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(40, 17);
			this->label6->TabIndex = 59;
			this->label6->Text = L"Birth";
			// 
			// txtBoxBirth
			// 
			this->txtBoxBirth->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxBirth->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxBirth->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->txtBoxBirth->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxBirth->Location = System::Drawing::Point(37, 342);
			this->txtBoxBirth->Name = L"txtBoxBirth";
			this->txtBoxBirth->Size = System::Drawing::Size(130, 16);
			this->txtBoxBirth->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label5->Location = System::Drawing::Point(33, 369);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(48, 17);
			this->label5->TabIndex = 57;
			this->label5->Text = L"Phone";
			// 
			// txtBoxPhone
			// 
			this->txtBoxPhone->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxPhone->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPhone->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->txtBoxPhone->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPhone->Location = System::Drawing::Point(37, 395);
			this->txtBoxPhone->Name = L"txtBoxPhone";
			this->txtBoxPhone->Size = System::Drawing::Size(130, 16);
			this->txtBoxPhone->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label4->Location = System::Drawing::Point(33, 222);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 17);
			this->label4->TabIndex = 55;
			this->label4->Text = L"Nick Name";
			// 
			// txtBoxNickName
			// 
			this->txtBoxNickName->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxNickName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxNickName->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->txtBoxNickName->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxNickName->Location = System::Drawing::Point(37, 249);
			this->txtBoxNickName->Name = L"txtBoxNickName";
			this->txtBoxNickName->Size = System::Drawing::Size(130, 16);
			this->txtBoxNickName->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label3->Location = System::Drawing::Point(220, 160);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(63, 17);
			this->label3->TabIndex = 53;
			this->label3->Text = L"re-check";
			// 
			// txtBoxRechk
			// 
			this->txtBoxRechk->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxRechk->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxRechk->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->txtBoxRechk->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxRechk->Location = System::Drawing::Point(223, 186);
			this->txtBoxRechk->Name = L"txtBoxRechk";
			this->txtBoxRechk->PasswordChar = '*';
			this->txtBoxRechk->Size = System::Drawing::Size(130, 16);
			this->txtBoxRechk->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label2->Location = System::Drawing::Point(33, 159);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(31, 17);
			this->label2->TabIndex = 51;
			this->label2->Text = L"PW";
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxPW->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPW->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->txtBoxPW->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPW->Location = System::Drawing::Point(37, 186);
			this->txtBoxPW->MaxLength = 16;
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->PasswordChar = '*';
			this->txtBoxPW->Size = System::Drawing::Size(130, 16);
			this->txtBoxPW->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label1->Location = System::Drawing::Point(33, 83);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 17);
			this->label1->TabIndex = 49;
			this->label1->Text = L"ID";
			// 
			// txtBoxID
			// 
			this->txtBoxID->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxID->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxID->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->txtBoxID->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxID->Location = System::Drawing::Point(37, 114);
			this->txtBoxID->Name = L"txtBoxID";
			this->txtBoxID->Size = System::Drawing::Size(130, 16);
			this->txtBoxID->TabIndex = 2;
			// 
			// SignupForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(422, 491);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->txtBoxName);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->txtBoxEmail);
			this->Controls->Add(this->btnCancle);
			this->Controls->Add(this->btnSubmit);
			this->Controls->Add(this->combBoxCha);
			this->Controls->Add(this->btnChkAvailability);
			this->Controls->Add(this->btnNickChkAvailability);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->txtBoxBirth);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtBoxPhone);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtBoxNickName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtBoxRechk);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtBoxPW);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtBoxID);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"SignupForm";
			this->Text = L"SignupForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

			private:
				bool isChkIDDup = false;
				bool isChkNickNameDup = false;

	public: void SendMessageForm(int index)
	{

		switch (index)
		{
		case e_signup_IDchk:
		{
			String^ tmptxt_1 = txtBoxID->Text; // textBox는 해당 텍스트 상자의 이름입니다.

			if (!String::IsNullOrEmpty(tmptxt_1))
			{
				int t_index = e_signup_IDchk;
				String^ buffer = _my->s_(t_index) + " " + tmptxt_1;
				_my->SendMessage(buffer);
			}
			else
			{
				MessageBox::Show("Please fill the ID", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}

			break;
		}

		case e_signup_NickNamechk:
		{
			String^ tmptxt_1 = txtBoxNickName->Text;


			if (!String::IsNullOrEmpty(tmptxt_1))
			{
				int t_index = e_signup_NickNamechk;
				String^ buffer = _my->s_(t_index) + " " + tmptxt_1;
				_my->SendMessage(buffer);
			}
			else
			{
				MessageBox::Show("Please fill the nickname", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}

			break;
		}

		case e_signup_Submit:
		{
			if (!isChkIDDup)
			{
				System::Windows::Forms::MessageBox::Show("Please ID duplicate check", "warming", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				break;
			}
			if (!isChkNickNameDup)
			{
				System::Windows::Forms::MessageBox::Show("Please Nickname duplicate check", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				break;
			}
			if (txtBoxPW->Text != txtBoxRechk->Text)
			{

				System::Windows::Forms::MessageBox::Show("Please check the PW", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				break;
			}


			String^ tmptxt_1 = txtBoxID->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_2 = txtBoxEmail->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_3 = txtBoxPhone->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_4 = txtBoxBirth->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_5 = txtBoxNickName->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_6 = combBoxCha->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_7 = txtBoxPW->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_8 = txtBoxName->Text; // textBox는 해당 텍스트 상자의 이름입니다.

			// ID와 PW의 문자열이 채워져있다면
			//if (!String::IsNullOrEmpty(tmptxt_1) && !String::IsNullOrEmpty(tmptxt_2) && !String::IsNullOrEmpty(tmptxt_2)\
			//	&& !String::IsNullOrEmpty(tmptxt_3) && !String::IsNullOrEmpty(tmptxt_4) && !String::IsNullOrEmpty(tmptxt_5)\
			//	&& !String::IsNullOrEmpty(tmptxt_6) && !String::IsNullOrEmpty(tmptxt_7) && !String::IsNullOrEmpty(tmptxt_8)) {

			if (!String::IsNullOrEmpty(tmptxt_1) && !String::IsNullOrEmpty(tmptxt_2) && !String::IsNullOrEmpty(tmptxt_2)\
				&& !String::IsNullOrEmpty(tmptxt_3) && !String::IsNullOrEmpty(tmptxt_4) && !String::IsNullOrEmpty(tmptxt_5)\
				&& !String::IsNullOrEmpty(tmptxt_7) && !String::IsNullOrEmpty(tmptxt_8)) {

				if (tmptxt_6 == "izuna") // 나중에 고치자
				{
					tmptxt_6 = _my->s_(e_character_izuna);
				}
				else if (tmptxt_6 == "mari")
				{
					tmptxt_6 = _my->s_(e_character_mari);
				}
				else if (tmptxt_6 == "hihumi")
				{
					tmptxt_6 = _my->s_(e_character_hihumi);
				}

				int t_index = e_signup_Submit;
				String^ buffer = _my->s_(t_index) + " " + tmptxt_1 + " " + tmptxt_2 + " " + tmptxt_3 + " " + tmptxt_4\
					+ " " + tmptxt_5 + " " + tmptxt_6 + " " + tmptxt_7 + " " + tmptxt_8;
				_my->SendMessage(buffer);
			}
			// 입력값이 없다면,
			else {
				System::Windows::Forms::MessageBox::Show("please fill the blank.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		}

	}

		private: System::Void UpdateTextBoxID()
		{
			txtBoxID->Enabled = false;
		}


		private: System::Void UpdateTextBoxNickname()
		{
			txtBoxNickName->Enabled = false;
		}



		private: void ReceivedMsg(String^ message)
		{
			String^ inputString = message;

			array<String^>^ subString = inputString->Split(' ');

			String^ index_s = subString[0];
			String^ isTrue = subString[1];
			int index = Int32::Parse(index_s);

			switch (index)
			{
			case e_signup_IDchk:
			{

				if (isTrue == "true")
				{
					//txtBoxNickName->Invoke(gcnew Action<String^>(this, &YourFormName::UpdateTextBox), newText);
					txtBoxID->Invoke(gcnew Action(this, &SignupForm::UpdateTextBoxID));
					isChkIDDup = true;
					System::Windows::Forms::MessageBox::Show("You can use this ID", "id check", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else
				{

					System::Windows::Forms::MessageBox::Show("The ID already exists", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				break;
			}
			case e_signup_NickNamechk:
			{
				if (isTrue == "true")
				{
					txtBoxNickName->Invoke(gcnew Action(this, &SignupForm::UpdateTextBoxNickname));
					isChkNickNameDup = true;
					System::Windows::Forms::MessageBox::Show("You can use this Nickname", "nickname check", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else
				{
					System::Windows::Forms::MessageBox::Show("The nickname already exists.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				break;
			}
			case e_signup_Submit:
			{
				if (isTrue == "true")
				{
					System::Windows::Forms::MessageBox::Show("Thank you for signup", "nickname check", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else
				{
					System::Windows::Forms::MessageBox::Show("something wrong..", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				break;
			}

			}

		}


		
		private: System::Void btnChkAvailability_Click(System::Object^ sender, System::EventArgs^ e) {
			btnChkAvailability->NotifyDefault(false);
			SendMessageForm(e_signup_IDchk);
		}
		private: System::Void btnNickChkAvailability_Click(System::Object^ sender, System::EventArgs^ e) {
			btnNickChkAvailability->NotifyDefault(false);
			SendMessageForm(e_signup_NickNamechk);
		}
		private: System::Void btnCancle_Click(System::Object^ sender, System::EventArgs^ e) {
			this->_my->disposed();
			this->Close();

		}
		private: System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
			btnSubmit->NotifyDefault(false);
			SendMessageForm(e_signup_Submit);
		}
};
}
