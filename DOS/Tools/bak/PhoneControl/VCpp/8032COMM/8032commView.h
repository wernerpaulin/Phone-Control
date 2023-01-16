// 8032commView.h : interface of the CMy8032commView class
//
/////////////////////////////////////////////////////////////////////////////

class CMy8032commView : public CView
{
public:
	CWinThread *m_PSerialComm;
protected: // create from serialization only
	CBitmap m_Bitmap1;
	int m_Bitmap1Height;
	int m_Bitmap1Width;
	CBitmap m_Bitmap2;
	int m_Bitmap2Height;
	int m_Bitmap2Width;
	int X,i;
	CMy8032commView();
	DECLARE_DYNCREATE(CMy8032commView)

// Attributes
public:
	CMy8032commDoc* GetDocument();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy8032commView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy8032commView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy8032commView)
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 8032commView.cpp
inline CMy8032commDoc* CMy8032commView::GetDocument()
   { return (CMy8032commDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
