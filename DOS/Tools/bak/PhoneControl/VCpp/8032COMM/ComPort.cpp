// ComPort.cpp : implementation file
//

#include "stdafx.h"
#include "8032comm.h"
#include "ComPort.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CComPort dialog


CComPort::CComPort(CWnd* pParent /*=NULL*/)
	: CDialog(CComPort::IDD, pParent)
{
	//{{AFX_DATA_INIT(CComPort)
	m_ComPortNr = -1;
	//}}AFX_DATA_INIT
}


void CComPort::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComPort)
	DDX_Radio(pDX, IDC_RADIO1, m_ComPortNr);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CComPort, CDialog)
	//{{AFX_MSG_MAP(CComPort)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComPort message handlers
