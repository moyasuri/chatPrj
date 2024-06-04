#pragma once
#include "MyFunction.h"
#include "enum.h"
#include "PreviousChat.h"
#include <iostream>

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
			
			
			

			currentDirectory = System::Environment::CurrentDirectory;


		


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


	private: System::Windows::Forms::TextBox^ txtBoxMessage;
	private: System::Windows::Forms::TextBox^ txtBoxMyChat;





	private: System::Windows::Forms::Button^ btnSend;
	private: System::Windows::Forms::Button^ btnClose;
	private: MyFunction^ _my;
	private: String^ currentDirectory;


	private: System::Windows::Forms::Button^ btnPreviewChat;


	private: PreviousChat^ previousChat = nullptr;
	private: System::Windows::Forms::Timer^ timerDeletePicBoxIntro;
	private: System::Windows::Forms::ListBox^ listBoxUser;






	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ChatRoom::typeid));
			this->picBoxImojiMy = (gcnew System::Windows::Forms::PictureBox());
			this->txtBoxMessage = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxMyChat = (gcnew System::Windows::Forms::TextBox());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnPreviewChat = (gcnew System::Windows::Forms::Button());
			this->timerDeletePicBoxIntro = (gcnew System::Windows::Forms::Timer(this->components));
			this->listBoxUser = (gcnew System::Windows::Forms::ListBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiMy))->BeginInit();
			this->SuspendLayout();
			// 
			// picBoxImojiMy
			// 
			this->picBoxImojiMy->BackColor = System::Drawing::Color::Transparent;
			this->picBoxImojiMy->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBoxImojiMy.InitialImage")));
			this->picBoxImojiMy->Location = System::Drawing::Point(630, 52);
			this->picBoxImojiMy->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->picBoxImojiMy->Name = L"picBoxImojiMy";
			this->picBoxImojiMy->Size = System::Drawing::Size(200, 240);
			this->picBoxImojiMy->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->picBoxImojiMy->TabIndex = 0;
			this->picBoxImojiMy->TabStop = false;
			this->picBoxImojiMy->Visible = false;
			this->picBoxImojiMy->WaitOnLoad = true;
			// 
			// txtBoxMessage
			// 
			this->txtBoxMessage->Location = System::Drawing::Point(63, 55);
			this->txtBoxMessage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxMessage->Multiline = true;
			this->txtBoxMessage->Name = L"txtBoxMessage";
			this->txtBoxMessage->Size = System::Drawing::Size(381, 234);
			this->txtBoxMessage->TabIndex = 2;
			// 
			// txtBoxMyChat
			// 
			this->txtBoxMyChat->Location = System::Drawing::Point(63, 322);
			this->txtBoxMyChat->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxMyChat->Name = L"txtBoxMyChat";
			this->txtBoxMyChat->Size = System::Drawing::Size(379, 21);
			this->txtBoxMyChat->TabIndex = 2;
			this->txtBoxMyChat->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ChatRoom::txtBoxMyChat_KeyPress);
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
			this->btnSend->Location = System::Drawing::Point(47, 356);
			this->btnSend->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(149, 57);
			this->btnSend->TabIndex = 4;
			this->btnSend->UseVisualStyleBackColor = false;
			this->btnSend->Click += gcnew System::EventHandler(this, &ChatRoom::btnSend_Click);
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
			this->btnClose->Location = System::Drawing::Point(310, 473);
			this->btnClose->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(149, 57);
			this->btnClose->TabIndex = 4;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &ChatRoom::btnClose_Click);
			// 
			// btnPreviewChat
			// 
			this->btnPreviewChat->BackColor = System::Drawing::Color::Transparent;
			this->btnPreviewChat->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnPreviewChat.BackgroundImage")));
			this->btnPreviewChat->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPreviewChat->FlatAppearance->BorderSize = 0;
			this->btnPreviewChat->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			this->btnPreviewChat->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnPreviewChat->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnPreviewChat->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPreviewChat->Location = System::Drawing::Point(310, 356);
			this->btnPreviewChat->Name = L"btnPreviewChat";
			this->btnPreviewChat->Size = System::Drawing::Size(149, 57);
			this->btnPreviewChat->TabIndex = 5;
			this->btnPreviewChat->UseVisualStyleBackColor = false;
			this->btnPreviewChat->Click += gcnew System::EventHandler(this, &ChatRoom::btnPreviewChat_Click);
			// 
			// listBoxUser
			// 
			this->listBoxUser->FormattingEnabled = true;
			this->listBoxUser->ItemHeight = 12;
			this->listBoxUser->Location = System::Drawing::Point(474, 55);
			this->listBoxUser->Name = L"listBoxUser";
			this->listBoxUser->Size = System::Drawing::Size(138, 232);
			this->listBoxUser->TabIndex = 6;
			// 
			// ChatRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(855, 601);
			this->Controls->Add(this->listBoxUser);
			this->Controls->Add(this->btnPreviewChat);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->txtBoxMyChat);
			this->Controls->Add(this->txtBoxMessage);
			this->Controls->Add(this->picBoxImojiMy);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"ChatRoom";
			this->Text = L"ChatRoom";
			this->Activated += gcnew System::EventHandler(this, &ChatRoom::ChatRoom_Activated);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ChatRoom::ChatRoom_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiMy))->EndInit();
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
			case e_room_User:
			{

				if (isTrue == "true")
				{
					listBoxUser->Items->Clear();
					for (int i = 2; i < subString->Length;i++)
					{
						
						listBoxUser->Items->Add(gcnew String(subString[i]));
					}
					

				}

				Sleep(100);
				
				break;
			}

			}

		}




		public: void UpdateMessage(String^ message)
		{
			String^ e_length = _my->s_(e_room_Chat);
			String^ msg = message->Substring(e_length->Length + 6);
			
			// 아이디 추출
			int idEndIndex = msg->IndexOf(' '); // 공백 이전까지가 아이디
			String^ id = msg->Substring(0, idEndIndex)->Trim();

			
			// 첫 번째 공백 이후의 문자열을 가져옴
			String^ remaining = msg->Substring(idEndIndex + 1)->Trim();

			// 두 번째 구분자 위치 찾기
			int chaEndIndex = remaining->IndexOf(' '); // 두 번째 공백의 위치
			String^ cha = remaining->Substring(0, chaEndIndex)->Trim();

			

			// 메시지 추출
			String^ messagePart = msg->Substring(idEndIndex+2)->Trim();

			// 날짜 추출
			int lastSpaceIndex = messagePart->LastIndexOf(' '); // 뒤에서부터 첫 번째 공백의 위치
			int dateEndIndex = messagePart->LastIndexOf(' ', lastSpaceIndex - 1); // 뒤에서부터 두 번째 공백의 위치
			String^ date = messagePart->Substring(dateEndIndex)->Trim();

			// 실제 메시지 추출 (날짜 이전의 부분)
			String^ messageText = messagePart->Substring(0, dateEndIndex)->Trim();

			// 각각의 텍스트 박스에 표시
			//txtBoxId->Text += id + Environment::NewLine; // 삭제
			txtBoxMessage->Text += id + " : " + messageText + "  [" + date + "]" + Environment::NewLine;
			// txtBoxDate->Text += date + Environment::NewLine; // 삭제

			ProcessText(messageText,cha);



			return;
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
		private: System::Void btnPreviewChat_Click(System::Object^ sender, System::EventArgs^ e) {
			if (previousChat == nullptr || previousChat->IsDisposed) {
				previousChat = gcnew PreviousChat(_my);
				previousChat->Owner = this; // Owner를 설정해야 가능
				//this->HomeImageSound->Stop();
				previousChat->Show();
			}

		}

		private: bool ContCha(String^ str, String^ searchString) {
			// String 클래스의 Contains 메서드를 사용하여 문자열 포함 여부를 확인합니다.
			return str->Contains(searchString);
		}


		private: void ShowImageIfContains(String ^ text, String ^ searchString, String ^ imageName)
		{
			if (this->ContCha(text, searchString))
			{
				String^ relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Imoji\\" + imageName);
				picBoxImojiMy->ImageLocation = relativePath;
				this->picBoxImojiMy->Show();

				if (!timerDeletePicBoxIntro->Enabled)
				{
					timerDeletePicBoxIntro->Interval = 3000;
					timerDeletePicBoxIntro->Tick -= gcnew System::EventHandler(this, &ChatRoom::timerDeletePicBoxIntro_Tick);
					timerDeletePicBoxIntro->Tick += gcnew System::EventHandler(this, &ChatRoom::timerDeletePicBoxIntro_Tick);
					timerDeletePicBoxIntro->Start();
				}
				else
				{
					timerDeletePicBoxIntro->Stop(); // 타이머를 멈추고 다시 시작하여 타이머를 초기화
					timerDeletePicBoxIntro->Start();
				}
			}
		}

		// 타이머 이벤트 핸들러
		void timerDeletePicBoxIntro_Tick(Object^ sender, EventArgs^ e)
		{
			this->picBoxImojiMy->Hide();
			timerDeletePicBoxIntro->Stop();
		}

			   // 주어진 텍스트를 처리하는 함수
		void ProcessText(String^ tmptxt_1, String^ cha)
		{
			int i_cha = Convert::ToInt32(cha);

			if (i_cha == e_character_izuna)
			{

				ShowImageIfContains(tmptxt_1, "성큰", "icon_48.gif");
				ShowImageIfContains(tmptxt_1, "ㅠㅠ", "icon_3.gif");
				ShowImageIfContains(tmptxt_1, "야이씨", "icon_45.gif");
				ShowImageIfContains(tmptxt_1, "튀어", "icon_21.gif");
				

			}
			else if (i_cha == e_character_hihumi)
			{
				ShowImageIfContains(tmptxt_1, "ㄴㄴ", "icon_24.gif");
				ShowImageIfContains(tmptxt_1, "ㅇㅇ", "icon_23.png");
				ShowImageIfContains(tmptxt_1, "...", "h_icon_6.png");
				ShowImageIfContains(tmptxt_1, "헙", "h_icon_13.png");
				ShowImageIfContains(tmptxt_1, "사랑한다고?", "h_icon_40.png");
				ShowImageIfContains(tmptxt_1, "땡큐", "h_icon_12.png");
				ShowImageIfContains(tmptxt_1, "그런거임?", "h_icon_11.png");

			}

			else if (i_cha == e_character_mari)
			{
				ShowImageIfContains(tmptxt_1, "ㄱㅊ", "m_icon_43.png");
				ShowImageIfContains(tmptxt_1, "음", "m_icon_41.png");
				ShowImageIfContains(tmptxt_1, "생축", "m_icon_27.gif");
				ShowImageIfContains(tmptxt_1, "???", "m_icon_16.gif");
				ShowImageIfContains(tmptxt_1, "쪼아요", "m_icon_32.png");
				ShowImageIfContains(tmptxt_1, "잘자", "m_icon_3.gif");
			}


		}
		private: System::Void ChatRoom_Activated(System::Object^ sender, System::EventArgs^ e) {

			
			
			
			int t_index = e_room_User;
			String^ buffer = _my->s_(t_index);
			_my->SendMessage(buffer);
			
		
		}


};
}
