// RingNr.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRingNr dialog

class CRingNr : public CDialog
{
// Construction
public:
	CRingNr(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRingNr)
	enum { IDD = IDD_DIALOG1 };
	int		m_Combo1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRingNr)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRingNr)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
