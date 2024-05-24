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
			this->btnNew = (gcnew System::Windows::Forms::Button());
			this->btnSent = (gcnew System::Windows::Forms::Button());
			this->btnMsgBox = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnNew
			// 
			this->btnNew->Location = System::Drawing::Point(112, 32);
			this->btnNew->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnNew->Name = L"btnNew";
			this->btnNew->Size = System::Drawing::Size(158, 58);
			this->btnNew->TabIndex = 0;
			this->btnNew->Text = L"new";
			this->btnNew->UseVisualStyleBackColor = true;
			this->btnNew->Click += gcnew System::EventHandler(this, &MessageMain::btnNew_Click);
			// 
			// btnSent
			// 
			this->btnSent->Location = System::Drawing::Point(112, 121);
			this->btnSent->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSent->Name = L"btnSent";
			this->btnSent->Size = System::Drawing::Size(158, 58);
			this->btnSent->TabIndex = 0;
			this->btnSent->Text = L"sent";
			this->btnSent->UseVisualStyleBackColor = true;
			this->btnSent->Click += gcnew System::EventHandler(this, &MessageMain::btnSent_Click);
			// 
			// btnMsgBox
			// 
			this->btnMsgBox->Location = System::Drawing::Point(112, 208);
			this->btnMsgBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnMsgBox->Name = L"btnMsgBox";
			this->btnMsgBox->Size = System::Drawing::Size(158, 58);
			this->btnMsgBox->TabIndex = 0;
			this->btnMsgBox->Text = L"msgbox";
			this->btnMsgBox->UseVisualStyleBackColor = true;
			this->btnMsgBox->Click += gcnew System::EventHandler(this, &MessageMain::btnMsgBox_Click);
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(268, 300);
			this->btnClose->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(158, 58);
			this->btnClose->TabIndex = 0;
			this->btnClose->Text = L"close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &MessageMain::btnClose_Click);
			// 
			// MessageMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(452, 386);
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
