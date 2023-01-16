// POS DBManagerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PosRunDb.h"
#include "POS DBManager.h"
#include "POS DBManagerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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

/////////////////////////////////////////////////////////////////////////////
// CPOSDBManagerDlg dialog

CPOSDBManagerDlg::CPOSDBManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPOSDBManagerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPOSDBManagerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPOSDBManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPOSDBManagerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
  
  //Datenaustausch mit Dialogbox
  DDX_Text( pDX, IDC_DBRESULT , dbResult  );

  DDX_Text( pDX, IDC_LASTNAME, dlgLast_Name  );
  DDX_Text( pDX, IDC_GIVENNAME, dlgGiven_Name  );
  DDX_Text( pDX, IDC_PIN, dlgPIN  );
  DDX_Text( pDX, IDC_SPEECHPROFILE, dlgSpeech_Profile  );
  DDX_Text( pDX, IDC_LACCESSTIME, strDlgTime  );

  DDX_Text( pDX, IDC_NBACCESS, dlgNumber_of_Access  );
  DDX_Text( pDX, IDC_UACCESSLEVEL, dlgUser_Access_Level  );

}

BEGIN_MESSAGE_MAP(CPOSDBManagerDlg, CDialog)
	//{{AFX_MSG_MAP(CPOSDBManagerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DOQUERY, OnDoquery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPOSDBManagerDlg message handlers

BOOL CPOSDBManagerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	CString strAboutMenu;
	strAboutMenu.LoadString(IDS_ABOUTBOX);
	if (!strAboutMenu.IsEmpty())
	{
		pSysMenu->AppendMenu(MF_SEPARATOR);
		pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
  dbResult = 0;                     //Edit-box initialisieren
  dlgLast_Name = "";
  dlgGiven_Name = "";
  dlgPIN = 0;
  dlgSpeech_Profile = "";
  dlgLast_Access_Time = 0;
  strDlgTime = "";
   
  dlgNumber_of_Access = 0;
 	dlgUser_Access_Level = 0;

  UpdateData(FALSE);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPOSDBManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPOSDBManagerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPOSDBManagerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPOSDBManagerDlg::OnDoquery() 
{
 if (m_PosRun.IsOpen())                    //Datenbank-Objekt schliessen falls geöffnet
   m_PosRun.Close();

 
 //Beispiel: Ändern eines Datenbank-Eintrags...
 /*
 UpdateData(TRUE);                    //Edit-Box einlesen

 m_PosRun.Open( CPosRunDb::dynaset, NULL, CPosRunDb::none );
 m_PosRun.MoveFirst();
 m_PosRun.Edit();
 m_PosRun.m_PIN = dbResult;
 m_PosRun.Update();
 */
 
 /*
 //Beispiel: Lesen eines Datenbank-Eintrags...
 m_PosRun.Open( CPosRunDb::dynaset, NULL, CPosRunDb::none );
 m_PosRun.MoveFirst();
 dbResult = m_PosRun.m_PIN;
 UpdateData(FALSE);
 */

 
 //Suchen eines Datenbankeintrags
 UpdateData(TRUE);                    //Edit-Box einlesen
 
 entryFound = 0;                      //Flag zurücksetzen
 
 //PENDENZ: OPEN() mit SQL-String der dynamisch zusammen gebaut wird aufrufen
 //         Den SQL-String erhält man aus MS Access...
 //         "SELECT TPosUserInfo.[Last Name],TPosUserInfo.[Given Name],TPosUserInfo.PIN,TPosUserInfo.[Speech Profile],TPosUserInfo.[Last Access Time],TPosUserInfo.[Number of Access],TPosUserInfo.[User Access Level] FROM TPosUserInfo WHERE ( ((TPosUserInfo.PIN) =1313) )",
 //               "SELECT TPosUserInfo.[Last Name] FROM TPosUserInfo",
 //               "SELECT * FROM TPosUserInfo",  //alle Elemente...

 
 strSQL = "SELECT * FROM TPosUserInfo WHERE ( ((TPosUserInfo.PIN) = "; //xxxx) )";
 _ltoa( dbResult, resChars, 10 );           //ASCII-Wandlung

 strSQL += resChars;
 strSQL += ") )";

 m_PosRun.Open( CPosRunDb::dynaset, 
                strSQL,
                CPosRunDb::none );        //Kanal zur Datenbank öffnen
 


 //m_PosRun.Open( CRecordset::snapshot, NULL, CRecordset::readOnly );

 
 if (!m_PosRun.IsEOF())
   {
    m_PosRun.MoveFirst();
    dlgLast_Name = m_PosRun.m_Last_Name;
	  dlgGiven_Name = m_PosRun.m_Given_Name;
	  dlgPIN = m_PosRun.m_PIN;
	  dlgSpeech_Profile = m_PosRun.m_Speech_Profile;
    dlgLast_Access_Time = m_PosRun.m_Last_Access_Time;

    //ACHTUNG: Die Zeit muss wie folgt in der Datenbank abgelegt sein: >16.11.98 10:45:00<
    //         Ansonsten schlägt der FORMAT-Befehl fehl, da WINDOWS die Zeit mittels vergangener
    //         Sekunden seit 1978 berrechnet !!!
    strDlgTime = dlgLast_Access_Time.Format( "%H:%M:%S" );
      
    dlgNumber_of_Access = m_PosRun.m_Number_of_Access;
    dlgUser_Access_Level = m_PosRun.m_User_Access_Level;
 
    UpdateData(FALSE);
   }
 else
   AfxMessageBox( "keinen Eintrag gefunden !!!", MB_OK | MB_ICONEXCLAMATION, 0 );

 /*
 m_PosRun.Open( CPosRunDb::dynaset, NULL, CPosRunDb::none );        //Kanal zur Datenbank öffnen
 m_PosRun.MoveFirst();

 while ( (!m_PosRun.IsEOF()) && (entryFound == 0) )
   {
    if (m_PosRun.m_PIN == dbResult)
      entryFound = 1;
    else
      m_PosRun.MoveNext();

   }
 
 if (entryFound)
   {
    //AfxMessageBox( "Eintrag gefunden !!!", MB_OK | MB_ICONEXCLAMATION, 0 );
    dlgLast_Name = m_PosRun.m_Last_Name;
	  dlgGiven_Name = m_PosRun.m_Given_Name;
	  dlgPIN = m_PosRun.m_PIN;
	  dlgSpeech_Profile = m_PosRun.m_Speech_Profile;
    dlgLast_Access_Time = m_PosRun.m_Last_Access_Time;

    //ACHTUNG: Die Zeit muss wie folgt in der Datenbank abgelegt sein: >16.11.98 10:45:00<
    //         Ansonsten schlägt der FORMAT-Befehl fehl, da WINDOWS die Zeit mittels vergangener
    //         Sekunden seit 1978 berrechnet !!!
    strDlgTime = dlgLast_Access_Time.Format( "%H:%M:%S" );
       
    dlgNumber_of_Access = m_PosRun.m_Number_of_Access;
  	dlgUser_Access_Level = m_PosRun.m_User_Access_Level;

    UpdateData(FALSE);
   }
 else
   AfxMessageBox( "keinen Eintrag gefunden !!!", MB_OK | MB_ICONEXCLAMATION, 0 );
 
*/	
}
