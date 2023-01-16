// 8032commDoc.h : interface of the CMy8032commDoc class
//
/////////////////////////////////////////////////////////////////////////////
class CMy8032commDoc : public CDocument
{
public:
int m_Combo1;  // Definition der Combo - Box - Variable m_Combo1
char m_Geraet1[16]; // Definition der Edit - Box 1 - Variable m_Geraet1
char m_Geraet2[16]; // Definition der Edit - Box 2 - Variable m_Geraet2
char m_Geraet3[16]; // Definition der Edit - Box 3 - Variable m_Geraet3
char Dateiname[20];
int m_ComPortNr;
struct SETUPFELD			// Record - Definition für Setupinhalte
	{int m_Combo1SET;
	 int m_ComPortNrSET;
	 char m_Geraet1SET[16];
	 char m_Geraet2SET[16];
	 char m_Geraet3SET[16];
    };
SETUPFELD SETUPDATEN;
protected: // create from serialization only
	CMy8032commDoc();
	DECLARE_DYNCREATE(CMy8032commDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy8032commDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy8032commDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy8032commDoc)
	afx_msg void OnHardwareSettings();
	afx_msg void OnSettingsSoftware();
	afx_msg void OnSettingsSavesettings();
	afx_msg void OnSettingsSerialport();
	afx_msg void OnSettingsRecallfactory();
	afx_msg void OnSystemMonitor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
