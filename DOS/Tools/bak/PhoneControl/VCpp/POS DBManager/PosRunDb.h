// PosRunDb.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPosRunDb recordset

class CPosRunDb : public CRecordset
{
public:
	CPosRunDb(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPosRunDb)

// Field/Param Data
	//{{AFX_FIELD(CPosRunDb, CRecordset)
	CString	m_Last_Name;
	CString	m_Given_Name;
	long	m_PIN;
	CString	m_Speech_Profile;
	CTime	m_Last_Access_Time;
	long	m_Number_of_Access;
	long	m_User_Access_Level;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPosRunDb)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};
