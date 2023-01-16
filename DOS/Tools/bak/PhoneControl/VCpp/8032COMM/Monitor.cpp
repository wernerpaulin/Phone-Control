// Monitor.cpp : implementation file
//

#include "stdafx.h"
#include "8032comm.h"

#include "8032commDoc.h"
#include "8032commView.h"

#include "DeviceNames.h"
#include "RingNr.h"
#include "SavSett.h"
#include "ComPort.h"
#include "Recallset.h"
#include "Monitor.h"

#include "string.h"
#include "stdio.h"
#include "conio.h"
#include "iostream.h"
#include "ctype.h"
#include "afx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMonitor dialog


CMonitor::CMonitor(CWnd* pParent /*=NULL*/)
	: CDialog(CMonitor::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMonitor)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMonitor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMonitor)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMonitor, CDialog)
	//{{AFX_MSG_MAP(CMonitor)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMonitor message handlers

BOOL CMonitor::OnInitDialog() 
{
	CDialog::OnInitDialog();
	ShowWindow(SW_SHOW);
	// TODO: Add extra initialization here
	CMy8032commApp *ThisApp;
	ThisApp = (CMy8032commApp*)AfxGetApp();
	ThisApp->MonitorActivated = TRUE;
	//Initialisierung des Timers für das Monitor - UpDate
	SetTimer(1,1000,NULL); //Timer mit 1s aufgesetzt 

	GetDlgItem (IDC_TELLINE)->GetWindowRect (&m_Telline);	
	ScreenToClient (&m_Telline);
	GetDlgItem (IDC_SECURE)->GetWindowRect (&m_Secure);
	ScreenToClient (&m_Secure);
	GetDlgItem (IDC_LASTRECCHAR)->GetWindowRect (&m_Lastrecchar);
	ScreenToClient (&m_Lastrecchar);
	GetDlgItem (IDC_LASTTRACHAR)->GetWindowRect (&m_Lasttrachar);
	ScreenToClient (&m_Lasttrachar); 
	GetDlgItem (IDC_SPEECHREC)->GetWindowRect (&m_Speechrec);
	ScreenToClient (&m_Speechrec);
	GetDlgItem (IDC_SPEECHPROF)->GetWindowRect (&m_Speechprof);
	ScreenToClient (&m_Speechprof);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMonitor::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	// Do not call CDialog::OnPaint() for painting messages
	
	CMy8032commApp *ThisApp;
	ThisApp = (CMy8032commApp*)AfxGetApp();
	
	int X,Y;
	//Aktualisierung des Telephonline condition - Monitors
	dc.SelectStockObject (ANSI_FIXED_FONT);//Standard - Schriftart
	X = m_Telline.left + 5;
	Y = m_Telline.top +14;
	dc.SetBkMode (TRANSPARENT);
	dc.TextOut (X,Y,ThisApp->PhonelineCondition);
	
	//Aktualisierung des Safety cut off - Monitors
    dc.SelectStockObject (ANSI_FIXED_FONT);//Standard - Schriftart
	X = m_Secure.left + 5;
	Y = m_Secure.top +14;
	dc.SetBkMode (TRANSPARENT);
	dc.TextOut (X,Y,ThisApp->SafetyCutOff);
	
	
	//Aktualisierung des Last received character - Monitors
	dc.SelectStockObject (ANSI_FIXED_FONT);//Standard - Schriftart
	X = m_Lastrecchar.left + 5;
	Y = m_Lastrecchar.top +14;
	dc.SetBkMode (TRANSPARENT);
	dc.TextOut (X,Y,ThisApp->LastRecCharacter);
	
	//Aktualisierung des Last transmitted character - Monitors
	dc.SelectStockObject (ANSI_FIXED_FONT);//Standard - Schriftart
    X = m_Lasttrachar.left + 5;
	Y = m_Lasttrachar.top +14;
	dc.SetBkMode (TRANSPARENT);
	dc.TextOut (X,Y,ThisApp->LastTraCharacter);
	
	//Aktualisierung des Speech recognition - Monitors
	dc.SelectStockObject (ANSI_FIXED_FONT);//Standard - Schriftart
	X = m_Speechrec.left + 5;
	Y = m_Speechrec.top +14;
	dc.SetBkMode (TRANSPARENT);
	dc.TextOut (X,Y,ThisApp->SpeechRecognition);
	
	//Aktualisierung des Speech profil identification - Monitors
	dc.SelectStockObject (ANSI_FIXED_FONT);//Standard - Schriftart
	X = m_Speechprof.left + 5;
	Y = m_Speechprof.top +14;
	dc.SetBkMode (TRANSPARENT);
	dc.TextOut (X,Y,ThisApp->SpeechProfileID);
}


void CMonitor::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CMy8032commApp *ThisApp;
	ThisApp = (CMy8032commApp*)AfxGetApp();
	
	if (ThisApp->OnChangePhonelineCondition)
		{InvalidateRect(&m_Telline,TRUE); //Monitor - Dialog - Fenster wird ungültig gemacht
		 ThisApp->OnChangePhonelineCondition = FALSE;
		 UpdateWindow();
		}
	
	if (ThisApp->OnChangeSafetyCutOff)
		{InvalidateRect(&m_Secure,TRUE); //Monitor - Dialog - Fenster wird ungültig gemacht
		 ThisApp->OnChangeSafetyCutOff = FALSE;
		 UpdateWindow();
		}
	
	if (ThisApp->OnChangeLastRecCharacter)
		{InvalidateRect(&m_Lastrecchar,TRUE); //Monitor - Dialog - Fenster wird ungültig gemacht
		 ThisApp->OnChangeLastRecCharacter = FALSE;
		 UpdateWindow();
		}
	
	if (ThisApp->OnChangeLastTraCharacter);
		{InvalidateRect(&m_Lasttrachar,TRUE); //Monitor - Dialog - Fenster wird ungültig gemacht
		 ThisApp->OnChangeLastTraCharacter = FALSE;	
		 UpdateWindow();
		}
	
	if (ThisApp->OnChangeSpeechRecognition);
		{InvalidateRect(&m_Speechrec,TRUE); //Monitor - Dialog - Fenster wird ungültig gemacht
		 ThisApp->OnChangeSpeechRecognition = FALSE;
		 UpdateWindow();
		}

	if (ThisApp->OnChangeSpeechProfileID)
		{InvalidateRect(&m_Speechprof,TRUE); //Monitor - Dialog - Fenster wird ungültig gemacht
		 ThisApp->OnChangeSpeechProfileID = FALSE;
		 UpdateWindow();
		} 
	
	CDialog::OnTimer(nIDEvent);
}

void CMonitor::OnOK() 
{
	// TODO: Add extra validation here
	KillTimer(1);
	CMy8032commApp *ThisApp;
	ThisApp = (CMy8032commApp*)AfxGetApp();
	ThisApp->MonitorActivated = FALSE;
	DestroyWindow();
	//CDialog::OnOK();
}


void CMonitor::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);
	CMy8032commApp *ThisApp;
	ThisApp = (CMy8032commApp*)AfxGetApp();
	ThisApp->MonitorActivated = FALSE;
	DestroyWindow();
	//CDialog::OnClose();
}

