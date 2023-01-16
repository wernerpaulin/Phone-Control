; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDeviceNames
LastTemplate=splitter
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "8032comm.h"
LastPage=0

ClassCount=23
Class1=CMy8032commApp
Class2=CMy8032commDoc
Class3=CMy8032commView
Class4=CMainFrame

ResourceCount=17
Resource1=IDD_ABOUTBOX (German (Austria))
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CRingNr
Resource3=IDD_DIALOG1
Resource4=IDD_DIALOG5 (German (Germany))
Resource5=IDD_DIALOG4
Resource6=IDD_DIALOG3
Class7=CDevName
Class8=CDevname
Class9=CDeviceName
Resource7=IDD_DIALOG2 (English (U.S.))
Class10=CDeName
Class11=Ctest
Class12=Ctest1
Class13=CTest
Class14=Ctest3
Class15=Ctest4
Class16=CDia3
Class17=CTest4
Class18=CDeviceNames
Resource8=IDD_DIALOG2
Class19=CSavSett
Resource9=IDD_DIALOG3 (German (Germany))
Class20=CComPort
Resource10=IDD_DIALOG4 (German (Germany))
Resource11=IDD_DIALOG5
Class21=CRecallset
Class22=CMonitor
Resource12=IDD_DIALOG6
Resource13=IDD_ABOUTBOX (English (U.S.))
Resource14=IDD_DIALOG2 (German (Germany))
Resource15=IDR_MAINFRAME (English (U.S.))
Resource16=IDD_DIALOG6 (German (Germany))
Class23=CMyVTProxy
Resource17=IDD_DIALOG1 (English (U.S.))

[CLS:CMy8032commApp]
Type=0
HeaderFile=8032comm.h
ImplementationFile=8032comm.cpp
Filter=N
LastObject=CMy8032commApp
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CMy8032commDoc]
Type=0
HeaderFile=8032commDoc.h
ImplementationFile=8032commDoc.cpp
Filter=N
LastObject=CMy8032commDoc
BaseClass=CDocument
VirtualFilter=DC

[CLS:CMy8032commView]
Type=0
HeaderFile=8032commView.h
ImplementationFile=8032commView.cpp
Filter=W
LastObject=CMy8032commView
BaseClass=CView
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC



[CLS:CAboutDlg]
Type=0
HeaderFile=8032comm.cpp
ImplementationFile=8032comm.cpp
Filter=D
LastObject=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_HARDWARE_SETTINGS
Command2=ID_APP_EXIT
Command3=ID_APP_ABOUT
CommandCount=3

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_EDIT_COPY
Command3=ID_FILE_NEW
Command4=ID_FILE_OPEN
Command5=ID_FILE_SAVE
Command6=ID_HARDWARE_SETTINGS
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_EDIT_CUT
Command15=ID_EDIT_UNDO
CommandCount=15

[DLG:IDD_DIALOG1]
Type=1
Class=CRingNr
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO1,combobox,1342242819

[CLS:CRingNr]
Type=0
HeaderFile=RingNr.h
ImplementationFile=RingNr.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CRingNr

[DLG:IDD_DIALOG1 (English (U.S.))]
Type=1
Class=CRingNr
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_COMBO1,combobox,1342242819
Control4=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_HARDWARE_SETTINGS
Command3=ID_SETTINGS_SOFTWARE
Command4=ID_SETTINGS_SERIALPORT
Command5=ID_SETTINGS_SAVESETTINGS
Command6=ID_SETTINGS_RECALLFACTORY
Command7=ID_SYSTEM_MONITOR
Command8=ID_HELP_TELKEY
Command9=ID_HELP_SOFTWARE
Command10=ID_APP_ABOUT
CommandCount=10

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Command1=ID_SETTINGS_SAVESETTINGS
Command2=ID_APP_EXIT
Command3=ID_SETTINGS_SERIALPORT
Command4=ID_HARDWARE_SETTINGS
Command5=ID_SYSTEM_MONITOR
Command6=ID_SETTINGS_RECALLFACTORY
Command7=ID_SETTINGS_SOFTWARE
Command8=ID_HELP_SOFTWARE
Command9=ID_HELP_TELKEY
CommandCount=9

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342179331
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOG2 (English (U.S.))]
Type=1
Class=CDeviceName
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631556
Control4=IDC_EDIT2,edit,1350631556
Control5=IDC_EDIT3,edit,1350631556

[CLS:CDevName]
Type=0
HeaderFile=DevName.h
ImplementationFile=DevName.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT4

[CLS:CDevname]
Type=0
HeaderFile=Devname.h
ImplementationFile=Devname.cpp
BaseClass=CDialog
Filter=D
LastObject=CDevname

[CLS:CDeviceName]
Type=0
HeaderFile=DeviceName.h
ImplementationFile=DeviceName.cpp
BaseClass=CDialog
Filter=D
LastObject=CDeviceName
VirtualFilter=dWC

