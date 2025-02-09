; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAaaDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "aaa.h"

ClassCount=3
Class1=CAaaApp
Class2=CAaaDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_AAA_DIALOG

[CLS:CAaaApp]
Type=0
HeaderFile=aaa.h
ImplementationFile=aaa.cpp
Filter=N

[CLS:CAaaDlg]
Type=0
HeaderFile=aaaDlg.h
ImplementationFile=aaaDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=aaaDlg.h
ImplementationFile=aaaDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_AAA_DIALOG]
Type=1
Class=CAaaDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_LIST1,listbox,1352728833
Control5=IDC_BUTTON1,button,1342242816

