// 8032comm.h : main header file for the 8032COMM application
//

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy8032commApp:
// See 8032comm.cpp for the implementation of this class
//

class CMy8032commApp : public CWinApp
{
public:
	CMy8032commApp();
	UINT SerialCommunication (LPVOID m_hWnd); //Prototyp der Funktion
	BOOL SetupConnection ();				  //Prototyp der Funktion
	BOOL ThreadRunFlag; //Wird nur bei Programmstart gesetzt
	BOOL SetupPassed;
	BOOL TransmittPickUpNumber;
	char COMPortNr[11];
	int PickUpNumber;
	BOOL PickUpNumberReceived;
	//MonitorVariablen
	char PhonelineCondition[17];
	BOOL OnChangePhonelineCondition;
	char SafetyCutOff[17];
	BOOL OnChangeSafetyCutOff;
	char LastRecCharacter[17];
	BOOL OnChangeLastRecCharacter;
	char LastTraCharacter[17];
	BOOL OnChangeLastTraCharacter;
	char SpeechRecognition[17];
	BOOL OnChangeSpeechRecognition;
	char SpeechProfileID[17];
	BOOL OnChangeSpeechProfileID;
	BOOL SpeechRecognitionActivated;
	char m_Geraet1View[16];
	char m_Geraet2View[16];
	char m_Geraet3View[16];
	char SpeechRecognitionView[17];
	BOOL Device1ON;
	BOOL Device2ON;
	BOOL Device3ON;
	BOOL MonitorActivated;
	BOOL OnChangeDevice1Condition;
	BOOL OnChangeDevice2Condition;
	BOOL OnChangeDevice3Condition;
	BOOL OnChangeView;
	BOOL SetupReturnValue;
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy8032commApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL InitApplication();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy8032commApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
