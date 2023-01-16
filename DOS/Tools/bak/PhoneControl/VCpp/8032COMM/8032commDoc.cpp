// 8032commDoc.cpp : implementation of the CMy8032commDoc class
//

#include "stdafx.h"
#include "8032comm.h"

#include "8032commDoc.h"
#include "8032commView.h"

#include "DeviceNames.h"
#include "RingNr.h"
#include "SavSett.h"
#include "ComPort.h"
#include "Recallset.h"
#include "Monitor.h"
#include "afxwin.h"

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

CMonitor MonitorDlg;


/////////////////////////////////////////////////////////////////////////////
// CMy8032commDoc

IMPLEMENT_DYNCREATE(CMy8032commDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy8032commDoc, CDocument)
	//{{AFX_MSG_MAP(CMy8032commDoc)
	ON_COMMAND(ID_HARDWARE_SETTINGS, OnHardwareSettings)
	ON_COMMAND(ID_SETTINGS_SOFTWARE, OnSettingsSoftware)
	ON_COMMAND(ID_SETTINGS_SAVESETTINGS, OnSettingsSavesettings)
	ON_COMMAND(ID_SETTINGS_SERIALPORT, OnSettingsSerialport)
	ON_COMMAND(ID_SETTINGS_RECALLFACTORY, OnSettingsRecallfactory)
	ON_COMMAND(ID_SYSTEM_MONITOR, OnSystemMonitor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy8032commDoc construction/destruction

CMy8032commDoc::CMy8032commDoc()
{
// TODO: add one-time construction code here
CMy8032commApp *ThisApp;
ThisApp = (CMy8032commApp*)AfxGetApp();	
strcpy (Dateiname,"SETUP.TEL");
FILE *SETUP;
SETUP=fopen(Dateiname,"rb");

if(SETUP != NULL) //kontrolliert ob es das File SETUP.TEL schon gibt
	{fread(&SETUPDATEN,sizeof(SETUPFELD),1,SETUP); //ließt Record ein
	 fclose(SETUP);
	 m_Combo1 = SETUPDATEN.m_Combo1SET;          //überträgt Daten auf
	 strcpy (m_Geraet1,SETUPDATEN.m_Geraet1SET); //die Dialogbox -		
	 strcpy (m_Geraet2,SETUPDATEN.m_Geraet2SET); //Variablen
	 strcpy (m_Geraet3,SETUPDATEN.m_Geraet3SET);
	 strcpy (ThisApp->m_Geraet1View,SETUPDATEN.m_Geraet1SET); 		
	 strcpy (ThisApp->m_Geraet2View,SETUPDATEN.m_Geraet2SET);
	 strcpy (ThisApp->m_Geraet3View,SETUPDATEN.m_Geraet3SET);
	 m_ComPortNr = SETUPDATEN.m_ComPortNrSET;
	 switch (m_ComPortNr)
			{case ComPort1: strcpy(ThisApp->COMPortNr,"\\\\.\\COM1");
			 break;
			 case ComPort2: strcpy(ThisApp->COMPortNr,"\\\\.\\COM2");
			 break;
			 case ComPort3: strcpy(ThisApp->COMPortNr,"\\\\.\\COM3");
			 break;
			 case ComPort4: strcpy(ThisApp->COMPortNr,"\\\\.\\COM4");
			 break;
			}
	}
else	
	{m_Combo1 = 1;								//wenn Setup noch nicht 	
	 strcpy (m_Geraet1, "Device Number 1");		//existiert werden die
	 strcpy (m_Geraet2, "Device Number 2");		//Defaultwerte verwendet
	 strcpy (m_Geraet3, "Device Number 3");
	 strcpy (ThisApp->m_Geraet1View, "Device Number 1");		
	 strcpy (ThisApp->m_Geraet2View, "Device Number 2");		
	 strcpy (ThisApp->m_Geraet3View, "Device Number 3");
	 m_ComPortNr = ComPort2;					//COM2 ist Default - Wert 
	 strcpy(ThisApp->COMPortNr,"\\\\.\\COM2");  //COM2 ist Default - Wert
	 //Initialisierungsdaten werden auch auf das SETUPFELD übertragen
	 SETUPDATEN.m_Combo1SET = m_Combo1;			//Record wird beschrieben	
	 SETUPDATEN.m_ComPortNrSET = m_ComPortNr;   //Record wird beschrieben
	 strcpy (SETUPDATEN.m_Geraet1SET,m_Geraet1);//Record wird beschrieben
	 strcpy (SETUPDATEN.m_Geraet2SET,m_Geraet2);//Record wird beschrieben
	 strcpy (SETUPDATEN.m_Geraet3SET,m_Geraet3);//Record wird beschrieben
	 strcpy (ThisApp->m_Geraet1View,m_Geraet1);
	 strcpy (ThisApp->m_Geraet2View,m_Geraet2);
	 strcpy (ThisApp->m_Geraet3View,m_Geraet3);
     UpdateAllViews(NULL);
	}
sprintf(ThisApp->PhonelineCondition,"%17s","unknown");
sprintf(ThisApp->SafetyCutOff,"%17s","unknown");
sprintf(ThisApp->LastRecCharacter,"%17s","unknown");
sprintf(ThisApp->LastTraCharacter,"%17s","unknown");
sprintf(ThisApp->SpeechRecognition,"%17s","unknown");
sprintf(ThisApp->SpeechProfileID,"%17s","unknown");
strcpy(ThisApp->SpeechRecognitionView, "unknown");
}

CMy8032commDoc::~CMy8032commDoc()
{
}
BOOL CMy8032commDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMy8032commDoc serialization

void CMy8032commDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMy8032commDoc diagnostics

#ifdef _DEBUG
void CMy8032commDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy8032commDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy8032commDoc commands

void CMy8032commDoc::OnHardwareSettings() 
{
	// TODO: Add your command handler code here
	CMy8032commApp *ThisApp;
	ThisApp = (CMy8032commApp*)AfxGetApp();
// Definiere ein Objekt der Dialogklasse
	CRingNr RingNrDlg;
 
//Initialisiere die Datenelemente des Objekts
	if (ThisApp->PickUpNumberReceived)
		{m_Combo1 = ThisApp->PickUpNumber;
		 ThisApp->PickUpNumberReceived = FALSE;
		}
	RingNrDlg.m_Combo1 = m_Combo1;

//Zeige die Dialogbox an
	if (RingNrDlg.DoModal () == IDOK)
		{
		// Übernimm die aktuellen Werte aus der Dialogbox
		m_Combo1 = RingNrDlg.m_Combo1;
		SETUPDATEN.m_Combo1SET = m_Combo1;//Record wird beschrieben
		ThisApp->PickUpNumber = m_Combo1;
		ThisApp->TransmittPickUpNumber = TRUE;
		}
}	 


void CMy8032commDoc::OnSettingsSoftware() 
{
	// TODO: Add your command handler code here
	CMy8032commApp *ThisApp;
	ThisApp = (CMy8032commApp*)AfxGetApp();	
	// Definiere ein Objekt der Dialogklasse
	CDeviceNames DeviceNumberDlg;
 
//Initialisiere die Datenelemente des Objekts
	DeviceNumberDlg.m_Geraet1 = m_Geraet1;
	DeviceNumberDlg.m_Geraet2 = m_Geraet2;
	DeviceNumberDlg.m_Geraet3 = m_Geraet3;

	//Zeige die Dialogbox an
	if (DeviceNumberDlg.DoModal () == IDOK)
		{
		// Übernimm (formatiert) die aktuellen Werte aus der Dialogbox
		/*sprintf(m_Geraet1,"%15s",DeviceNumberDlg.m_Geraet1);
		sprintf(m_Geraet2,"%15s",DeviceNumberDlg.m_Geraet2);
		sprintf(m_Geraet3,"%15s",DeviceNumberDlg.m_Geraet3);*/
		strcpy(m_Geraet1,DeviceNumberDlg.m_Geraet1);
		strcpy(m_Geraet2,DeviceNumberDlg.m_Geraet2);
		strcpy(m_Geraet3,DeviceNumberDlg.m_Geraet3);
		strcpy (SETUPDATEN.m_Geraet1SET,m_Geraet1);//Record wird beschrieben
		strcpy (SETUPDATEN.m_Geraet2SET,m_Geraet2);//Record wird beschrieben
		strcpy (SETUPDATEN.m_Geraet3SET,m_Geraet3);//Record wird beschrieben
		strcpy (ThisApp->m_Geraet1View,DeviceNumberDlg.m_Geraet1);
		strcpy (ThisApp->m_Geraet2View,DeviceNumberDlg.m_Geraet2);
		strcpy (ThisApp->m_Geraet3View,DeviceNumberDlg.m_Geraet3);
		UpdateAllViews(NULL);
		}
}

void CMy8032commDoc::OnSettingsSavesettings ()
{
	// TODO: Add your command handler code here
    // Definiere ein Objekt der Dialogklasse	
	CSavSett SaveSettingsDlg;
	//Zeige die Dialogbox an
	if (SaveSettingsDlg.DoModal () == IDOK)
		{
		//Abspeichern der Variablen
		strcpy (Dateiname,"SETUP.TEL");
		FILE *SETUP;	
		SETUP=fopen(Dateiname,"wb");
		fwrite(&SETUPDATEN,sizeof(SETUPFELD),1,SETUP);
		fclose(SETUP);
		}
}

void CMy8032commDoc::OnSettingsSerialport() 
{
	// TODO: Add your command handler code here
	CMy8032commApp *ThisApp;
	ThisApp = (CMy8032commApp*)AfxGetApp();
	// Definiere ein Objekt der Dialogklasse
	CComPort ComPortNummerDlg;
	//Initialisiere die Datenelemente des Objekts
	ComPortNummerDlg.m_ComPortNr = m_ComPortNr;
	//Zeige die Dialogbox an
	if (ComPortNummerDlg.DoModal () == IDOK)
		// Übernimm die aktuellen Werte aus der Dialogbox
		{m_ComPortNr = ComPortNummerDlg.m_ComPortNr;
		 SETUPDATEN.m_ComPortNrSET = m_ComPortNr;
		/// Portzuweisung
		switch (m_ComPortNr)
			{case ComPort1: strcpy(ThisApp->COMPortNr,"\\\\.\\COM1");
			 break;
			 case ComPort2: strcpy(ThisApp->COMPortNr,"\\\\.\\COM2");
			 break;
			 case ComPort3: strcpy(ThisApp->COMPortNr,"\\\\.\\COM3");
			 break;
			 case ComPort4: strcpy(ThisApp->COMPortNr,"\\\\.\\COM4");
			 break;
			}
		}
}

void CMy8032commDoc::OnSettingsRecallfactory() 
{
	// TODO: Add your command handler code here
	CMy8032commApp *ThisApp;
	ThisApp = (CMy8032commApp*)AfxGetApp();	
	// Definiere ein Objekt der Dialogklasse
	CRecallset RecallsettingsDlg;
	//Zeige die Dialogbox an
	if (RecallsettingsDlg.DoModal () == IDOK)
		{//lösche die Datei SETUP.TEL
		strcpy (Dateiname,"SETUP.TEL");
		unlink (Dateiname);
		//Den Variablen werden wieder die Defaultwerte zugewiesen
		m_Combo1 = 1;								
		strcpy (m_Geraet1, "Device Number 1");	
		strcpy (m_Geraet2, "Device Number 2"); 
		strcpy (m_Geraet3, "Device Number 3");
		m_ComPortNr = ComPort2; //COM2 ist Default - Wert 
		//Initialisierungsdaten werden auch auf das SETUPFELD übertragen
		SETUPDATEN.m_Combo1SET = m_Combo1;		   //Record wird beschrieben	
		SETUPDATEN.m_ComPortNrSET = m_ComPortNr;   //Record wird beschrieben
		strcpy (SETUPDATEN.m_Geraet1SET,m_Geraet1);//Record wird beschrieben
		strcpy (SETUPDATEN.m_Geraet2SET,m_Geraet2);//Record wird beschrieben
		strcpy (SETUPDATEN.m_Geraet3SET,m_Geraet3);//Record wird beschrieben
		strcpy (ThisApp->m_Geraet1View, "Device Number 1");		
		strcpy (ThisApp->m_Geraet2View, "Device Number 2");		
		strcpy (ThisApp->m_Geraet3View, "Device Number 3");
		ThisApp->TransmittPickUpNumber = TRUE;
   		UpdateAllViews(NULL);

		}
}

void CMy8032commDoc::OnSystemMonitor() 
{
	// TODO: Add your command handler code here
	CMy8032commApp *ThisApp;
	ThisApp = (CMy8032commApp*)AfxGetApp();
	//Definiere ein Objekt der Dialogklasse
	//CMonitor MonitorDlg;
	//Zeige die Dialogbox an
	if (!ThisApp->MonitorActivated)
		MonitorDlg.Create(IDD_DIALOG6,NULL); 
}

