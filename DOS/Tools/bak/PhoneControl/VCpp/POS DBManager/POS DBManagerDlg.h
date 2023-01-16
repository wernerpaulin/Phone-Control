// POS DBManagerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPOSDBManagerDlg dialog
#include "afxdb.h"

class CPOSDBManagerDlg : public CDialog
{
// Construction
public:
	CPOSDBManagerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPOSDBManagerDlg)
	enum { IDD = IDD_POSDBMANAGER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPOSDBManagerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

  CPosRunDb m_PosRun;                             //Objekt für Datenbank-Zugriff anlegen
  BOOL entryFound;                                //Flag für gefundenen Datensatz
  CString strDlgTime;                             //Objekt für Zeit Konvertierung

  //Variablen für Dialog-Box
  long dbResult;                                  //Variable für EDIT-Box
  
	CString	dlgLast_Name;
	CString dlgGiven_Name;
  long	dlgPIN;
	CString	dlgSpeech_Profile;
	CTime	dlgLast_Access_Time;
	long	dlgNumber_of_Access;
	long	dlgUser_Access_Level;
	CString strSQL;     
  char resChars[10];

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPOSDBManagerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDoquery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
