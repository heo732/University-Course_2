object FormMain: TFormMain
  Left = 341
  Top = 144
  Width = 747
  Height = 474
  Caption = #1055#1072#1088#1072#1083#1077#1083#1086#1075#1088#1072#1084
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Verdana'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 16
  object Image: TImage
    Left = 304
    Top = 8
    Width = 417
    Height = 417
  end
  object ImageColor: TImage
    Left = 88
    Top = 296
    Width = 33
    Height = 33
    OnClick = ImageColorClick
  end
  object Label1: TLabel
    Left = 8
    Top = 120
    Width = 56
    Height = 16
    Caption = #1054#1089#1085#1086#1074#1072':'
  end
  object Label4: TLabel
    Left = 8
    Top = 296
    Width = 41
    Height = 16
    Caption = #1050#1086#1083#1110#1088':'
  end
  object Label5: TLabel
    Left = 8
    Top = 368
    Width = 71
    Height = 16
    Caption = #1055#1077#1088#1080#1084#1077#1090#1088':'
  end
  object Label6: TLabel
    Left = 8
    Top = 400
    Width = 51
    Height = 16
    Caption = #1055#1083#1086#1097#1072':'
  end
  object LabelPerimeter: TLabel
    Left = 88
    Top = 368
    Width = 5
    Height = 16
  end
  object LabelArea: TLabel
    Left = 72
    Top = 400
    Width = 5
    Height = 16
  end
  object EditBase: TEdit
    Left = 144
    Top = 120
    Width = 73
    Height = 24
    TabOrder = 0
    Text = '200'
  end
  object EditHeight: TEdit
    Left = 224
    Top = 184
    Width = 73
    Height = 24
    TabOrder = 1
    Text = '70'
  end
  object EditSide: TEdit
    Left = 224
    Top = 216
    Width = 73
    Height = 24
    TabOrder = 2
    Text = '80'
  end
  object ButtonDraw: TButton
    Left = 8
    Top = 32
    Width = 289
    Height = 57
    Caption = #1053#1072#1088#1080#1089#1091#1074#1072#1090#1080
    TabOrder = 3
    OnClick = ButtonDrawClick
  end
  object RadioGroupLocks: TRadioGroup
    Left = 8
    Top = 168
    Width = 209
    Height = 105
    Caption = #1052#1086#1078#1077' '#1079#1084#1110#1085#1102#1074#1072#1090#1080#1089#1103
    ItemIndex = 2
    Items.Strings = (
      #1042#1080#1089#1086#1090#1072
      #1041#1110#1095#1085#1072
      #1050#1091#1090' '#1084#1110#1078' '#1086#1089#1085#1086#1074#1086#1102' '#1110' '#1073#1110#1095#1085#1086#1102)
    TabOrder = 4
  end
  object EditAlpha: TEdit
    Left = 224
    Top = 248
    Width = 73
    Height = 24
    TabOrder = 5
    Text = '150'
  end
  object ColorDialog: TColorDialog
    Ctl3D = True
  end
end
