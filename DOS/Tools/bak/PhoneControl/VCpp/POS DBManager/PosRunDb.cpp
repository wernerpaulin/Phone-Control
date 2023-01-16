// PosRunDb.cpp : implementation file
//

#include "stdafx.h"
#include "POS DBManager.h"
#include "PosRunDb.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPosRunDb

IMPLEMENT_DYNAMIC(CPosRunDb, CRecordset)

CPosRunDb::CPosRunDb(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPosRunDb)
	m_Last_Name = _T("");
	m_Given_Name = _T("");
	m_PIN = 0;
	m_Speech_Profile = _T("");
	m_Number_of_Access = 0;
	m_User_Access_Level = 0;
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CPosRunDb::GetDefaultConnect()
{
	return _T("ODBC;DSN=POS RUN");
}

CString CPosRunDb::GetDefaultSQL()
{
	return _T("[TPosUserInfo]");
}

void CPosRunDb::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPosRunDb)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[Last Name]"), m_Last_Name);
	RFX_Text(pFX, _T("[Given Name]"), m_Given_Name);
	RFX_Long(pFX, _T("[PIN]"), m_PIN);
	RFX_Text(pFX, _T("[Speech Profile]"), m_Speech_Profile);
	RFX_Date(pFX, _T("[Last Access Time]"), m_Last_Access_Time);
	RFX_Long(pFX, _T("[Number of Access]"), m_Number_of_Access);
	RFX_Long(pFX, _T("[User Access Level]"), m_User_Access_Level);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CPosRunDb diagnostics

#ifdef _DEBUG
void CPosRunDb::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPosRunDb::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
