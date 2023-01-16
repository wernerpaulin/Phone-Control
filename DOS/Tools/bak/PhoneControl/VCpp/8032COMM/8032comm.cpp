// 8032comm.cpp : Defines the class behaviors for the application.
// 
 
#include "stdafx.h"
#include "8032comm.h"
#include "iostream.h"
#include "MainFrm.h"
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
#include "ctype.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CMy8032commApp

BEGIN_MESSAGE_MAP(CMy8032commApp, CWinApp)
	//{{AFX_MSG_MAP(CMy8032commApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy8032commApp construction

CMy8032commApp::CMy8032commApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMy8032commApp object

CMy8032commApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMy8032commApp initialization

BOOL CMy8032commApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CMy8032commDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CMy8032commView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

m_pMainWnd->SetWindowText ("Phone - Control");
m_pMainWnd->MoveWindow(210, 114, 600, 261);//Fensterposition und -größe

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CMy8032commApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}



BOOL CMy8032commApp::InitApplication() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CMy8032commApp *ThisApp;
	ThisApp = (CMy8032commApp*)AfxGetApp();
	ThisApp->ThreadRunFlag = FALSE;
	ThisApp->SetupPassed = FALSE;
	ThisApp->PickUpNumberReceived = FALSE;
	ThisApp->TransmittPickUpNumber = FALSE;
	ThisApp->OnChangePhonelineCondition = FALSE;
	ThisApp->OnChangeSafetyCutOff = FALSE;
	ThisApp->OnChangeLastRecCharacter = FALSE;
	ThisApp->OnChangeLastTraCharacter = FALSE;
	ThisApp->OnChangeSpeechRecognition = FALSE;
	ThisApp->OnChangeSpeechProfileID = FALSE;
	ThisApp->SpeechRecognitionActivated = FALSE;
	ThisApp->MonitorActivated = FALSE;
	ThisApp->OnChangeDevice1Condition =FALSE;
	ThisApp->OnChangeDevice2Condition =FALSE;
	ThisApp->OnChangeDevice3Condition =FALSE;
	ThisApp->OnChangeView = FALSE;
	ThisApp->SetupReturnValue = NULL;
	return CWinApp::InitApplication();

}