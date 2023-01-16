// DeviceNames.cpp : implementation file
//

#include "stdafx.h"
#include "8032comm.h"
#include "DeviceNames.h"
#include "8032commDoc.h"

#include "RingNr.h"
#include "SavSett.h"

#include "string.h"
#include "stdio.h"
#include "conio.h"
#include "iostream.h"
#include "ctype.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeviceNames dialog


CDeviceNames::CDeviceNames(CWnd* pParent /*=NULL*/)
	: CDialog(CDeviceNames::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeviceNames)
	m_Geraet1 = _T("");
	m_Geraet2 = _T("");
	m_Geraet3 = _T("");
	//}}AFX_DATA_INIT
}


void CDeviceNames::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeviceNames)
	DDX_Control(pDX, IDC_EDIT3, m_Geraet3Edit);
	DDX_Control(pDX, IDC_EDIT2, m_Geraet2Edit);
	DDX_Control(pDX, IDC_EDIT1, m_Geraet1Edit);
	DDX_Text(pDX, IDC_EDIT1, m_Geraet1);
	DDV_MaxChars(pDX, m_Geraet1, 16);
	DDX_Text(pDX, IDC_EDIT2, m_Geraet2);
	DDV_MaxChars(pDX, m_Geraet2, 16);
	DDX_Text(pDX, IDC_EDIT3, m_Geraet3);
	DDV_MaxChars(pDX, m_Geraet3, 16);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeviceNames, CDialog)
	//{{AFX_MSG_MAP(CDeviceNames)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeviceNames message handlers

BOOL CDeviceNames::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
m_Geraet1Edit.LimitText(15);
m_Geraet2Edit.LimitText(15);
m_Geraet3Edit.LimitText(15);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}