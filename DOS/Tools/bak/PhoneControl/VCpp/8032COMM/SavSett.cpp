// SavSett.cpp : implementation file
//

#include "stdafx.h"
#include "8032comm.h"
#include "SavSett.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSavSett dialog


CSavSett::CSavSett(CWnd* pParent /*=NULL*/)
	: CDialog(CSavSett::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSavSett)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSavSett::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSavSett)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSavSett, CDialog)
	//{{AFX_MSG_MAP(CSavSett)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSavSett message handlers