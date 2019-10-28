//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    char SendDate[100]; //한글 50자 알파벳 100자
    memset(SendDate,0x00,100); // 주기억장치 0으로 셋 , 0x00=널=공백
                                //senddate 크기만큼 0x00을 채워준다

    Memo1->Lines->Add("세영 : "+Edit1->Text); // "세영 :" 입력 을 메모1라인에 추가
    Edit1->Text="세영 : "+Edit1->Text;
    memcpy(SendDate,Edit1->Text.c_str(),strlen(Edit1->Text.c_str()));

    NMUDP1->SendBuffer(SendDate,sizeof(SendDate),strlen(Edit1->Text.c_str()));
    //nmudp sendbuffer는 메세지를 보낸다. sizeof=크기 strlen=길이
    Edit1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NMUDP1DataReceived(TComponent *Sender,
      int NumberBytes, AnsiString FromIP, int Port)
{
    char Buff[100];
    int i;
    memset (Buff,0x00,100);
    NMUDP1->ReadBuffer(Buff,NumberBytes,i);
    //NMUDP1 ReadBuffer는 메세지를 받는다.  크기 길이
    Memo1->Lines->Add(Buff);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Shift.Empty() == true && Key == VK_RETURN)
    {
        Button1->Click();
    }
}
//---------------------------------------------------------------------------

