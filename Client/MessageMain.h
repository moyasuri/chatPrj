#pragma once
#include "MyFunction.h"
#include "enum.h"
#include "MsgBox.h"
#include "MessageSent.h"
#include "NewMessage.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MessageMain에 대한 요약입니다.
	/// </summary>
	public ref class MessageMain : public System::Windows::Forms::Form
	{
	public:
		MessageMain(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

		MessageMain(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;

		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MessageMain()
		{
			if (_my != nullptr) {
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnNew;
	protected:
	private: System::Windows::Forms::Button^ btnSent;
	private: System::Windows::Forms::Button^ btnMsgBox;
	private: System::Windows::Forms::Button^ btnClose;
	private: MyFunction^ _my;
		   NewMessage^ newMessage = nullptr;
		   MessageSent^ messageSent = nullptr;
		   MsgBox^ msgBox = nullptr;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MessageMain::typeid));
			this->btnNew = (gcnew System::Windows::Forms::Button());
			this->btnSent = (gcnew System::Windows::Forms::Button());
			this->btnMsgBox = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnNew
			// 
			this->btnNew->BackColor = System::Drawing::Color::Transparent;
			this->btnNew->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNew.BackgroundImage")));
			this->btnNew->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnNew->FlatAppearance->BorderSize = 0;
			this->btnNew->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			this->btnNew->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnNew->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnNew->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNew->Location = System::Drawing::Point(24, 30);
			this->btnNew->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnNew->Name = L"btnNew";
			this->btnNew->Size = System::Drawing::Size(158, 58);
			this->btnNew->TabIndex = 0;
			this->btnNew->UseVisualStyleBackColor = false;
			this->btnNew->Click += gcnew System::EventHandler(this, &MessageMain::btnNew_Click);
			// 
			// btnSent
			// 
			this->btnSent->BackColor = System::Drawing::Color::Transparent;
			this->btnSent->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSent.BackgroundImage")));
			this->btnSent->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSent->FlatAppearance->BorderSize = 0;
			this->btnSent->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			this->btnSent->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSent->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSent->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSent->Location = System::Drawing::Point(24, 119);
			this->btnSent->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSent->Name = L"btnSent";
			this->btnSent->Size = System::Drawing::Size(158, 58);
			this->btnSent->TabIndex = 0;
			this->btnSent->UseVisualStyleBackColor = false;
			this->btnSent->Click += gcnew System::EventHandler(this, &MessageMain::btnSent_Click);
			// 
			// btnMsgBox
			// 
			this->btnMsgBox->BackColor = System::Drawing::Color::Transparent;
			this->btnMsgBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMsgBox.BackgroundImage")));
			this->btnMsgBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnMsgBox->FlatAppearance->BorderSize = 0;
			this->btnMsgBox->FlatAppearance->CheckedBackColor = System::Drawing::Color::Transparent;
			this->btnMsgBox->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnMsgBox->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnMsgBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMsgBox->Location = System::Drawing::Point(24, 206);
			this->btnMsgBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnMsgBox->Name = L"btnMsgBox";
			this->btnMsgBox->Size = System::Drawing::Size(158, 58);
			this->btnMsgBox->TabIndex = 0;
			this->btnMsgBox->UseVisualStyleBackColor = false;
			this->btnMsgBox->Click += gcnew System::EventHandler(this, &MessageMain::btnMsgBox_Click);
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
			this->btnClose->Location = System::Drawing::Point(500, 324);
			this->btnClose->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(158, 58);
			this->btnClose->TabIndex = 0;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &MessageMain::btnClose_Click);
			// 
			// MessageMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(668, 386);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnMsgBox);
			this->Controls->Add(this->btnSent);
			this->Controls->Add(this->btnNew);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MessageMain";
			this->Text = L"MessageMain";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MessageMain::MessageMain_FormClosing);
			this->ResumeLayout(false);

		}
#pragma endregion


		private: System::Void btnNew_Click(System::Object^ sender, System::EventArgs^ e) {
			if (newMessage == nullptr || newMessage->IsDisposed) {
				newMessage = gcnew NewMessage(_my);
				newMessage->Owner = this; // Owner를 설정해야 가능
				//this->HomeImageSound->Stop();
				newMessage->Show();
			}
		}
		private: System::Void btnSent_Click(System::Object^ sender, System::EventArgs^ e) {
			if (messageSent == nullptr || messageSent->IsDisposed) {
				messageSent = gcnew MessageSent(_my);
				messageSent->Owner = this; // Owner를 설정해야 가능
				//this->HomeImageSound->Stop();
				messageSent->Show();
			}
		}
		private: System::Void btnMsgBox_Click(System::Object^ sender, System::EventArgs^ e) {
			if (msgBox == nullptr || msgBox->IsDisposed) {
				msgBox = gcnew MsgBox(_my);
				msgBox->Owner = this; // Owner를 설정해야 가능
				//this->HomeImageSound->Stop();
				msgBox->Show();
			}
		}
		private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
		private: System::Void MessageMain_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			this->Owner->Show();
			this->Owner->Activate();
		}
};
}
