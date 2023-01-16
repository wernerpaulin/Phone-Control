// DeviceNames.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeviceNames dialog

class CDeviceNames : public CDialog
{
// Construction
public:
	CDeviceNames(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CDeviceNames)
	enum { IDD = IDD_DIALOG2 };
	CEdit	m_Geraet3Edit;
	CEdit	m_Geraet2Edit;
	CEdit	m_Geraet1Edit;
	CString	m_Geraet1;
	CString	m_Geraet2;
	CString	m_Geraet3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeviceNames)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeviceNames)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
