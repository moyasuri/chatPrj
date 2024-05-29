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
	private: System::Windows::Forms::Button^ btnEditConfirm;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::PictureBox^ pictureBox8;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EditProfile::typeid));
			this->txtBoxPW = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxPW_new = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxPW_Confirm = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxNickName = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxPhone = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxEmail = (gcnew System::Windows::Forms::TextBox());
			this->combBoxCha = (gcnew System::Windows::Forms::ComboBox());
			this->btnPWchk = (gcnew System::Windows::Forms::Button());
			this->btnNickNameduplicateChk = (gcnew System::Windows::Forms::Button());
			this->btnEditConfirm = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			this->SuspendLayout();
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->Location = System::Drawing::Point(144, 75);
			this->txtBoxPW->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->Size = System::Drawing::Size(168, 21);
			this->txtBoxPW->TabIndex = 1;
			// 
			// txtBoxPW_new
			// 
			this->txtBoxPW_new->Enabled = false;
			this->txtBoxPW_new->Location = System::Drawing::Point(144, 172);
			this->txtBoxPW_new->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxPW_new->Name = L"txtBoxPW_new";
			this->txtBoxPW_new->Size = System::Drawing::Size(168, 21);
			this->txtBoxPW_new->TabIndex = 1;
			// 
			// txtBoxPW_Confirm
			// 
			this->txtBoxPW_Confirm->Enabled = false;
			this->txtBoxPW_Confirm->Location = System::Drawing::Point(342, 172);
			this->txtBoxPW_Confirm->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxPW_Confirm->Name = L"txtBoxPW_Confirm";
			this->txtBoxPW_Confirm->Size = System::Drawing::Size(168, 21);
			this->txtBoxPW_Confirm->TabIndex = 1;
			// 
			// txtBoxNickName
			// 
			this->txtBoxNickName->Enabled = false;
			this->txtBoxNickName->Location = System::Drawing::Point(144, 251);
			this->txtBoxNickName->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxNickName->Name = L"txtBoxNickName";
			this->txtBoxNickName->Size = System::Drawing::Size(168, 21);
			this->txtBoxNickName->TabIndex = 1;
			// 
			// txtBoxPhone
			// 
			this->txtBoxPhone->Enabled = false;
			this->txtBoxPhone->Location = System::Drawing::Point(144, 320);
			this->txtBoxPhone->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxPhone->Name = L"txtBoxPhone";
			this->txtBoxPhone->Size = System::Drawing::Size(168, 21);
			this->txtBoxPhone->TabIndex = 1;
			// 
			// txtBoxEmail
			// 
			this->txtBoxEmail->Enabled = false;
			this->txtBoxEmail->Location = System::Drawing::Point(339, 320);
			this->txtBoxEmail->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxEmail->Name = L"txtBoxEmail";
			this->txtBoxEmail->Size = System::Drawing::Size(168, 21);
			this->txtBoxEmail->TabIndex = 1;
			// 
			// combBoxCha
			// 
			this->combBoxCha->FormattingEnabled = true;
			this->combBoxCha->Location = System::Drawing::Point(142, 401);
			this->combBoxCha->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->combBoxCha->Name = L"combBoxCha";
			this->combBoxCha->Size = System::Drawing::Size(106, 20);
			this->combBoxCha->TabIndex = 2;
			// 
			// btnPWchk
			// 
			this->btnPWchk->Location = System::Drawing::Point(348, 75);
			this->btnPWchk->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnPWchk->Name = L"btnPWchk";
			this->btnPWchk->Size = System::Drawing::Size(106, 26);
			this->btnPWchk->TabIndex = 3;
			this->btnPWchk->Text = L"check";
			this->btnPWchk->UseVisualStyleBackColor = true;
			this->btnPWchk->Click += gcnew System::EventHandler(this, &EditProfile::btnPWchk_Click);
			// 
			// btnNickNameduplicateChk
			// 
			this->btnNickNameduplicateChk->Location = System::Drawing::Point(348, 246);
			this->btnNickNameduplicateChk->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnNickNameduplicateChk->Name = L"btnNickNameduplicateChk";
			this->btnNickNameduplicateChk->Size = System::Drawing::Size(106, 26);
			this->btnNickNameduplicateChk->TabIndex = 3;
			this->btnNickNameduplicateChk->Text = L"check";
			this->btnNickNameduplicateChk->UseVisualStyleBackColor = true;
			this->btnNickNameduplicateChk->Click += gcnew System::EventHandler(this, &EditProfile::btnNickNameduplicateChk_Click);
			// 
			// btnEditConfirm
			// 
			this->btnEditConfirm->BackColor = System::Drawing::Color::Transparent;
			this->btnEditConfirm->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnEditConfirm.BackgroundImage")));
			this->btnEditConfirm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnEditConfirm->FlatAppearance->BorderSize = 0;
			this->btnEditConfirm->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnEditConfirm->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnEditConfirm->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEditConfirm->Location = System::Drawing::Point(142, 464);
			this->btnEditConfirm->Name = L"btnEditConfirm";
			this->btnEditConfirm->Size = System::Drawing::Size(153, 54);
			this->btnEditConfirm->TabIndex = 4;
			this->btnEditConfirm->UseVisualStyleBackColor = false;
			this->btnEditConfirm->Click += gcnew System::EventHandler(this, &EditProfile::btnEditConfirm_Click);
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::Transparent;
			this->btnClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClose.BackgroundImage")));
			this->btnClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Location = System::Drawing::Point(301, 464);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(153, 54);
			this->btnClose->TabIndex = 4;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &EditProfile::btnClose_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Location = System::Drawing::Point(136, 44);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(178, 27);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox2->Location = System::Drawing::Point(122, 132);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(178, 27);
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox4->Location = System::Drawing::Point(339, 132);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(178, 27);
			this->pictureBox4->TabIndex = 7;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.BackgroundImage")));
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox5->Location = System::Drawing::Point(102, 218);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(178, 27);
			this->pictureBox5->TabIndex = 8;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.BackgroundImage")));
			this->pictureBox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox6->Location = System::Drawing::Point(86, 291);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(178, 27);
			this->pictureBox6->TabIndex = 9;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox7->Location = System::Drawing::Point(283, 291);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(178, 27);
			this->pictureBox7->TabIndex = 10;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.BackgroundImage")));
			this->pictureBox8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox8->Location = System::Drawing::Point(128, 364);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(115, 27);
			this->pictureBox8->TabIndex = 11;
			this->pictureBox8->TabStop = false;
			// 
			// EditProfile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(593, 564);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnEditConfirm);
			this->Controls->Add(this->btnNickNameduplicateChk);
			this->Controls->Add(this->btnPWchk);
			this->Controls->Add(this->combBoxCha);
			this->Controls->Add(this->txtBoxPW_Confirm);
			this->Controls->Add(this->txtBoxEmail);
			this->Controls->Add(this->txtBoxPhone);
			this->Controls->Add(this->txtBoxNickName);
			this->Controls->Add(this->txtBoxPW_new);
			this->Controls->Add(this->txtBoxPW);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"EditProfile";
			this->Text = L"EditProfile";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &EditProfile::EditProfile_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
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
			txtBoxPW_Confirm->Enabled = true;
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



		private: System::Void btnEditConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
			SendMessageForm(e_edit_Confirm);
		}
		private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
		private: System::Void EditProfile_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			this->Owner->Show();
			this->Owner->Activate();
		}

		private: System::Void btnPWchk_Click(System::Object^ sender, System::EventArgs^ e) {
			SendMessageForm(e_edit_PWchk);
		}

		private: System::Void btnNickNameduplicateChk_Click(System::Object^ sender, System::EventArgs^ e) {
			SendMessageForm(e_edit_NickNamechk);
		}

};

}
