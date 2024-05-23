﻿#pragma once
#include "enum.h"
#include "MyFunction.h"
#include "Friends.h"
#include "MessageMain.h"
#include "JoinChatRoom.h"
#include "CreateChatRoom.h"
#include "DeleteRoom.h"
#include "EditProfile.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MainForm에 대한 요약입니다.
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

		MainForm(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &MainForm::ReceivedMsg);

			//relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Button\\Img_Gacha_Char_SSR_Resume.png");
			//btnFriends->BackgroundImage = Image::FromFile(relativePath);


		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MainForm()
		{
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &MainForm::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}


			if (components)
			{
				delete components;
			}

		}
	private: System::Windows::Forms::Button^ btnJoinChatRoom;
	private: System::Windows::Forms::Button^ btnCreateChatRoom;
	private: System::Windows::Forms::Button^ btnDelChatRoom;
	private: System::Windows::Forms::Button^ btnEditProfile;
	private: System::Windows::Forms::Button^ btnFriends;
	private: System::Windows::Forms::Button^ btnMessage;
	private: System::Windows::Forms::Button^ btnSignOut;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ NumMessage;
	private: MyFunction^ _my;
	private:
		String^ numMsg;
		EditProfile^ editProfile = nullptr;
		Friends^ friends = nullptr;
		MessageMain^ messageMain = nullptr;
		CreateChatRoom^ createchatRoom = nullptr;
		JoinChatRoom^ joinchatRoom = nullptr;
		DeleteRoom^ deleteRoom = nullptr;






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
			this->btnJoinChatRoom = (gcnew System::Windows::Forms::Button());
			this->btnCreateChatRoom = (gcnew System::Windows::Forms::Button());
			this->btnDelChatRoom = (gcnew System::Windows::Forms::Button());
			this->btnEditProfile = (gcnew System::Windows::Forms::Button());
			this->btnFriends = (gcnew System::Windows::Forms::Button());
			this->btnMessage = (gcnew System::Windows::Forms::Button());
			this->btnSignOut = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->NumMessage = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnJoinChatRoom
			// 
			this->btnJoinChatRoom->Location = System::Drawing::Point(196, 59);
			this->btnJoinChatRoom->Name = L"btnJoinChatRoom";
			this->btnJoinChatRoom->Size = System::Drawing::Size(228, 64);
			this->btnJoinChatRoom->TabIndex = 0;
			this->btnJoinChatRoom->Text = L"joinroom";
			this->btnJoinChatRoom->UseVisualStyleBackColor = true;
			// 
			// btnCreateChatRoom
			// 
			this->btnCreateChatRoom->Location = System::Drawing::Point(196, 165);
			this->btnCreateChatRoom->Name = L"btnCreateChatRoom";
			this->btnCreateChatRoom->Size = System::Drawing::Size(228, 64);
			this->btnCreateChatRoom->TabIndex = 0;
			this->btnCreateChatRoom->Text = L"createroom";
			this->btnCreateChatRoom->UseVisualStyleBackColor = true;
			// 
			// btnDelChatRoom
			// 
			this->btnDelChatRoom->Location = System::Drawing::Point(196, 262);
			this->btnDelChatRoom->Name = L"btnDelChatRoom";
			this->btnDelChatRoom->Size = System::Drawing::Size(228, 64);
			this->btnDelChatRoom->TabIndex = 0;
			this->btnDelChatRoom->Text = L"deleteroom";
			this->btnDelChatRoom->UseVisualStyleBackColor = true;
			// 
			// btnEditProfile
			// 
			this->btnEditProfile->Location = System::Drawing::Point(82, 374);
			this->btnEditProfile->Name = L"btnEditProfile";
			this->btnEditProfile->Size = System::Drawing::Size(92, 114);
			this->btnEditProfile->TabIndex = 0;
			this->btnEditProfile->Text = L"editprofile";
			this->btnEditProfile->UseVisualStyleBackColor = true;
			// 
			// btnFriends
			// 
			this->btnFriends->Location = System::Drawing::Point(258, 374);
			this->btnFriends->Name = L"btnFriends";
			this->btnFriends->Size = System::Drawing::Size(92, 114);
			this->btnFriends->TabIndex = 0;
			this->btnFriends->Text = L"friends";
			this->btnFriends->UseVisualStyleBackColor = true;
			// 
			// btnMessage
			// 
			this->btnMessage->Location = System::Drawing::Point(432, 374);
			this->btnMessage->Name = L"btnMessage";
			this->btnMessage->Size = System::Drawing::Size(92, 114);
			this->btnMessage->TabIndex = 0;
			this->btnMessage->Text = L"message";
			this->btnMessage->UseVisualStyleBackColor = true;
			// 
			// btnSignOut
			// 
			this->btnSignOut->Location = System::Drawing::Point(461, 548);
			this->btnSignOut->Name = L"btnSignOut";
			this->btnSignOut->Size = System::Drawing::Size(149, 47);
			this->btnSignOut->TabIndex = 0;
			this->btnSignOut->Text = L"signout";
			this->btnSignOut->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->NumMessage);
			this->panel1->Location = System::Drawing::Point(540, 262);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(109, 112);
			this->panel1->TabIndex = 1;
			// 
			// NumMessage
			// 
			this->NumMessage->AutoSize = true;
			this->NumMessage->Location = System::Drawing::Point(21, 37);
			this->NumMessage->Name = L"NumMessage";
			this->NumMessage->Size = System::Drawing::Size(45, 15);
			this->NumMessage->TabIndex = 0;
			this->NumMessage->Text = L"label1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(715, 620);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnSignOut);
			this->Controls->Add(this->btnMessage);
			this->Controls->Add(this->btnFriends);
			this->Controls->Add(this->btnEditProfile);
			this->Controls->Add(this->btnDelChatRoom);
			this->Controls->Add(this->btnCreateChatRoom);
			this->Controls->Add(this->btnJoinChatRoom);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		public: void SendMessageForm(int index)
		{

			switch (index)
			{
				case e_message_Cnt:
				{
					int t_index = e_message_Cnt;
					String^ buffer = _my->s_(t_index);
					_my->SendMessage(buffer);
					break;
				}
				default :
					return;

			}
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
				case e_message_Cnt:
				{

					if (isTrue == "true")
					{
						//txtBoxNickName->Invoke(gcnew Action<String^>(this, &YourFormName::UpdateTextBox), newText);
						String^ numMsg = subString[2];
						this->Invoke(gcnew Action<String^>(this, &MainForm::UpdateMessageCnt), numMsg);
					}
					break;
				}

			}

		}
		private: void UpdateMessageCnt(String^ _numMsg)
		{
			NumMessage->Text = _numMsg;
		}


		private: System::Void btnSignOut_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}


		private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			this->Owner->Show();
			this->Owner->Activate();
			delete NumMessage;
		}
		private: System::Void MainForm_Activated(System::Object^ sender, System::EventArgs^ e) {
			SendMessageForm(e_message_Cnt);
		}
		private: System::Void btnEditProfile_Click(System::Object^ sender, System::EventArgs^ e) {
			if (editProfile == nullptr || editProfile->IsDisposed) {
				editProfile = gcnew EditProfile(_my);
				editProfile->Owner = this; // Owner를 설정해야 가능
				this->Hide();
				//this->HomeImageSound->Stop();
				editProfile->Show();
			}
		}
		private: System::Void btnFriends_Click(System::Object^ sender, System::EventArgs^ e) {
			if (friends == nullptr || friends->IsDisposed) {
				friends = gcnew Friends(_my);
				friends->Owner = this; // Owner를 설정해야 가능
				this->Hide();
				//this->HomeImageSound->Stop();
				friends->Show();
			}
		}
		private: System::Void btnMessage_Click(System::Object^ sender, System::EventArgs^ e) {
			if (messageMain == nullptr || messageMain->IsDisposed) {
				messageMain = gcnew MessageMain(_my);
				messageMain->Owner = this; // Owner를 설정해야 가능
				this->Hide();
				//this->HomeImageSound->Stop();
				messageMain->Show();
			}
		}
		private: System::Void btnJoinChatRoom_Click(System::Object^ sender, System::EventArgs^ e) {
			if (joinchatRoom == nullptr || joinchatRoom->IsDisposed) {
				joinchatRoom = gcnew JoinChatRoom(_my);
				joinchatRoom->Owner = this; // Owner를 설정해야 가능
				this->Hide();
				//this->HomeImageSound->Stop();
				joinchatRoom->Show();
			}
		}
		private: System::Void btnCreateChatRoom_Click(System::Object^ sender, System::EventArgs^ e) {
			if (createchatRoom == nullptr || createchatRoom->IsDisposed) {
				createchatRoom = gcnew CreateChatRoom(_my);
				createchatRoom->Owner = this; // Owner를 설정해야 가능
				this->Hide();
				//this->HomeImageSound->Stop();
				createchatRoom->Show();
			}
		}
		private: System::Void btnDelChatRoom_Click(System::Object^ sender, System::EventArgs^ e) {
			if (deleteRoom == nullptr || deleteRoom->IsDisposed) {
				deleteRoom = gcnew DeleteRoom(_my);
				deleteRoom->Owner = this; // Owner를 설정해야 가능
				this->Hide();
				//this->HomeImageSound->Stop();
				deleteRoom->Show();
			}
		}
	};
}