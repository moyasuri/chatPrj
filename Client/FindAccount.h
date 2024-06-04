#pragma once
#include "MyFunction.h";
#include "enum.h"


namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// FindAccount에 대한 요약입니다.
	/// </summary>
	public ref class FindAccount : public System::Windows::Forms::Form
	{
	public:
		FindAccount(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
		FindAccount(MyFunction^ my)
		{
			InitializeComponent();
			this->_my = my;
			this->_my->MyEvent += gcnew Action<String^>(this, &FindAccount::ReceivedMsg);


			String^ currentDirectory = System::Environment::CurrentDirectory;


			String^ relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\Button\\submit.png");
			btnSubmit_ID->BackgroundImage = Image::FromFile(relativePath);
			btnSubmit_PW->BackgroundImage = Image::FromFile(relativePath);

			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\Button\\close.png");
			btnCancle->BackgroundImage = Image::FromFile(relativePath);


			// 필요에 따라 버튼의 크기 모드를 설정합니다.
			btnSubmit_ID->BackgroundImageLayout = ImageLayout::Zoom;
			btnSubmit_PW->BackgroundImageLayout = ImageLayout::Zoom;
			btnCancle->BackgroundImageLayout = ImageLayout::Zoom;



		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~FindAccount()
		{
			if (components)
			{
				delete components;
			}
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &FindAccount::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}
		}
	
	protected:
	private: System::Windows::Forms::Button^ btnCancle;
	private: System::Windows::Forms::Button^ btnSubmit_ID;
	private: System::Windows::Forms::Button^ btnSubmit_PW;
	


	

	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::Label^ label9;



	private: System::Windows::Forms::TextBox^ txtBoxName;
	private: System::Windows::Forms::TextBox^ txtBoxEmail;

	private: MyFunction^ _my;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtBoxBirth;
	private: System::Windows::Forms::TextBox^ txtBoxID;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtBoxPhone;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FindAccount::typeid));
			this->btnCancle = (gcnew System::Windows::Forms::Button());
			this->btnSubmit_PW = (gcnew System::Windows::Forms::Button());
			this->btnSubmit_ID = (gcnew System::Windows::Forms::Button());
			this->txtBoxName = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxEmail = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtBoxBirth = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxID = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtBoxPhone = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnCancle
			// 
			this->btnCancle->BackColor = System::Drawing::Color::Transparent;
			this->btnCancle->FlatAppearance->BorderSize = 0;
			this->btnCancle->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnCancle->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnCancle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->btnCancle->ForeColor = System::Drawing::Color::Firebrick;
			this->btnCancle->Location = System::Drawing::Point(247, 478);
			this->btnCancle->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCancle->Name = L"btnCancle";
			this->btnCancle->Size = System::Drawing::Size(160, 59);
			this->btnCancle->TabIndex = 48;
			this->btnCancle->UseVisualStyleBackColor = false;
			this->btnCancle->Click += gcnew System::EventHandler(this, &FindAccount::btnCancle_Click);
			// 
			// btnSubmit_PW
			// 
			this->btnSubmit_PW->BackColor = System::Drawing::Color::Transparent;
			this->btnSubmit_PW->FlatAppearance->BorderSize = 0;
			this->btnSubmit_PW->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSubmit_PW->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSubmit_PW->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSubmit_PW->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->btnSubmit_PW->Location = System::Drawing::Point(102, 478);
			this->btnSubmit_PW->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSubmit_PW->Name = L"btnSubmit_PW";
			this->btnSubmit_PW->Size = System::Drawing::Size(160, 59);
			this->btnSubmit_PW->TabIndex = 47;
			this->btnSubmit_PW->UseVisualStyleBackColor = false;
			this->btnSubmit_PW->Click += gcnew System::EventHandler(this, &FindAccount::btnSubmit_PW_Click);
			// 
			// btnSubmit_ID
			// 
			this->btnSubmit_ID->BackColor = System::Drawing::Color::Transparent;
			this->btnSubmit_ID->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnSubmit_ID->FlatAppearance->BorderSize = 0;
			this->btnSubmit_ID->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSubmit_ID->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSubmit_ID->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSubmit_ID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->btnSubmit_ID->Location = System::Drawing::Point(247, 144);
			this->btnSubmit_ID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSubmit_ID->Name = L"btnSubmit_ID";
			this->btnSubmit_ID->Size = System::Drawing::Size(160, 59);
			this->btnSubmit_ID->TabIndex = 46;
			this->btnSubmit_ID->UseVisualStyleBackColor = false;
			this->btnSubmit_ID->Click += gcnew System::EventHandler(this, &FindAccount::btnSubmit_ID_Click);
			// 
			// txtBoxName
			// 
			this->txtBoxName->BackColor = System::Drawing::Color::GhostWhite;
			this->txtBoxName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtBoxName->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxName->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxName->Location = System::Drawing::Point(115, 67);
			this->txtBoxName->Name = L"txtBoxName";
			this->txtBoxName->Size = System::Drawing::Size(272, 29);
			this->txtBoxName->TabIndex = 1;
			// 
			// txtBoxEmail
			// 
			this->txtBoxEmail->BackColor = System::Drawing::Color::GhostWhite;
			this->txtBoxEmail->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtBoxEmail->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxEmail->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxEmail->Location = System::Drawing::Point(115, 116);
			this->txtBoxEmail->Name = L"txtBoxEmail";
			this->txtBoxEmail->Size = System::Drawing::Size(272, 29);
			this->txtBoxEmail->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(18, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 18);
			this->label2->TabIndex = 24;
			this->label2->Text = L"Name";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label9->Location = System::Drawing::Point(16, 120);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(55, 18);
			this->label9->TabIndex = 24;
			this->label9->Text = L"E-mail";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Location = System::Drawing::Point(30, 401);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 18);
			this->label5->TabIndex = 24;
			this->label5->Text = L"Birth";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(30, 352);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 18);
			this->label1->TabIndex = 24;
			this->label1->Text = L"ID";
			// 
			// txtBoxBirth
			// 
			this->txtBoxBirth->BackColor = System::Drawing::Color::GhostWhite;
			this->txtBoxBirth->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtBoxBirth->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxBirth->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxBirth->Location = System::Drawing::Point(115, 398);
			this->txtBoxBirth->Name = L"txtBoxBirth";
			this->txtBoxBirth->Size = System::Drawing::Size(272, 29);
			this->txtBoxBirth->TabIndex = 26;
			// 
			// txtBoxID
			// 
			this->txtBoxID->BackColor = System::Drawing::Color::GhostWhite;
			this->txtBoxID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtBoxID->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxID->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxID->Location = System::Drawing::Point(115, 352);
			this->txtBoxID->Name = L"txtBoxID";
			this->txtBoxID->Size = System::Drawing::Size(272, 29);
			this->txtBoxID->TabIndex = 27;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label6->Location = System::Drawing::Point(30, 450);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(52, 18);
			this->label6->TabIndex = 31;
			this->label6->Text = L"Phone";
			// 
			// txtBoxPhone
			// 
			this->txtBoxPhone->BackColor = System::Drawing::Color::GhostWhite;
			this->txtBoxPhone->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtBoxPhone->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxPhone->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPhone->Location = System::Drawing::Point(115, 444);
			this->txtBoxPhone->Name = L"txtBoxPhone";
			this->txtBoxPhone->Size = System::Drawing::Size(272, 29);
			this->txtBoxPhone->TabIndex = 32;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(327, 322);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 18);
			this->label3->TabIndex = 49;
			this->label3->Text = L"Find PW";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(327, 37);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 18);
			this->label4->TabIndex = 49;
			this->label4->Text = L"Find Id";
			// 
			// FindAccount
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(419, 538);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtBoxName);
			this->Controls->Add(this->txtBoxEmail);
			this->Controls->Add(this->txtBoxPhone);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->btnCancle);
			this->Controls->Add(this->txtBoxID);
			this->Controls->Add(this->btnSubmit_PW);
			this->Controls->Add(this->txtBoxBirth);
			this->Controls->Add(this->btnSubmit_ID);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label5);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"FindAccount";
			this->Text = L"FindAccount";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: void SendMessageForm(int index)
		{

			switch (index)
			{
			case e_id_find_ID:
			{
				String^ tmptxt_1 = txtBoxName->Text; // textBox는 해당 텍스트 상자의 이름입니다.
				String^ tmptxt_2 = txtBoxEmail->Text; // textBox는 해당 텍스트 상자의 이름입니다.

				if (!String::IsNullOrEmpty(tmptxt_1) && !String::IsNullOrEmpty(tmptxt_2))
				{
					int t_index = e_id_find_ID;
					String^ buffer = t_index.ToString() + " " + tmptxt_1 + " " + tmptxt_2;
					_my->SendMessage(buffer);
				}
				else
				{
					MessageBox::Show("input ID / PW", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}

				break;
			}

			case e_id_find_PW:
			{
				String^ tmptxt_1 = txtBoxID->Text;
				String^ tmptxt_2 = txtBoxBirth->Text;
				String^ tmptxt_3 = txtBoxPhone->Text;


				if (!String::IsNullOrEmpty(tmptxt_1) && !String::IsNullOrEmpty(tmptxt_2))
				{
					int t_index = e_id_find_PW;
					String^ buffer = t_index.ToString() + " " + tmptxt_1 + " " + tmptxt_2 + " " + tmptxt_3;
					_my->SendMessage(buffer);
				}
				else
				{
					MessageBox::Show("please input blanck.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}

				break;
			}

			}

		}

		public: void ReceivedMsg(String^ message)
		{
			String^ inputString = message;


			array<String^>^ subString = inputString->Split(' ');


			String^ index_s = subString[0];
			String^ isTrue = subString[1];
			int index = Int32::Parse(index_s);


			switch (index)
			{
				case e_id_find_ID:
				{
					if (isTrue == "true")
					{
						String^ msg = "ID : " + subString[2];

						System::Windows::Forms::MessageBox::Show(msg, ("find id"), MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else
					{
						System::Windows::Forms::MessageBox::Show("Wrong information", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
					break;
				}
				case e_id_find_PW:
				{
					if (isTrue == "true")
					{
						String^ msg = "PW : " + subString[2];
						System::Windows::Forms::MessageBox::Show(msg, "find pw", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else
					{
						System::Windows::Forms::MessageBox::Show("wrong information.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
					break;
				}

			}

		}






		
		private: System::Void btnSubmit_ID_Click(System::Object^ sender, System::EventArgs^ e) {
			btnSubmit_ID->NotifyDefault(false);
			SendMessageForm(e_id_find_ID);
		}
		private: System::Void btnCancle_Click(System::Object^ sender, System::EventArgs^ e) {
			this->_my->disposed();
			this->Close();
		}
		private: System::Void btnSubmit_PW_Click(System::Object^ sender, System::EventArgs^ e) {
			btnSubmit_PW->NotifyDefault(false);
			SendMessageForm(e_id_find_PW);

		}
};
}
