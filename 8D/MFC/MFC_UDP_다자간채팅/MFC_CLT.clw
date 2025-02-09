; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMFC_CLTDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MFC_CLT.h"

ClassCount=3
Class1=CMFC_CLTApp
Class2=CMFC_CLTDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MFC_CLT_DIALOG

[CLS:CMFC_CLTApp]
Type=0
HeaderFile=MFC_CLT.h
ImplementationFile=MFC_CLT.cpp
Filter=N

[CLS:CMFC_CLTDlg]
Type=0
HeaderFile=MFC_CLTDlg.h
ImplementationFile=MFC_CLTDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CAboutDlg]
Type=0
HeaderFile=MFC_CLTDlg.h
ImplementationFile=MFC_CLTDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MFC_CLT_DIALOG]
Type=1
Class=CMFC_CLTDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,listbox,1352728833
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_BUTTON1,button,1342242816

