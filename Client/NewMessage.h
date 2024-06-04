#pragma once
#include "enum.h"
#include "MyFunction.h"
#include "FriendsList.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// NewMessage에 대한 요약입니다.
	/// </summary>
	public ref class NewMessage : public System::Windows::Forms::Form
	{
	public:
		NewMessage(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

		NewMessage(MyFunction^ my)
		{
			InitializeComponent();
			this->_my = my;
			this->_my->MyEvent += gcnew Action<String^>(this, &NewMessage::ReceivedMsg);

		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~NewMessage()
		{

			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &NewMessage::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::TextBox^ txtBoxMsg;
	public: System::Windows::Forms::TextBox^ txtBoxNickname;
	private:
	private: System::Windows::Forms::Button^ btnFriends;
	public:
	private: System::Windows::Forms::Button^ btnSend;
	private: System::Windows::Forms::Button^ btnClose;
	private: FriendsList^ friendsList = nullptr;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NewMessage::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtBoxMsg = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxNickname = (gcnew System::Windows::Forms::TextBox());
			this->btnFriends = (gcnew System::Windows::Forms::Button());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label2->ForeColor = System::Drawing::Color::Cornsilk;
			this->label2->Location = System::Drawing::Point(24, 61);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 26);
			this->label2->TabIndex = 19;
			this->label2->Text = L"To.";
			// 
			// txtBoxMsg
			// 
			this->txtBoxMsg->Location = System::Drawing::Point(29, 102);
			this->txtBoxMsg->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxMsg->Multiline = true;
			this->txtBoxMsg->Name = L"txtBoxMsg";
			this->txtBoxMsg->Size = System::Drawing::Size(210, 252);
			this->txtBoxMsg->TabIndex = 2;
			// 
			// txtBoxNickname
			// 
			this->txtBoxNickname->Location = System::Drawing::Point(76, 66);
			this->txtBoxNickname->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxNickname->Name = L"txtBoxNickname";
			this->txtBoxNickname->Size = System::Drawing::Size(163, 21);
			this->txtBoxNickname->TabIndex = 1;
			// 
			// btnFriends
			// 
			this->btnFriends->BackColor = System::Drawing::Color::Transparent;
			this->btnFriends->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnFriends.BackgroundImage")));
			this->btnFriends->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnFriends->FlatAppearance->BorderSize = 0;
			this->btnFriends->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			this->btnFriends->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnFriends->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnFriends->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFriends->Location = System::Drawing::Point(259, 49);
			this->btnFriends->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnFriends->Name = L"btnFriends";
			this->btnFriends->Size = System::Drawing::Size(146, 56);
			this->btnFriends->TabIndex = 20;
			this->btnFriends->UseVisualStyleBackColor = false;
			this->btnFriends->Click += gcnew System::EventHandler(this, &NewMessage::btnFriends_Click);
			// 
			// btnSend
			// 
			this->btnSend->BackColor = System::Drawing::Color::Transparent;
			this->btnSend->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSend.BackgroundImage")));
			this->btnSend->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSend->FlatAppearance->BorderSize = 0;
			this->btnSend->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			this->btnSend->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSend->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSend->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSend->Location = System::Drawing::Point(109, 361);
			this->btnSend->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(146, 56);
			this->btnSend->TabIndex = 20;
			this->btnSend->UseVisualStyleBackColor = false;
			this->btnSend->Click += gcnew System::EventHandler(this, &NewMessage::btnSend_Click);
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::Transparent;
			this->btnClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClose.BackgroundImage")));
			this->btnClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			this->btnClose->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Location = System::Drawing::Point(259, 361);
			this->btnClose->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(146, 56);
			this->btnClose->TabIndex = 20;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &NewMessage::btnClose_Click);
			// 
			// NewMessage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(464, 455);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->btnFriends);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtBoxMsg);
			this->Controls->Add(this->txtBoxNickname);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"NewMessage";
			this->Text = L"NewMessage";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: void SendMessageForm(int index)
		{

			switch (index)
			{
				case e_message_Send:
				{
					String^ tmptxt_1 = txtBoxNickname->Text;
					String^ tmptxt_2 = txtBoxMsg->Text;

					if (!String::IsNullOrEmpty(tmptxt_1))
					{
						int t_index = e_message_Send;
						String^ buffer = t_index.ToString() + " " + tmptxt_1 + " " + tmptxt_2;
						_my->SendMessage(buffer);
					}
					else
					{
						MessageBox::Show("Input friends id", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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
				case e_message_Send:
				{
					if (isTrue == "true")
					{
						System::Windows::Forms::MessageBox::Show("Message sent", "notice", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else
					{
						System::Windows::Forms::MessageBox::Show("Please Check the ID", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
					break;
				}
			}

		}
		private: void FillFriendID(String^ message)
		{
			txtBoxNickname->Text = message;
		}



		private: System::Void btnFriends_Click(System::Object^ sender, System::EventArgs^ e) {
			if (friendsList == nullptr || friendsList->IsDisposed) {
				friendsList = gcnew FriendsList(_my);
				friendsList->Show();
				friendsList->MyEvent_ += gcnew Action<String^>(this, &NewMessage::FillFriendID);
			}
			// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
			else {
				friendsList->Activate();
			}
		}
		private: System::Void btnSend_Click(System::Object^ sender, System::EventArgs^ e) {
			btnSend->NotifyDefault(false);
			SendMessageForm(e_message_Send);
		}
		private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
};
}