[CLS:CDeName]
Type=0
HeaderFile=DeName.h
ImplementationFile=DeName.cpp
BaseClass=CDialog
Filter=D
LastObject=CDeName

[CLS:Ctest]
Type=0
HeaderFile=test.h
ImplementationFile=test.cpp
BaseClass=CDialog
Filter=D
LastObject=Ctest

[CLS:Ctest1]
Type=0
HeaderFile=test1.h
ImplementationFile=test1.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1

[DLG:IDD_ABOUTBOX (German (Austria))]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342179331
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CTest]
Type=0
HeaderFile=Test.h
ImplementationFile=Test.cpp
BaseClass=CDialog
Filter=D
LastObject=CTest

[CLS:Ctest3]
Type=0
HeaderFile=test3.h
ImplementationFile=test3.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1

[CLS:Ctest4]
Type=0
HeaderFile=test4.h
ImplementationFile=test4.cpp
BaseClass=CDialog
Filter=D

[CLS:CDia3]
Type=0
HeaderFile=Dia3.h
ImplementationFile=Dia3.cpp
BaseClass=CDialog
Filter=D
LastObject=CDia3

[CLS:CTest4]
Type=0
HeaderFile=Test4.h
ImplementationFile=Test4.cpp
BaseClass=CDialog
Filter=D
LastObject=CTest4

[DLG:IDD_DIALOG2]
Type=1
Class=CDeviceNames
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_EDIT3,edit,1350631552
Control5=IDCANCEL,button,1342242816

[CLS:CDeviceNames]
Type=0
HeaderFile=DeviceNames.h
ImplementationFile=DeviceNames.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1

[DLG:IDD_DIALOG3]
Type=1
Class=CSavSett
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[CLS:CSavSett]
Type=0
HeaderFile=SavSett.h
ImplementationFile=SavSett.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSavSett

[DLG:IDD_DIALOG4]
Type=1
Class=CComPort
ControlCount=7
Control1=IDC_STATIC,button,1342177287
Control2=IDC_RADIO1,button,1342308361
Control3=IDC_RADIO2,button,1342177289
Control4=IDC_RADIO3,button,1342177289
Control5=IDC_RADIO4,button,1342177289
Control6=IDOK,button,1342242817
Control7=IDCANCEL,button,1342242816

[CLS:CComPort]
Type=0
HeaderFile=ComPort.h
ImplementationFile=ComPort.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_RADIO2

[DLG:IDD_DIALOG5]
Type=1
Class=CRecallset
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308353

[CLS:CRecallset]
Type=0
HeaderFile=Recallset.h
ImplementationFile=Recallset.cpp
BaseClass=CDialog
Filter=D
LastObject=CRecallset

[DLG:IDD_DIALOG6]
Type=1
Class=CMonitor
ControlCount=6
Control1=IDC_TELLINE,button,1342177287
Control2=IDC_SECURE,button,1342177287
Control3=IDC_LASTRECCHAR,button,1342177287
Control4=IDC_LASTTRACHAR,button,1342177287
Control5=IDOK,button,1342242817
Control6=IDC_SPEECHREC,button,1342177287

[CLS:CMonitor]
Type=0
HeaderFile=Monitor.h
ImplementationFile=Monitor.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMonitor

[DLG:IDD_DIALOG6 (German (Germany))]
Type=1
Class=CMonitor
ControlCount=7
Control1=IDC_TELLINE,button,1342177287
Control2=IDC_SECURE,button,1342177287
Control3=IDC_LASTRECCHAR,button,1342177287
Control4=IDC_LASTTRACHAR,button,1342177287
Control5=IDOK,button,1342242817
Control6=IDC_SPEECHREC,button,1342177287
Control7=IDC_SPEECHPROF,button,1342177287

[DLG:IDD_DIALOG2 (German (Germany))]
Type=1
Class=CDeviceName
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_EDIT3,edit,1350631552
Control5=IDCANCEL,button,1342242816

[DLG:IDD_DIALOG3 (German (Germany))]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG4 (German (Germany))]
Type=1
ControlCount=8
Control1=IDC_STATIC,button,1342177287
Control2=IDC_RADIO1,button,1342308361
Control3=IDC_RADIO2,button,1342177289
Control4=IDC_RADIO3,button,1342177289
Control5=IDC_RADIO4,button,1342177289
Control6=IDOK,button,1342242817
Control7=IDCANCEL,button,1342242816
Control8=IDC_STATIC,static,1342308353

[DLG:IDD_DIALOG5 (German (Germany))]
Type=1
Class=CRecallset
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308480

[CLS:CMyVTProxy]
Type=0
HeaderFile=MyVTProxy.h
ImplementationFile=MyVTProxy.cpp
BaseClass=splitter
Filter=T
LastObject=CMyVTProxy

