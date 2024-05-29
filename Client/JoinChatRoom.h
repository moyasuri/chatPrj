#pragma once
#include "MyFunction.h"
#include "enum.h"
#include "ChatRoom.h"
#include "GeneralChatList.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// JoinChatRoom에 대한 요약입니다.
	/// </summary>
	public ref class JoinChatRoom : public System::Windows::Forms::Form
	{
	public:
		JoinChatRoom(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
		JoinChatRoom(MyFunction^ my)
		{

			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//

			_my = my;
			this->_my->MyEvent += gcnew Action<String^>(this, &JoinChatRoom::ReceivedMsg);
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~JoinChatRoom()
		{
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &JoinChatRoom::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnServer;
	protected:
	private: System::Windows::Forms::Button^ btnGeneral;
	private: System::Windows::Forms::Button^ btnClose;
	private: MyFunction^ _my;
	private: ChatRoom^ chatRoom = nullptr;
	public: GeneralChatList^ generalChatList = nullptr;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(JoinChatRoom::typeid));
			this->btnServer = (gcnew System::Windows::Forms::Button());
			this->btnGeneral = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnServer
			// 
			this->btnServer->BackColor = System::Drawing::Color::Transparent;
			this->btnServer->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnServer->FlatAppearance->BorderSize = 0;
			this->btnServer->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnServer->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnServer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnServer->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnServer.Image")));
			this->btnServer->Location = System::Drawing::Point(74, 57);
			this->btnServer->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnServer->Name = L"btnServer";
			this->btnServer->Size = System::Drawing::Size(167, 52);
			this->btnServer->TabIndex = 0;
			this->btnServer->UseVisualStyleBackColor = false;
			this->btnServer->Click += gcnew System::EventHandler(this, &JoinChatRoom::btnServer_Click);
			// 
			// btnGeneral
			// 
			this->btnGeneral->BackColor = System::Drawing::Color::Transparent;
			this->btnGeneral->FlatAppearance->BorderSize = 0;
			this->btnGeneral->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnGeneral->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnGeneral->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnGeneral->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnGeneral.Image")));
			this->btnGeneral->Location = System::Drawing::Point(278, 57);
			this->btnGeneral->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnGeneral->Name = L"btnGeneral";
			this->btnGeneral->Size = System::Drawing::Size(167, 52);
			this->btnGeneral->TabIndex = 0;
			this->btnGeneral->UseVisualStyleBackColor = false;
			this->btnGeneral->Click += gcnew System::EventHandler(this, &JoinChatRoom::btnGeneral_Click);
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::Transparent;
			this->btnClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClose.Image")));
			this->btnClose->Location = System::Drawing::Point(319, 311);
			this->btnClose->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(167, 52);
			this->btnClose->TabIndex = 1;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &JoinChatRoom::btnClose_Click);
			// 
			// JoinChatRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(498, 374);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnGeneral);
			this->Controls->Add(this->btnServer);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"JoinChatRoom";
			this->Text = L"JoinChatRoom";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &JoinChatRoom::JoinChatRoom_FormClosing);
			this->ResumeLayout(false);

		}
#pragma endregion


		public: void SendMessageForm(int index)
		{

			switch (index)
			{
			case e_room_Enter:
			{

				int t_index = e_room_Enter;
				String^ buffer = _my->s_(e_room_Enter) + " " + "1" + " " + "1";
				_my->SendMessage(buffer);

				break;
			}

			}

		}

		private: void JoinServerChat(String^ message)
		{
			if (chatRoom == nullptr || chatRoom->IsDisposed) {

				chatRoom = gcnew ChatRoom(_my);
				chatRoom->Owner = this; // Owner를 설정해야 가능
				chatRoom->Show();
				this->Hide();
			}	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
			else {
				chatRoom->Activate();
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
				case e_room_Enter:
				{
					if (isTrue == "else")
					{
						this->Invoke(gcnew Action<String^>(this, &JoinChatRoom::JoinServerChat), message);

					}
					else
					{
						// false 시에 할 행동
					}
					break;
				}

			}
		}




		private: System::Void btnServer_Click(System::Object^ sender, System::EventArgs^ e) {
			SendMessageForm(e_room_Enter);
		}
		private: System::Void btnGeneral_Click(System::Object^ sender, System::EventArgs^ e) {
			if (generalChatList == nullptr || generalChatList->IsDisposed) {
				generalChatList = gcnew GeneralChatList(_my);
				generalChatList->Owner = this; // Owner를 설정해야 가능
				this->Hide();
				//this->HomeImageSound->Stop();
				generalChatList->Show();
			}
		}
		private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
		private: System::Void JoinChatRoom_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			this->Owner->Show();
			this->Owner->Activate();
		}
};
}
