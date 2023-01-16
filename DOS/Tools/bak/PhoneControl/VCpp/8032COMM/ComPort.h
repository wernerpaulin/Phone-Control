// ComPort.h : header file
//
enum{ComPort1,ComPort2,ComPort3,ComPort4};
/////////////////////////////////////////////////////////////////////////////
// CComPort dialog

class CComPort : public CDialog
{
// Construction
public:
	CComPort(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CComPort)
	enum { IDD = IDD_DIALOG4 };
	int		m_ComPortNr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComPort)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CComPort)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
