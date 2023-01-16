; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPosRunDb
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "POS DBManager.h"

ClassCount=4
Class1=CPOSDBManagerApp
Class2=CPOSDBManagerDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_POSDBMANAGER_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Class4=CPosRunDb
Resource5=IDD_POSDBMANAGER_DIALOG (English (U.S.))

[CLS:CPOSDBManagerApp]
Type=0
HeaderFile=POS DBManager.h
ImplementationFile=POS DBManager.cpp
Filter=N

[CLS:CPOSDBManagerDlg]
Type=0
HeaderFile=POS DBManagerDlg.h
ImplementationFile=POS DBManagerDlg.cpp
Filter=D
LastObject=IDC_DBRESULT
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=POS DBManagerDlg.h
ImplementationFile=POS DBManagerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[DLG:IDD_POSDBMANAGER_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CPOSDBManagerDlg

[DLG:IDD_POSDBMANAGER_DIALOG (English (U.S.))]
Type=1
Class=CPOSDBManagerDlg
ControlCount=19
Control1=IDC_DBRESULT,edit,1350631552
Control2=IDC_DOQUERY,button,1342242817
Control3=IDOK,button,1342242816
Control4=IDCANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_LASTNAME,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_GIVENNAME,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_SPEECHPROFILE,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_LACCESSTIME,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_NBACCESS,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_UACCESSLEVEL,edit,1350631552
Control17=IDC_STATIC,static,1342308352
Control18=IDC_PIN,edit,1350631552
Control19=IDC_STATIC,static,1342308352

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CPosRunDb]
Type=0
HeaderFile=PosRunDb.h
ImplementationFile=PosRunDb.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CPosRunDb

[DB:CPosRunDb]
DB=1
DBType=ODBC
ColumnCount=7
Column1=[Last Name], 12, 50
Column2=[Given Name], 12, 50
Column3=[PIN], 4, 4
Column4=[Speech Profile], 12, 50
Column5=[Last Access Time], 11, 16
Column6=[Number of Access], 4, 4
Column7=[User Access Level], 4, 4

