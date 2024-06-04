#pragma once
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
	using namespace System::Media;
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


			String^ currentDirectory = System::Environment::CurrentDirectory;


			String^ relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\Button\\editprofile.png");
			btnEditProfile->BackgroundImage = Image::FromFile(relativePath);

			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\Button\\friends.png");
			btnFriends->BackgroundImage = Image::FromFile(relativePath);

			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\Button\\message.png");
			btnMessage->BackgroundImage = Image::FromFile(relativePath);

			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\Button\\signout.png");
			btnSignOut->BackgroundImage = Image::FromFile(relativePath);

			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\Button\\joinroom.png");
			btnJoinChatRoom->BackgroundImage = Image::FromFile(relativePath);

			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\Button\\deleteroom.png");
			btnDelChatRoom->BackgroundImage = Image::FromFile(relativePath);

			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Img\\Button\\createroom.png");
			btnCreateChatRoom->BackgroundImage = Image::FromFile(relativePath);
			
			IntroImageSound = gcnew SoundPlayer;
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\BGM\\Nichirin.wav");
			IntroImageSound->SoundLocation = relativePath;


			// 필요에 따라 버튼의 크기 모드를 설정합니다.
			btnEditProfile->BackgroundImageLayout = ImageLayout::Stretch;
			btnFriends->BackgroundImageLayout = ImageLayout::Stretch;
			btnMessage->BackgroundImageLayout = ImageLayout::Stretch;
			btnSignOut->BackgroundImageLayout = ImageLayout::Stretch;
			btnJoinChatRoom->BackgroundImageLayout = ImageLayout::Zoom;
			btnDelChatRoom->BackgroundImageLayout = ImageLayout::Zoom;
			btnCreateChatRoom->BackgroundImageLayout = ImageLayout::Zoom;


		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MainForm()
		{
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				this->_my->disposed();
				_my->MyEvent -= gcnew Action<String^>(this, &MainForm::ReceivedMsg);
				// _my를 삭제
				delete IntroImageSound;
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
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: SoundPlayer^ IntroImageSound;
	private: bool isFirstActivation = true;









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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->btnJoinChatRoom = (gcnew System::Windows::Forms::Button());
			this->btnCreateChatRoom = (gcnew System::Windows::Forms::Button());
			this->btnDelChatRoom = (gcnew System::Windows::Forms::Button());
			this->btnEditProfile = (gcnew System::Windows::Forms::Button());
			this->btnFriends = (gcnew System::Windows::Forms::Button());
			this->btnMessage = (gcnew System::Windows::Forms::Button());
			this->btnSignOut = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->NumMessage = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnJoinChatRoom
			// 
			this->btnJoinChatRoom->BackColor = System::Drawing::Color::Transparent;
			this->btnJoinChatRoom->FlatAppearance->BorderSize = 0;
			this->btnJoinChatRoom->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnJoinChatRoom->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnJoinChatRoom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnJoinChatRoom->Location = System::Drawing::Point(203, 56);
			this->btnJoinChatRoom->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->btnJoinChatRoom->Name = L"btnJoinChatRoom";
			this->btnJoinChatRoom->Size = System::Drawing::Size(381, 100);
			this->btnJoinChatRoom->TabIndex = 0;
			this->btnJoinChatRoom->UseVisualStyleBackColor = false;
			this->btnJoinChatRoom->Click += gcnew System::EventHandler(this, &MainForm::btnJoinChatRoom_Click);
			// 
			// btnCreateChatRoom
			// 
			this->btnCreateChatRoom->BackColor = System::Drawing::Color::Transparent;
			this->btnCreateChatRoom->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCreateChatRoom->FlatAppearance->BorderSize = 0;
			this->btnCreateChatRoom->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnCreateChatRoom->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnCreateChatRoom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCreateChatRoom->Location = System::Drawing::Point(203, 178);
			this->btnCreateChatRoom->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->btnCreateChatRoom->Name = L"btnCreateChatRoom";
			this->btnCreateChatRoom->Size = System::Drawing::Size(381, 100);
			this->btnCreateChatRoom->TabIndex = 0;
			this->btnCreateChatRoom->UseVisualStyleBackColor = false;
			this->btnCreateChatRoom->Click += gcnew System::EventHandler(this, &MainForm::btnCreateChatRoom_Click);
			// 
			// btnDelChatRoom
			// 
			this->btnDelChatRoom->BackColor = System::Drawing::Color::Transparent;
			this->btnDelChatRoom->FlatAppearance->BorderSize = 0;
			this->btnDelChatRoom->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnDelChatRoom->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnDelChatRoom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDelChatRoom->Location = System::Drawing::Point(203, 302);
			this->btnDelChatRoom->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->btnDelChatRoom->Name = L"btnDelChatRoom";
			this->btnDelChatRoom->Size = System::Drawing::Size(381, 100);
			this->btnDelChatRoom->TabIndex = 0;
			this->btnDelChatRoom->UseVisualStyleBackColor = false;
			this->btnDelChatRoom->Click += gcnew System::EventHandler(this, &MainForm::btnDelChatRoom_Click);
			// 
			// btnEditProfile
			// 
			this->btnEditProfile->BackColor = System::Drawing::Color::Transparent;
			this->btnEditProfile->FlatAppearance->BorderSize = 0;
			this->btnEditProfile->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnEditProfile->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnEditProfile->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEditProfile->Location = System::Drawing::Point(123, 448);
			this->btnEditProfile->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->btnEditProfile->Name = L"btnEditProfile";
			this->btnEditProfile->Size = System::Drawing::Size(97, 136);
			this->btnEditProfile->TabIndex = 0;
			this->btnEditProfile->UseVisualStyleBackColor = false;
			this->btnEditProfile->Click += gcnew System::EventHandler(this, &MainForm::btnEditProfile_Click);
			// 
			// btnFriends
			// 
			this->btnFriends->BackColor = System::Drawing::Color::Transparent;
			this->btnFriends->FlatAppearance->BorderSize = 0;
			this->btnFriends->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnFriends->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnFriends->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFriends->Location = System::Drawing::Point(326, 448);
			this->btnFriends->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->btnFriends->Name = L"btnFriends";
			this->btnFriends->Size = System::Drawing::Size(114, 136);
			this->btnFriends->TabIndex = 0;
			this->btnFriends->UseVisualStyleBackColor = false;
			this->btnFriends->Click += gcnew System::EventHandler(this, &MainForm::btnFriends_Click);
			// 
			// btnMessage
			// 
			this->btnMessage->BackColor = System::Drawing::Color::Transparent;
			this->btnMessage->FlatAppearance->BorderSize = 0;
			this->btnMessage->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnMessage->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnMessage->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMessage->Location = System::Drawing::Point(516, 474);
			this->btnMessage->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->btnMessage->Name = L"btnMessage";
			this->btnMessage->Size = System::Drawing::Size(171, 88);
			this->btnMessage->TabIndex = 0;
			this->btnMessage->UseVisualStyleBackColor = false;
			this->btnMessage->Click += gcnew System::EventHandler(this, &MainForm::btnMessage_Click);
			// 
			// btnSignOut
			// 
			this->btnSignOut->BackColor = System::Drawing::Color::Transparent;
			this->btnSignOut->FlatAppearance->BorderSize = 0;
			this->btnSignOut->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSignOut->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSignOut->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignOut->Location = System::Drawing::Point(534, 656);
			this->btnSignOut->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->btnSignOut->Name = L"btnSignOut";
			this->btnSignOut->Size = System::Drawing::Size(220, 88);
			this->btnSignOut->TabIndex = 0;
			this->btnSignOut->UseVisualStyleBackColor = false;
			this->btnSignOut->Click += gcnew System::EventHandler(this, &MainForm::btnSignOut_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->panel1->Controls->Add(this->NumMessage);
			this->panel1->Location = System::Drawing::Point(659, 384);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(99, 96);
			this->panel1->TabIndex = 1;
			// 
			// NumMessage
			// 
			this->NumMessage->AutoSize = true;
			this->NumMessage->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NumMessage->ForeColor = System::Drawing::Color::DarkCyan;
			this->NumMessage->Location = System::Drawing::Point(47, 30);
			this->NumMessage->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->NumMessage->Name = L"NumMessage";
			this->NumMessage->Size = System::Drawing::Size(29, 28);
			this->NumMessage->TabIndex = 0;
			this->NumMessage->Text = L"la";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox2->Location = System::Drawing::Point(296, 582);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(171, 45);
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox3->Location = System::Drawing::Point(514, 585);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(171, 45);
			this->pictureBox3->TabIndex = 4;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Location = System::Drawing::Point(89, 584);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(171, 45);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(809, 777);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnSignOut);
			this->Controls->Add(this->btnMessage);
			this->Controls->Add(this->btnFriends);
			this->Controls->Add(this->btnEditProfile);
			this->Controls->Add(this->btnDelChatRoom);
			this->Controls->Add(this->btnCreateChatRoom);
			this->Controls->Add(this->btnJoinChatRoom);
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Activated += gcnew System::EventHandler(this, &MainForm::MainForm_Activated);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->VisibleChanged += gcnew System::EventHandler(this, &MainForm::MainForm_VisibleChanged);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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
	private: System::Void btnSignOut_Click(System::Object^ sender, System::EventArgs^ e) {
		
		this->Close();
	}
	private: System::Void MainForm_Activated(System::Object^ sender, System::EventArgs^ e) {
		SendMessageForm(e_message_Cnt);
	}
	private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		this->Owner->Show();
		this->Owner->Activate();
		delete NumMessage;
	}


private: System::Void MainForm_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {
	if (isFirstActivation) {

		IntroImageSound->Load();
		IntroImageSound->PlayLooping();

		isFirstActivation = false; // 처음 활성화 시 함수 실행을 건너뛰기
	}

	



}
private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
