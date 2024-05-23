#pragma once
#include "MyFunction.h"
#include "enum.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// EditProfile에 대한 요약입니다.
	/// </summary>
	public ref class EditProfile : public System::Windows::Forms::Form
	{
	public:
		EditProfile(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
		EditProfile(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &EditProfile::ReceivedMsg);
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~EditProfile()
		{
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &EditProfile::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}
			if (components)
			{
				delete components;
			}
		}
	
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ txtBoxPW;

	private: System::Windows::Forms::TextBox^ txtBoxPW_new;
	private: System::Windows::Forms::TextBox^ txtBoxPW_Confirm;
	private: System::Windows::Forms::TextBox^ txtBoxNickName;
	private: System::Windows::Forms::TextBox^ txtBoxPhone;
	private: System::Windows::Forms::TextBox^ txtBoxEmail;
	private: System::Windows::Forms::ComboBox^ combBoxCha;
	private: MyFunction^ _my;
	private: bool isChkNickName = false;

	private: System::Windows::Forms::Button^ btnPWchk;
	private: System::Windows::Forms::Button^ btnNickNameduplicateChk;




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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtBoxPW = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxPW_new = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxPW_Confirm = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxNickName = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxPhone = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxEmail = (gcnew System::Windows::Forms::TextBox());
			this->combBoxCha = (gcnew System::Windows::Forms::ComboBox());
			this->btnPWchk = (gcnew System::Windows::Forms::Button());
			this->btnNickNameduplicateChk = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(74, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Current Password";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(317, 185);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(126, 15);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Confirm Password";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(74, 185);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 15);
			this->label3->TabIndex = 0;
			this->label3->Text = L"New Password";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(74, 281);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 15);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Nickname";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(74, 382);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(50, 15);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Phone";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(74, 469);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(69, 15);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Character";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(317, 382);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(49, 15);
			this->label7->TabIndex = 0;
			this->label7->Text = L"E-mail";
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->Location = System::Drawing::Point(75, 94);
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->Size = System::Drawing::Size(121, 25);
			this->txtBoxPW->TabIndex = 1;
			// 
			// txtBoxPW_new
			// 
			this->txtBoxPW_new->Enabled = false;
			this->txtBoxPW_new->Location = System::Drawing::Point(75, 214);
			this->txtBoxPW_new->Name = L"txtBoxPW_new";
			this->txtBoxPW_new->Size = System::Drawing::Size(121, 25);
			this->txtBoxPW_new->TabIndex = 1;
			// 
			// txtBoxPW_Confirm
			// 
			this->txtBoxPW_Confirm->Enabled = false;
			this->txtBoxPW_Confirm->Location = System::Drawing::Point(320, 214);
			this->txtBoxPW_Confirm->Name = L"txtBoxPW_Confirm";
			this->txtBoxPW_Confirm->Size = System::Drawing::Size(121, 25);
			this->txtBoxPW_Confirm->TabIndex = 1;
			// 
			// txtBoxNickName
			// 
			this->txtBoxNickName->Enabled = false;
			this->txtBoxNickName->Location = System::Drawing::Point(75, 313);
			this->txtBoxNickName->Name = L"txtBoxNickName";
			this->txtBoxNickName->Size = System::Drawing::Size(121, 25);
			this->txtBoxNickName->TabIndex = 1;
			// 
			// txtBoxPhone
			// 
			this->txtBoxPhone->Enabled = false;
			this->txtBoxPhone->Location = System::Drawing::Point(75, 400);
			this->txtBoxPhone->Name = L"txtBoxPhone";
			this->txtBoxPhone->Size = System::Drawing::Size(121, 25);
			this->txtBoxPhone->TabIndex = 1;
			// 
			// txtBoxEmail
			// 
			this->txtBoxEmail->Enabled = false;
			this->txtBoxEmail->Location = System::Drawing::Point(322, 400);
			this->txtBoxEmail->Name = L"txtBoxEmail";
			this->txtBoxEmail->Size = System::Drawing::Size(121, 25);
			this->txtBoxEmail->TabIndex = 1;
			// 
			// combBoxCha
			// 
			this->combBoxCha->FormattingEnabled = true;
			this->combBoxCha->Location = System::Drawing::Point(75, 507);
			this->combBoxCha->Name = L"combBoxCha";
			this->combBoxCha->Size = System::Drawing::Size(121, 23);
			this->combBoxCha->TabIndex = 2;
			// 
			// btnPWchk
			// 
			this->btnPWchk->Location = System::Drawing::Point(75, 143);
			this->btnPWchk->Name = L"btnPWchk";
			this->btnPWchk->Size = System::Drawing::Size(121, 32);
			this->btnPWchk->TabIndex = 3;
			this->btnPWchk->Text = L"check";
			this->btnPWchk->UseVisualStyleBackColor = true;
			// 
			// btnNickNameduplicateChk
			// 
			this->btnNickNameduplicateChk->Location = System::Drawing::Point(320, 307);
			this->btnNickNameduplicateChk->Name = L"btnNickNameduplicateChk";
			this->btnNickNameduplicateChk->Size = System::Drawing::Size(121, 32);
			this->btnNickNameduplicateChk->TabIndex = 3;
			this->btnNickNameduplicateChk->Text = L"check";
			this->btnNickNameduplicateChk->UseVisualStyleBackColor = true;
			// 
			// EditProfile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(595, 631);
			this->Controls->Add(this->btnNickNameduplicateChk);
			this->Controls->Add(this->btnPWchk);
			this->Controls->Add(this->combBoxCha);
			this->Controls->Add(this->txtBoxPW_Confirm);
			this->Controls->Add(this->txtBoxEmail);
			this->Controls->Add(this->txtBoxPhone);
			this->Controls->Add(this->txtBoxNickName);
			this->Controls->Add(this->txtBoxPW_new);
			this->Controls->Add(this->txtBoxPW);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"EditProfile";
			this->Text = L"EditProfile";
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion


		public: void SendMessageForm(int index)
		{

			switch (index)
			{
			case e_edit_PWchk:
			{
				String^ tmptxt_1 = txtBoxPW->Text; // textBox는 해당 텍스트 상자의 이름입니다.
				// String^ tmptxt_2 = txtBoxRechk->Text; // textBox는 해당 텍스트 상자의 이름입니다.


				if (String::IsNullOrEmpty(tmptxt_1)) {
					System::Windows::Forms::MessageBox::Show("Please input Password.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}

				String^ buffer = _my->s_(e_edit_PWchk) + " " + tmptxt_1;
				_my->SendMessage(buffer);

				break;
			}

			case e_edit_NickNamechk:
			{
				String^ tmptxt_1 = txtBoxNickName->Text;


				if (String::IsNullOrEmpty(tmptxt_1))
				{
					System::Windows::Forms::MessageBox::Show("닉네임을 입력해주세요", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}

				String^ buffer = _my->s_(e_edit_NickNamechk) + " " + tmptxt_1;
				_my->SendMessage(buffer);

				break;
			}

			case e_edit_Confirm:
			{
				if (!isChkNickName)
				{
					System::Windows::Forms::MessageBox::Show("Please ID duplicate check", "warming", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					break;
				}


				String^ tmptxt_1 = txtBoxEmail->Text;
				String^ tmptxt_2 = txtBoxPhone->Text;
				String^ tmptxt_3 = txtBoxNickName->Text;
				String^ tmptxt_4 = combBoxCha->Text;
				String^ tmptxt_5 = txtBoxPW_new->Text;
				String^ tmptxt_6 = txtBoxPW_Confirm->Text;
			

				if (tmptxt_5 != tmptxt_6)
				{
					System::Windows::Forms::MessageBox::Show("please check the password.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
					

				// ID와 PW의 문자열이 채워져있다면
				if (!String::IsNullOrEmpty(tmptxt_1) && !String::IsNullOrEmpty(tmptxt_2) && !String::IsNullOrEmpty(tmptxt_2)\
					&& !String::IsNullOrEmpty(tmptxt_3) && !String::IsNullOrEmpty(tmptxt_4) && !String::IsNullOrEmpty(tmptxt_5))
				{
					if (1) // 나중에 캐릭터 추가하자
					{
						tmptxt_4 = _my->s_(e_character_izuna);
					}
					int t_index = e_signup_NickNamechk;
					String^ buffer = _my->s_(t_index) + " " + tmptxt_1 + " " + tmptxt_2 + " " + tmptxt_3 + " " + tmptxt_4;
					_my->SendMessage(buffer);
				}
				// 입력값이 없다면,
				else {
					System::Windows::Forms::MessageBox::Show("please fill the blank.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}

			}
		}



		private: System::Void UpdateTextBox()
		{
			txtBoxPW->Enabled = false;
			txtBoxEmail->Enabled = true;
			txtBoxPhone->Enabled = true;
			txtBoxPW_new->Enabled = true;
			txtBoxNickName->Enabled = true;
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
				case e_edit_PWchk:
				{
					if (isTrue == "true")
					{
						Invoke(gcnew Action(this, &EditProfile::UpdateTextBox));
						System::Windows::Forms::MessageBox::Show("Password matches username.", "PW check", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else
					{
						System::Windows::Forms::MessageBox::Show("Password Wrong", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
					break;
				}
				case e_edit_NickNamechk:
				{
					if (isTrue == "true")
					{
						Invoke(gcnew Action(this, &EditProfile::UpdateTextBoxNickname));
						System::Windows::Forms::MessageBox::Show("You can use this Nickname", "nickname check", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else
					{
						System::Windows::Forms::MessageBox::Show("The nickname already exists.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
					break;
				}
				case e_edit_Confirm:
				{
					if (isTrue == "true")
					{
						System::Windows::Forms::MessageBox::Show("Update Profile Success", "Edit Porofile", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else
					{
						System::Windows::Forms::MessageBox::Show("something wrong..", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
					break;
				}

			}

		}

		private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
		private: System::Void btnEditConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
			SendMessageForm(e_edit_Confirm);
		}
		private: System::Void btnPWchk_Click(System::Object^ sender, System::EventArgs^ e) {
			SendMessageForm(e_edit_PWchk);
		}
		private: System::Void btnNickNameduplicateChk_Click(System::Object^ sender, System::EventArgs^ e) {
			SendMessageForm(e_edit_NickNamechk);
		}
		private: System::Void EditProfile_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			this->Owner->Show();
			this->Owner->Activate();
		}

	};

}
