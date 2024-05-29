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
	/// AddFriends에 대한 요약입니다.
	/// </summary>
	public ref class AddFriends : public System::Windows::Forms::Form
	{
	public:
		AddFriends(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
		AddFriends(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &AddFriends::ReceivedMsg);
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~AddFriends()
		{
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &AddFriends::ReceivedMsg);

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


	private: System::Windows::Forms::TextBox^ txtBoxNickname;
	private: System::Windows::Forms::TextBox^ txtBoxReqMsg;
	private: System::Windows::Forms::Button^ btnSendReq;
	private: System::Windows::Forms::Button^ btnClose;
	private: MyFunction^ _my;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddFriends::typeid));
			this->txtBoxNickname = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxReqMsg = (gcnew System::Windows::Forms::TextBox());
			this->btnSendReq = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// txtBoxNickname
			// 
			this->txtBoxNickname->Location = System::Drawing::Point(283, 82);
			this->txtBoxNickname->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxNickname->Name = L"txtBoxNickname";
			this->txtBoxNickname->Size = System::Drawing::Size(161, 21);
			this->txtBoxNickname->TabIndex = 1;
			// 
			// txtBoxReqMsg
			// 
			this->txtBoxReqMsg->Location = System::Drawing::Point(127, 201);
			this->txtBoxReqMsg->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxReqMsg->Multiline = true;
			this->txtBoxReqMsg->Name = L"txtBoxReqMsg";
			this->txtBoxReqMsg->Size = System::Drawing::Size(369, 90);
			this->txtBoxReqMsg->TabIndex = 1;
			// 
			// btnSendReq
			// 
			this->btnSendReq->Location = System::Drawing::Point(159, 295);
			this->btnSendReq->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSendReq->Name = L"btnSendReq";
			this->btnSendReq->Size = System::Drawing::Size(160, 38);
			this->btnSendReq->TabIndex = 2;
			this->btnSendReq->Text = L"btnSendReq";
			this->btnSendReq->UseVisualStyleBackColor = true;
			this->btnSendReq->Click += gcnew System::EventHandler(this, &AddFriends::btnSendReq_Click);
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(383, 295);
			this->btnClose->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(160, 38);
			this->btnClose->TabIndex = 2;
			this->btnClose->Text = L"btnClose";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &AddFriends::btnClose_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Location = System::Drawing::Point(105, 41);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(66, 29);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox2->Location = System::Drawing::Point(159, 151);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(113, 29);
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// AddFriends
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(608, 426);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSendReq);
			this->Controls->Add(this->txtBoxReqMsg);
			this->Controls->Add(this->txtBoxNickname);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"AddFriends";
			this->Text = L"AddFriends";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	public: void SendMessageForm(int index)
	{

		switch (index)
		{
			case e_friends_Request:
			{
				String^ tmptxt_1 = txtBoxNickname->Text; // textBox는 해당 텍스트 상자의 이름입니다.
				String^ tmptxt_2 = txtBoxReqMsg->Text; // textBox는 해당 텍스트 상자의 이름입니다.

				if (!String::IsNullOrEmpty(tmptxt_1))
				{
					int t_index = e_friends_Request;
					String^ buffer = t_index.ToString() + " " + tmptxt_1 + " " + tmptxt_2;
					_my->SendMessage(buffer);
				}
				else
				{
					System::Windows::Forms::MessageBox::Show("Check the ID ", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
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
			case e_friends_Request:
			{
				if (isTrue == "true")
				{
					System::Windows::Forms::MessageBox::Show("Request sent", "Request", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else if (isTrue == "else")
				{
					System::Windows::Forms::MessageBox::Show("Already Sent", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				else
				{
					System::Windows::Forms::MessageBox::Show("No ID found", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}

				break;
			}
		}

	}


	private: System::Void btnSendReq_Click(System::Object^ sender, System::EventArgs^ e) {
		this->SendMessageForm(e_friends_Request);

	}
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
