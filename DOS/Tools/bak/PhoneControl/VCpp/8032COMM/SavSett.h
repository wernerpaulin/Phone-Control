// SavSett.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSavSett dialog

class CSavSett : public CDialog
{
// Construction
public:
	CSavSett(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSavSett)
	enum { IDD = IDD_DIALOG3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSavSett)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSavSett)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
