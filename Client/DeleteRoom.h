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
	/// DeleteRoom에 대한 요약입니다.
	/// </summary>
	public ref class DeleteRoom : public System::Windows::Forms::Form
	{
	public:
		DeleteRoom(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
		DeleteRoom(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &DeleteRoom::ReceivedMsg);
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~DeleteRoom()
		{
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &DeleteRoom::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ ViewRoomList;
	protected:

	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RoomIndex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RoomName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RoomTitle;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PrivateCheck;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CreatedDate;
	private: System::Windows::Forms::Button^ btnDelete;
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
			this->ViewRoomList = (gcnew System::Windows::Forms::DataGridView());
			this->RoomIndex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RoomName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RoomTitle = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PrivateCheck = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CreatedDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewRoomList))->BeginInit();
			this->SuspendLayout();
			// 
			// ViewRoomList
			// 
			this->ViewRoomList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ViewRoomList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->RoomIndex,
					this->RoomName, this->RoomTitle, this->PrivateCheck, this->CreatedDate
			});
			this->ViewRoomList->Location = System::Drawing::Point(83, 76);
			this->ViewRoomList->Name = L"ViewRoomList";
			this->ViewRoomList->RowTemplate->Height = 27;
			this->ViewRoomList->Size = System::Drawing::Size(575, 353);
			this->ViewRoomList->TabIndex = 0;
			// 
			// RoomIndex
			// 
			this->RoomIndex->HeaderText = L"#Index";
			this->RoomIndex->Name = L"RoomIndex";
			// 
			// RoomName
			// 
			this->RoomName->HeaderText = L"Name";
			this->RoomName->Name = L"RoomName";
			// 
			// RoomTitle
			// 
			this->RoomTitle->HeaderText = L"Title";
			this->RoomTitle->Name = L"RoomTitle";
			// 
			// PrivateCheck
			// 
			this->PrivateCheck->HeaderText = L"Private";
			this->PrivateCheck->Name = L"PrivateCheck";
			// 
			// CreatedDate
			// 
			this->CreatedDate->HeaderText = L"CreatedDate";
			this->CreatedDate->Name = L"CreatedDate";
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(714, 125);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(101, 50);
			this->btnDelete->TabIndex = 1;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(714, 295);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(101, 50);
			this->btnClose->TabIndex = 1;
			this->btnClose->Text = L"Close";
			this->btnClose->UseVisualStyleBackColor = true;
			// 
			// DeleteRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(952, 565);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->ViewRoomList);
			this->Name = L"DeleteRoom";
			this->Text = L"DeleteRoom";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewRoomList))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

			public: void SendMessageForm(int index)
			{

				switch (index)
				{
				case e_room_Delete:
				{

					MessageBoxButtons buttons = MessageBoxButtons::YesNo;

					// 메시지 박스를 표시하고 사용자의 선택을 저장합니다.
					System::Windows::Forms::DialogResult result = \
						MessageBox::Show("Do you really want to delete this room?", "confirm", buttons);

					// 사용자의 선택에 따라 분기합니다.
					if (result == System::Windows::Forms::DialogResult::Yes)
					{
					}
					else if (result == System::Windows::Forms::DialogResult::No)
					{
						return;
					}



					int selectedRowIndex = ViewRoomList->SelectedRows[0]->Index;

					System::Object^ column1ValueObj = ViewRoomList->Rows[selectedRowIndex]->Cells["RoomIndex"]->Value;
					System::String^ tmptxt_1;
					// null 체크
					if (column1ValueObj != nullptr)
					{
						System::String^ column1Value = column1ValueObj->ToString();
						tmptxt_1 = column1Value;
					}
					else
					{
						ViewRoomList->Rows->Clear();
						return;
					}

					int t_index = e_room_Delete;
					String^ buffer = _my->s_(t_index) + " " + tmptxt_1;
					_my->SendMessage(buffer);
					break;
				}
				case e_room_myList:
				{
					int t_index = e_room_myList;
					String^ buffer = _my->s_(t_index);
					_my->SendMessage(buffer);

					break;
				}

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
				case e_room_Delete:
				{

					if (isTrue == "true")
					{

						System::Windows::Forms::MessageBox::Show("Room deleted", "Notice", MessageBoxButtons::OK, MessageBoxIcon::Information);
					}
					else
					{
						System::Windows::Forms::MessageBox::Show("Failed", "Notice", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
					break;
				}

				case e_room_myList:
				{

					this->Invoke(gcnew Action<String^>(this, &DeleteRoom::UpdateRoomList), message);
					break;
				}

				}


			}
			private: void UpdateRoomList(String^ message) {

				ViewRoomList->Rows->Clear();

				String^ inputString = message;

				array<String^>^ subString = inputString->Split(' ');

				String^ index_s = subString[0];
				String^ isTrue = subString[1];

				if (isTrue == "false")
				{
					return;
				}

				// 17*/2*/welcome my home*/20211012 3033\n

				array<String^>^ roomInfo = message->Split('\n');
				int rowNum = 0;
				array<String^>^ separators = gcnew array<String^> { "*/" };

				for (int i = 1; i < roomInfo->Length;i++)
				{
					//array<String^>^ myString = roomInfo[i]->Split('*/');
					array<String^>^ myString = roomInfo[i]->Split(separators, StringSplitOptions::None);
					ViewRoomList->Rows->Add();
					ViewRoomList->Rows[rowNum]->Cells["RoomIndex"]->Value = myString[0];


					if (myString[1] == "2")
					{
						ViewRoomList->Rows[rowNum]->Cells["PrivateCheck"]->Value = "Public";
					}
					else
					{
						ViewRoomList->Rows[rowNum]->Cells["PrivateCheck"]->Value = "Private";
					}

					ViewRoomList->Rows[rowNum]->Cells["RoomName"]->Value = myString[2];


					ViewRoomList->Rows[rowNum]->Cells["CreatedDate"]->Value = myString[3];

					rowNum++;
				}


			}


			private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
				btnDelete->NotifyDefault(false);
				SendMessageForm(e_room_Delete);
			}

			private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
				this->Close();
			}

			private: System::Void DeleteRoom_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
				this->Owner->Show();
				this->Owner->Activate();

			}

			private: System::Void DeleteRoom_Activated(System::Object^ sender, System::EventArgs^ e) {

				SendMessageForm(e_room_myList);

			}



	};
}
