#pragma once
#include "MyFunction.h"
#include "enum.h"
#include "AddFriends.h"
#include "FriendsResponse.h"

namespace Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Friends에 대한 요약입니다.
	/// </summary>
	public ref class Friends : public System::Windows::Forms::Form
	{
	public:
		Friends(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

		Friends(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &Friends::ReceivedMsg);
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Friends()
		{
			if (components)
			{
				delete components;
			}
		}
	
	protected:
	private: System::Windows::Forms::ListBox^ listBoxFriends;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::Button^ btnResponse;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnClose;
	private: MyFunction^ _my;
	private:
		AddFriends^ addFriends = nullptr;
		FriendsResponse^ friendResponse = nullptr;
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
			this->listBoxFriends = (gcnew System::Windows::Forms::ListBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnResponse = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24));
			this->label2->ForeColor = System::Drawing::Color::SlateGray;
			this->label2->Location = System::Drawing::Point(31, 52);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(181, 37);
			this->label2->TabIndex = 18;
			this->label2->Text = L"Friend List";
			// 
			// listBoxFriends
			// 
			this->listBoxFriends->FormattingEnabled = true;
			this->listBoxFriends->ItemHeight = 15;
			this->listBoxFriends->Location = System::Drawing::Point(38, 116);
			this->listBoxFriends->Margin = System::Windows::Forms::Padding(2);
			this->listBoxFriends->Name = L"listBoxFriends";
			this->listBoxFriends->Size = System::Drawing::Size(316, 394);
			this->listBoxFriends->TabIndex = 17;
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(408, 128);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(150, 52);
			this->btnAdd->TabIndex = 19;
			this->btnAdd->Text = L"add";
			this->btnAdd->UseVisualStyleBackColor = true;
			// 
			// btnResponse
			// 
			this->btnResponse->Location = System::Drawing::Point(399, 199);
			this->btnResponse->Name = L"btnResponse";
			this->btnResponse->Size = System::Drawing::Size(150, 52);
			this->btnResponse->TabIndex = 19;
			this->btnResponse->Text = L"response";
			this->btnResponse->UseVisualStyleBackColor = true;
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(408, 278);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(150, 52);
			this->btnDelete->TabIndex = 19;
			this->btnDelete->Text = L"delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(408, 421);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(150, 52);
			this->btnClose->TabIndex = 19;
			this->btnClose->Text = L"close";
			this->btnClose->UseVisualStyleBackColor = true;
			// 
			// Friends
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(634, 610);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnResponse);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBoxFriends);
			this->Name = L"Friends";
			this->Text = L"Friends";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: void SendMessageForm(int index, String^ tmptxt_1)
		{

			switch (index)
			{
			case e_friends_Delete:
			{

				int t_index = e_friends_Delete;
				String^ buffer = _my->s_(t_index) + " " + tmptxt_1;
				_my->SendMessage(buffer);

				break;
			}
			}
		}



	private: void UpdateFriendList(String^ message)
	{
		array<String^>^ subString = message->Split(' ');

		for (int i = 2; i < subString->Length; i++)
		{
			listBoxFriends->Items->Add(gcnew String(subString[i]));
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
		case e_friends_List:
		{

			if (isTrue == "true")
			{

				this->Invoke(gcnew Action<String^>(this, &Friends::UpdateFriendList), message);


			}
			else
			{
			}
			break;
		}
		case e_friends_Delete:
		{

			if (isTrue == "true")
			{
				System::Windows::Forms::MessageBox::Show("Friend deleted", "Edit Porofile", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("something wrong..", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			break;



		}


		}

	}

	private: System::Void Friends_Activated(System::Object^ sender, System::EventArgs^ e) {
		listBoxFriends->Items->Clear();
		int t_index = e_friends_List;
		String^ buffer = _my->s_(t_index);
		_my->SendMessage(buffer);
	}
		private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {

			if (addFriends == nullptr || addFriends->IsDisposed) {
				addFriends = gcnew AddFriends(_my);
				addFriends->Owner = this; // Owner를 설정해야 가능
				//this->HomeImageSound->Stop();
				addFriends->Show();
			}


		}
			private: System::Void btnResponse_Click(System::Object^ sender, System::EventArgs^ e) {
				if (friendResponse == nullptr || friendResponse->IsDisposed) {
					friendResponse = gcnew FriendsResponse(_my);
					friendResponse->Owner = this; // Owner를 설정해야 가능
					//this->HomeImageSound->Stop();
					friendResponse->Show();


				}
			}
			private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {

				String^ tmptxt_1;
				if (listBoxFriends->SelectedItem != nullptr)
				{
					tmptxt_1 = listBoxFriends->SelectedItem->ToString();
				}
				else
				{
					System::Windows::Forms::MessageBox::Show("Select ID to delete", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
				MessageBoxButtons buttons = MessageBoxButtons::YesNo;

				// 메시지 박스를 표시하고 사용자의 선택을 저장합니다.
				System::Windows::Forms::DialogResult result = \
					MessageBox::Show("Do you really want to delete friend?", "confirm", buttons);

				// 사용자의 선택에 따라 분기합니다.
				if (result == System::Windows::Forms::DialogResult::Yes)
				{
					btnDelete->NotifyDefault(false);
					SendMessageForm(e_friends_Delete, tmptxt_1);
				}
				else if (result == System::Windows::Forms::DialogResult::No)
				{
					return;
				}
			}

		private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		private: System::Void Friends_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			this->Owner->Show();
			this->Owner->Activate();
		}





	};
}
