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
    char SendDate[100]; //�ѱ� 50�� ���ĺ� 100��
    memset(SendDate,0x00,100); // �ֱ����ġ 0���� �� , 0x00=��=����
                                //senddate ũ�⸸ŭ 0x00�� ä���ش�

    Memo1->Lines->Add("���� : "+Edit1->Text); // "���� :" �Է� �� �޸�1���ο� �߰�
    Edit1->Text="���� : "+Edit1->Text;
    memcpy(SendDate,Edit1->Text.c_str(),strlen(Edit1->Text.c_str()));

    NMUDP1->SendBuffer(SendDate,sizeof(SendDate),strlen(Edit1->Text.c_str()));
    //nmudp sendbuffer�� �޼����� ������. sizeof=ũ�� strlen=����
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
    //NMUDP1 ReadBuffer�� �޼����� �޴´�.  ũ�� ����
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

