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
	/// CreateChatRoom에 대한 요약입니다.
	/// </summary>
	public ref class CreateChatRoom : public System::Windows::Forms::Form
	{
	public:
		CreateChatRoom(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

		CreateChatRoom(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &CreateChatRoom::ReceivedMsg);
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~CreateChatRoom()
		{
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &CreateChatRoom::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtBoxRoomTitle;
	private: System::Windows::Forms::TextBox^ txtBoxPW;
	private: System::Windows::Forms::CheckBox^ chkBoxPrivate;
	private: System::Windows::Forms::Button^ btnConfirm;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtBoxRoomTitle = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxPW = (gcnew System::Windows::Forms::TextBox());
			this->chkBoxPrivate = (gcnew System::Windows::Forms::CheckBox());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(104, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"RoomTitle";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(104, 152);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 15);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Password";
			// 
			// txtBoxRoomTitle
			// 
			this->txtBoxRoomTitle->Location = System::Drawing::Point(229, 62);
			this->txtBoxRoomTitle->Name = L"txtBoxRoomTitle";
			this->txtBoxRoomTitle->Size = System::Drawing::Size(202, 25);
			this->txtBoxRoomTitle->TabIndex = 1;
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->Location = System::Drawing::Point(229, 149);
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->Size = System::Drawing::Size(202, 25);
			this->txtBoxPW->TabIndex = 1;
			// 
			// chkBoxPrivate
			// 
			this->chkBoxPrivate->AutoSize = true;
			this->chkBoxPrivate->Location = System::Drawing::Point(505, 64);
			this->chkBoxPrivate->Name = L"chkBoxPrivate";
			this->chkBoxPrivate->Size = System::Drawing::Size(71, 19);
			this->chkBoxPrivate->TabIndex = 2;
			this->chkBoxPrivate->Text = L"Private";
			this->chkBoxPrivate->UseVisualStyleBackColor = true;
			// 
			// btnConfirm
			// 
			this->btnConfirm->Location = System::Drawing::Point(107, 276);
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->Size = System::Drawing::Size(121, 27);
			this->btnConfirm->TabIndex = 3;
			this->btnConfirm->Text = L"btnConfirm";
			this->btnConfirm->UseVisualStyleBackColor = true;
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(443, 276);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(121, 27);
			this->btnClose->TabIndex = 3;
			this->btnClose->Text = L"btnClose";
			this->btnClose->UseVisualStyleBackColor = true;
			// 
			// CreateChatRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(895, 470);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnConfirm);
			this->Controls->Add(this->chkBoxPrivate);
			this->Controls->Add(this->txtBoxPW);
			this->Controls->Add(this->txtBoxRoomTitle);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"CreateChatRoom";
			this->Text = L"CreateChatRoom";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: void SendMessageForm(int index)
		{

			switch (index)
			{
				case e_room_Create:
				{
					String^ roomType;
					String^ roomTitle = txtBoxRoomTitle->Text; // textBox는 해당 텍스트 상자의 이름입니다.
					String^ roomPW = txtBoxPW->Text; // textBox는 해당 텍스트 상자의 이름입니다.
					if (!chkBoxPrivate->Checked && !String::IsNullOrEmpty(roomPW))
					{
						System::Windows::Forms::MessageBox::Show("Please check the private box", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);

						return;
					}
					if (chkBoxPrivate->Checked && String::IsNullOrEmpty(roomPW))
					{
						System::Windows::Forms::MessageBox::Show("Please enter your password", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}
					if (chkBoxPrivate->Checked)
					{
						roomType = "3";
					}
					else
					{
						roomType = "2";
						roomPW = "0";
					}

					if (!String::IsNullOrEmpty(roomTitle) && !chkBoxPrivate->Checked)
					{
						int t_index = e_room_Create;
						String^ buffer = t_index.ToString() + " " + roomType + " " + roomPW + " " + roomTitle;
						_my->SendMessage(buffer);
					}
					else
					{
						MessageBox::Show("Input RoomTitle", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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
				case e_room_Create:
				{
					if (isTrue == "true")
					{
						System::Windows::Forms::MessageBox::Show("Room Created", "warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else
					{
						System::Windows::Forms::MessageBox::Show("The room title already exists", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
					break;
				}
			}

		}

		private: System::Void btnConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
			btnConfirm->NotifyDefault(false);
			SendMessageForm(e_room_Create);
		}

		private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
		private: System::Void CreateChatRoom_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			this->Owner->Show();
			this->Owner->Activate();
		}
	};
}
