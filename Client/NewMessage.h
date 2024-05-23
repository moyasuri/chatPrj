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
			this->label2->Location = System::Drawing::Point(28, 76);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 26);
			this->label2->TabIndex = 19;
			this->label2->Text = L"To.";
			// 
			// txtBoxMsg
			// 
			this->txtBoxMsg->Location = System::Drawing::Point(87, 142);
			this->txtBoxMsg->Multiline = true;
			this->txtBoxMsg->Name = L"txtBoxMsg";
			this->txtBoxMsg->Size = System::Drawing::Size(303, 314);
			this->txtBoxMsg->TabIndex = 18;
			// 
			// txtBoxNickname
			// 
			this->txtBoxNickname->Location = System::Drawing::Point(87, 83);
			this->txtBoxNickname->Name = L"txtBoxNickname";
			this->txtBoxNickname->Size = System::Drawing::Size(186, 25);
			this->txtBoxNickname->TabIndex = 17;
			// 
			// btnFriends
			// 
			this->btnFriends->Location = System::Drawing::Point(348, 83);
			this->btnFriends->Name = L"btnFriends";
			this->btnFriends->Size = System::Drawing::Size(89, 35);
			this->btnFriends->TabIndex = 20;
			this->btnFriends->Text = L"friends";
			this->btnFriends->UseVisualStyleBackColor = true;
			// 
			// btnSend
			// 
			this->btnSend->Location = System::Drawing::Point(102, 502);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(89, 35);
			this->btnSend->TabIndex = 20;
			this->btnSend->Text = L"send";
			this->btnSend->UseVisualStyleBackColor = true;
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(316, 502);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(89, 35);
			this->btnClose->TabIndex = 20;
			this->btnClose->Text = L"close";
			this->btnClose->UseVisualStyleBackColor = true;
			// 
			// NewMessage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(530, 569);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->btnFriends);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtBoxMsg);
			this->Controls->Add(this->txtBoxNickname);
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
		private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
		private: System::Void btnSend_Click(System::Object^ sender, System::EventArgs^ e) {
			btnSend->NotifyDefault(false);
			SendMessageForm(e_message_Send);

		}
	};
}
