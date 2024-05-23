﻿#pragma once
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
	/// ChatRoom에 대한 요약입니다.
	/// </summary>
	public ref class ChatRoom : public System::Windows::Forms::Form
	{
	public:
		ChatRoom(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

		ChatRoom(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &ChatRoom::ReceivedMsg);

			int t_index = e_room_show_whole_Text;
			String^ buffer = _my->s_(t_index);
			_my->SendMessage(buffer);
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~ChatRoom()
		{
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &ChatRoom::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ picBoxImojiMy;
	protected:
	private: System::Windows::Forms::PictureBox^ picBoxImojiYou;
	private: System::Windows::Forms::TextBox^ txtBoxId;
	private: System::Windows::Forms::TextBox^ txtBoxMessage;
	private: System::Windows::Forms::TextBox^ txtBoxMyChat;
	private: System::Windows::Forms::TextBox^ txtBoxDate;
	private: System::Windows::Forms::DataGridView^ ViewDataChat;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Message;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Time;
	private: System::Windows::Forms::Button^ btnSend;
	private: System::Windows::Forms::Button^ btnClose;
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
			this->picBoxImojiMy = (gcnew System::Windows::Forms::PictureBox());
			this->picBoxImojiYou = (gcnew System::Windows::Forms::PictureBox());
			this->txtBoxId = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxMessage = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxMyChat = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxDate = (gcnew System::Windows::Forms::TextBox());
			this->ViewDataChat = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Message = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiMy))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiYou))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewDataChat))->BeginInit();
			this->SuspendLayout();
			// 
			// picBoxImojiMy
			// 
			this->picBoxImojiMy->Location = System::Drawing::Point(24, 150);
			this->picBoxImojiMy->Name = L"picBoxImojiMy";
			this->picBoxImojiMy->Size = System::Drawing::Size(87, 91);
			this->picBoxImojiMy->TabIndex = 0;
			this->picBoxImojiMy->TabStop = false;
			// 
			// picBoxImojiYou
			// 
			this->picBoxImojiYou->Location = System::Drawing::Point(24, 274);
			this->picBoxImojiYou->Name = L"picBoxImojiYou";
			this->picBoxImojiYou->Size = System::Drawing::Size(87, 91);
			this->picBoxImojiYou->TabIndex = 0;
			this->picBoxImojiYou->TabStop = false;
			// 
			// txtBoxId
			// 
			this->txtBoxId->Location = System::Drawing::Point(159, 51);
			this->txtBoxId->Multiline = true;
			this->txtBoxId->Name = L"txtBoxId";
			this->txtBoxId->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtBoxId->Size = System::Drawing::Size(134, 189);
			this->txtBoxId->TabIndex = 1;
			// 
			// txtBoxMessage
			// 
			this->txtBoxMessage->Location = System::Drawing::Point(338, 57);
			this->txtBoxMessage->Multiline = true;
			this->txtBoxMessage->Name = L"txtBoxMessage";
			this->txtBoxMessage->Size = System::Drawing::Size(154, 182);
			this->txtBoxMessage->TabIndex = 2;
			// 
			// txtBoxMyChat
			// 
			this->txtBoxMyChat->Location = System::Drawing::Point(338, 274);
			this->txtBoxMyChat->Name = L"txtBoxMyChat";
			this->txtBoxMyChat->Size = System::Drawing::Size(154, 25);
			this->txtBoxMyChat->TabIndex = 2;
			// 
			// txtBoxDate
			// 
			this->txtBoxDate->Location = System::Drawing::Point(526, 59);
			this->txtBoxDate->Multiline = true;
			this->txtBoxDate->Name = L"txtBoxDate";
			this->txtBoxDate->Size = System::Drawing::Size(154, 182);
			this->txtBoxDate->TabIndex = 2;
			// 
			// ViewDataChat
			// 
			this->ViewDataChat->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ViewDataChat->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->ID, this->Message,
					this->Time
			});
			this->ViewDataChat->Location = System::Drawing::Point(526, 247);
			this->ViewDataChat->Name = L"ViewDataChat";
			this->ViewDataChat->RowTemplate->Height = 27;
			this->ViewDataChat->Size = System::Drawing::Size(431, 183);
			this->ViewDataChat->TabIndex = 3;
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			// 
			// Message
			// 
			this->Message->HeaderText = L"Message";
			this->Message->Name = L"Message";
			// 
			// Time
			// 
			this->Time->HeaderText = L"Time";
			this->Time->Name = L"Time";
			// 
			// btnSend
			// 
			this->btnSend->Location = System::Drawing::Point(159, 432);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(119, 42);
			this->btnSend->TabIndex = 4;
			this->btnSend->Text = L"btnSend";
			this->btnSend->UseVisualStyleBackColor = true;
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(373, 432);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(119, 42);
			this->btnClose->TabIndex = 4;
			this->btnClose->Text = L"btnClose";
			this->btnClose->UseVisualStyleBackColor = true;
			// 
			// ChatRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(969, 518);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->ViewDataChat);
			this->Controls->Add(this->txtBoxMyChat);
			this->Controls->Add(this->txtBoxDate);
			this->Controls->Add(this->txtBoxMessage);
			this->Controls->Add(this->txtBoxId);
			this->Controls->Add(this->picBoxImojiYou);
			this->Controls->Add(this->picBoxImojiMy);
			this->Name = L"ChatRoom";
			this->Text = L"ChatRoom";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiMy))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiYou))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewDataChat))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: void ReceivedMsg(String^ message)
		{
			String^ inputString = message;

			array<String^>^ subString = inputString->Split(' ');

			String^ index_s = subString[0];
			String^ isTrue = subString[1];
			int index = Int32::Parse(index_s);

			switch (index)
			{
			case e_room_Chat:
			{
				if (isTrue == "true")
				{
					this->Invoke(gcnew Action<String^>(this, &ChatRoom::UpdateMessage), message);
				}
				else
				{
					System::Windows::Forms::MessageBox::Show("Password Wrong", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				break;
			}
			case e_room_show_whole_Text:
			{
				if (isTrue == "true")
				{
					this->Invoke(gcnew Action<String^>(this, &ChatRoom::PreviousMsgShow), message);
				}
				else if (isTrue == "else")
				{
					this->Invoke(gcnew Action(this, &ChatRoom::PreviousMsgEndline));
				}
				break;
			}
			//case e_edit_Confirm:
			//{
			//	if (isTrue == "true")
			//	{
			//		System::Windows::Forms::MessageBox::Show("Update Profile Success", "Edit Porofile", MessageBoxButtons::OK, MessageBoxIcon::Information);
			//	}
			//	else
			//	{
			//		System::Windows::Forms::MessageBox::Show("something wrong..", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			//	}
			//	break;
			//}
			}



		}

		public: void PreviousMsgEndline()
		{
			txtBoxId->Text += Environment::NewLine;
			txtBoxMessage->Text += "-----------------previous--------------" + Environment::NewLine;
			txtBoxDate->Text += Environment::NewLine;
		}
		public: void PreviousMsgShow(String^ message)
		{
			String^ e_length = _my->s_(e_room_show_whole_Text);
			String^ msg = message->Substring(e_length->Length + 6);

			//// 아이디 추출
			int idEndIndex = msg->IndexOf(' '); // 공백 이전까지가 아이디
			String^ id = msg->Substring(0, idEndIndex)->Trim();

			// 메시지 추출
			String^ messagePart = msg->Substring(idEndIndex)->Trim();

			//// 날짜 추출
			int lastSpaceIndex = messagePart->LastIndexOf(' '); // 뒤에서부터 첫 번째 공백의 위치
			int dateEndIndex = messagePart->LastIndexOf(' ', lastSpaceIndex - 1); // 뒤에서부터 두 번째 공백의 위치
			String^ date = messagePart->Substring(dateEndIndex)->Trim();

			//// 실제 메시지 추출 (날짜 이전의 부분)
			String^ messageText = messagePart->Substring(0, dateEndIndex)->Trim();
			int rowIndex = ViewDataChat->Rows->Add();
			ViewDataChat->Rows[rowIndex]->Cells["ViewId"]->Value = id;
			ViewDataChat->Rows[rowIndex]->Cells["ViewMsg"]->Value = messageText;
			ViewDataChat->Rows[rowIndex]->Cells["Date"]->Value = date;

		}


		public: void UpdateMessage(String^ message)
		{
			String^ e_length = _my->s_(e_room_show_whole_Text);
			String^ msg = message->Substring(e_length->Length + 6);

			// 아이디 추출
			int idEndIndex = msg->IndexOf(' '); // 공백 이전까지가 아이디
			String^ id = msg->Substring(0, idEndIndex)->Trim();

			// 메시지 추출
			String^ messagePart = msg->Substring(idEndIndex)->Trim();

			// 날짜 추출
			int lastSpaceIndex = messagePart->LastIndexOf(' '); // 뒤에서부터 첫 번째 공백의 위치
			int dateEndIndex = messagePart->LastIndexOf(' ', lastSpaceIndex - 1); // 뒤에서부터 두 번째 공백의 위치
			String^ date = messagePart->Substring(dateEndIndex)->Trim();

			// 실제 메시지 추출 (날짜 이전의 부분)
			String^ messageText = messagePart->Substring(0, dateEndIndex)->Trim();

			// 각각의 텍스트 박스에 표시
			txtBoxId->Text += id + Environment::NewLine;
			txtBoxMessage->Text += messageText + Environment::NewLine;
			txtBoxDate->Text += date + Environment::NewLine;

			return;
		}

		private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		private: System::Void ChatRoom_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {

			String^ buffer = _my->s_(e_room_Exit);
			_my->SendMessage(buffer);
			this->Owner->Show();
			this->Owner->Activate();


		}

		private: System::Void txtBoxMyChat_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
			// Check if Enter key (carriage return) was pressed
			if (e->KeyChar == (char)Keys::Enter) {
				// Trigger the "Send" button's click event
				btnSend_Click(sender, e);
			}
		}

		private: System::Void btnSend_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ tmptxt_1 = txtBoxMyChat->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			if (!String::IsNullOrEmpty(tmptxt_1))
			{
				int t_index = e_room_Chat;
				String^ buffer = _my->s_(t_index) + " " + tmptxt_1;
				_my->SendMessage(buffer);
				txtBoxMyChat->Text = "";
			}
		}

	};
}
