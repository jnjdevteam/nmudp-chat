object Form1: TForm1
  Left = 192
  Top = 124
  Width = 356
  Height = 232
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object Edit1: TEdit
    Left = 64
    Top = 120
    Width = 121
    Height = 21
    ImeName = 'Microsoft Office IME 2007'
    TabOrder = 0
    Text = 'Edit1'
  end
  object Button1: TButton
    Left = 208
    Top = 120
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 64
    Top = 8
    Width = 185
    Height = 89
    ImeName = 'Microsoft Office IME 2007'
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object Edit2: TEdit
    Left = 64
    Top = 152
    Width = 121
    Height = 21
    ImeName = 'Microsoft Office IME 2007'
    TabOrder = 3
    Text = 'Edit2'
  end
  object NMUDP1: TNMUDP
    RemoteHost = '192.168.1.101'
    RemotePort = 2000
    LocalPort = 1000
    ReportLevel = 1
    OnDataReceived = NMUDP1DataReceived
    Left = 256
    Top = 8
  end
end
