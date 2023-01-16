// RingNr.cpp : implementation file
//
#include "stdafx.h"
#include "8032comm.h"
#include "RingNr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRingNr dialog


CRingNr::CRingNr(CWnd* pParent /*=NULL*/)
	: CDialog(CRingNr::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRingNr)
	m_Combo1 = -1;
	//}}AFX_DATA_INIT
}


void CRingNr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRingNr)
	DDX_CBIndex(pDX, IDC_COMBO1, m_Combo1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRingNr, CDialog)
	//{{AFX_MSG_MAP(CRingNr)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRingNr message handlers
