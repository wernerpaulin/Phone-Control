// Monitor.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMonitor dialog

class CMonitor : public CDialog
{
public:
	RECT m_Telline;
	RECT m_Secure;
	RECT m_Lastrecchar;
	RECT m_Lasttrachar;
	RECT m_Speechrec;
	RECT m_Speechprof;
// Construction
public:
	CMonitor(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMonitor)
	enum { IDD = IDD_DIALOG6 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMonitor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMonitor)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual void OnOK();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
