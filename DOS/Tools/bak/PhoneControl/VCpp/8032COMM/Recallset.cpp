// Recallset.cpp : implementation file
//

#include "stdafx.h"
#include "8032comm.h"
#include "Recallset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecallset dialog


CRecallset::CRecallset(CWnd* pParent /*=NULL*/)
	: CDialog(CRecallset::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRecallset)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRecallset::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRecallset)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRecallset, CDialog)
	//{{AFX_MSG_MAP(CRecallset)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecallset message handlers
