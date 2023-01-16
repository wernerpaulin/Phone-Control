// 8032commView.cpp : implementation of the CMy8032commView class
//

#include "stdafx.h"
#include "8032comm.h"

#include "DeviceNames.h"
#include "RingNr.h"
#include "SavSett.h"
#include "ComPort.h"
#include "Recallset.h"
#include "Monitor.h"
  
#include "string.h"
#include "stdio.h"
#include "conio.h"
#include "iostream.h"
#include "ctype.h"


#include "8032commDoc.h"
#include "8032commView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

HANDLE hMutex;
HANDLE hCommApp;
/////////////////////////////////////////////////////////////////////////////
// CMy8032commView

IMPLEMENT_DYNCREATE(CMy8032commView, CView)

BEGIN_MESSAGE_MAP(CMy8032commView, CView)
	//{{AFX_MSG_MAP(CMy8032commView)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy8032commView construction/destruction

CMy8032commView::CMy8032commView()
{
	// TODO: add construction code here
	m_PSerialComm = 0;
	BITMAP BM;
	m_Bitmap1.LoadBitmap (IDB_PC1);
	m_Bitmap1.GetObject (sizeof (BM), &BM);
	m_Bitmap1Width = BM.bmWidth;
	m_Bitmap1Height = BM.bmHeight;
	m_Bitmap2.LoadBitmap (IDB_Speech);
	m_Bitmap2.GetObject (sizeof (BM), &BM);
	m_Bitmap2Width = BM.bmWidth;
	m_Bitmap2Height = BM.bmHeight;
}

CMy8032commView::~CMy8032commView()
{
delete m_PSerialComm;
}

BOOL CMy8032commView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}
UINT SerialCommunication (LPVOID m_hWnd)
{
	//Befehle die vom Sekundär - Thread abgearbeitet werden
	
	//Deklarationsteil
	DWORD dwBytesWritten;
	DWORD dwBytesRead;
	char RecCharBuffer;
	DWORD dwEventMaskValue;
	CMy8032commApp *ThisApp;
	ThisApp = (CMy8032commApp*)AfxGetApp();
	int CodeLaufvariable;
	char CodeBuffer[5];	
	BOOL CodeReadingAborted;
	BOOL ValidCodeBuffer;
	hMutex = ::CreateMutex //Synchronisierte Zuweisungen
		(NULL,
		FALSE,
		NULL); 
	CMonitor Monitor;
	//Ende des Deklarationsteils

	ThisApp->ThreadRunFlag = TRUE; //Zeigt an, daß der Thread läuft
    if (!ThisApp->SetupPassed)
	{
	 BOOL SetupConnection();
	 if (!SetupConnection())
		{AfxMessageBox("Connection or Settings failed !!!", 
		 MB_OK);
		}
	}
	//Kommunikation
	dwEventMaskValue = 0;
	WaitCommEvent(
		hCommApp,
		&dwEventMaskValue,
        NULL);
	
	if ((dwEventMaskValue & EV_RXCHAR) == EV_RXCHAR)
		ReadFile(hCommApp,&RecCharBuffer,1,&dwBytesRead,NULL);
	//Auswertung
	switch (RecCharBuffer)
		{case 'V': 
			{//Einfügen: Beenden der Spracherkennung (gleiches bei CodeReadingAborted einfügen)
			 ThisApp->SpeechRecognitionActivated = FALSE;
		
			 //Monitoraktualisierung
			 ::WaitForSingleObject  (hMutex,INFINITE);
	     	 sprintf(ThisApp->PhonelineCondition,"%17s","offline");
			 ThisApp->OnChangePhonelineCondition = TRUE;
			 sprintf(ThisApp->LastRecCharacter,"%17s","V");
			 ThisApp->OnChangeLastRecCharacter = TRUE;
			 sprintf(ThisApp->SpeechRecognition,"%17s","inactive");		
			 strcpy(ThisApp->SpeechRecognitionView, "inactive");
			 ThisApp->OnChangeSpeechRecognition =TRUE;
			 sprintf(ThisApp->SpeechProfileID,"%17s","unknown");
			 ThisApp->OnChangeSpeechProfileID = TRUE;
			 ::ReleaseMutex (hMutex);
			 //Einfügen Grafiksteuerung !!!!
			 ThisApp->OnChangeView = TRUE;
			}
		break;
		case 'Y':
			{//Einlesen der wirklichen Pick - Up - Number
			 dwEventMaskValue = 0;
			 WaitCommEvent(hCommApp,&dwEventMaskValue,NULL);
			 if ((dwEventMaskValue & EV_RXCHAR) == EV_RXCHAR)
				ReadFile(hCommApp,&RecCharBuffer,1,&dwBytesRead,NULL);	
			 switch (RecCharBuffer)
				 {case '0':ThisApp->PickUpNumber = 0;
				  break;
				  case '1':ThisApp->PickUpNumber = 1;
				  break;
				  case '2':ThisApp->PickUpNumber = 2;
				  break;
				  case '3':ThisApp->PickUpNumber = 3;
				  break;
				  case '4':ThisApp->PickUpNumber = 4;
				  break;
				  case '5':ThisApp->PickUpNumber = 5;
				  break;
				  case '6':ThisApp->PickUpNumber = 6;
				  break;
				  case '7':ThisApp->PickUpNumber = 7;
				  break;
				  case '8':ThisApp->PickUpNumber = 8;
				  break;
				 }
			 ThisApp->PickUpNumberReceived = TRUE;
			 //Monitoraktualisierung
			 ::WaitForSingleObject  (hMutex,INFINITE);
	   		 sprintf(ThisApp->PhonelineCondition,"%17s","online");
			 ThisApp->OnChangePhonelineCondition = TRUE;
			 sprintf(ThisApp->LastRecCharacter,"%17s","Y");
		     ThisApp->OnChangeLastRecCharacter = TRUE;
			 ::ReleaseMutex (hMutex);
			 CodeReadingAborted = FALSE;
			 strcpy(CodeBuffer,"C");
			 //Code - Auswertung
			 for (CodeLaufvariable = 3;CodeLaufvariable >= 0;--CodeLaufvariable)
			 {dwEventMaskValue = 0;
			  WaitCommEvent(hCommApp,&dwEventMaskValue,NULL);
			  if ((dwEventMaskValue & EV_RXCHAR) == EV_RXCHAR)
				{ReadFile(hCommApp,&RecCharBuffer,1,&dwBytesRead,NULL);
					 if (strcmp(&RecCharBuffer,"A")>=0) //wirksam bei Übertragungsfehler
						{CodeReadingAborted = TRUE;		//und bei vorzeitigen Auflegen -> "V"
						 break;
						}
				 switch (RecCharBuffer)
					 {case '0':strcat(CodeBuffer,"0"); // aufgrund des DTMF - Dekoders, kann
					  break;						   // die "0" nicht verwendet werden !!!	
					  case '1':strcat(CodeBuffer,"1");
					  break;
					  case '2':strcat(CodeBuffer,"2");;
					  break;
					  case '3':strcat(CodeBuffer,"3");
					  break;
					  case '4':strcat(CodeBuffer,"4");
					  break;
					  case '5':strcat(CodeBuffer,"5");
					  break;
					  case '6':strcat(CodeBuffer,"6");
					  break;
					  case '7':strcat(CodeBuffer,"7");
					  break;
					  case '8':strcat(CodeBuffer,"8");
					  break;
					  case '9':strcat(CodeBuffer,"9");
					  break; 
					 }
				}
			 }
			 if (CodeReadingAborted)
				{
				 //Monitoraktualisierung
				 sprintf(ThisApp->PhonelineCondition,"%17s","offline");
				 ThisApp->OnChangePhonelineCondition = TRUE;
				 sprintf(ThisApp->LastRecCharacter,"%17s","V");
				 ThisApp->OnChangeLastRecCharacter = TRUE;
				 sprintf(ThisApp->SpeechRecognition,"%17s","inactive");		
				 strcpy(ThisApp->SpeechRecognitionView, "inactive");
				 ThisApp->OnChangeSpeechRecognition =TRUE;
				 sprintf(ThisApp->SpeechProfileID,"%17s","unknown");
				 ThisApp->OnChangeSpeechProfileID = TRUE;
				 //Einfügen Grafiksteuerung !!!!
				 ThisApp->OnChangeView = TRUE;
				}
			 else
				{//Monitoraktualisierung
				 sprintf(ThisApp->SpeechProfileID,"%17s",CodeBuffer);
				 ThisApp->OnChangeSpeechProfileID = TRUE;
				 //Code - Verifizierung (vorläufig nur ein Code !!!)
				 if (strcmp(CodeBuffer,"C1234") == 0)
					 ValidCodeBuffer = TRUE;
				 else
					 ValidCodeBuffer = FALSE;
				 switch (ValidCodeBuffer)
					{case TRUE:WriteFile(hCommApp,"C",1,&dwBytesWritten,NULL);
							   ThisApp->TransmittPickUpNumber = FALSE;
							   //Monitoraktualisierung
							   sprintf(ThisApp->LastTraCharacter,"%17s","C");
				        	   ThisApp->OnChangeLastTraCharacter = TRUE;
					 break;
					 default:WriteFile(hCommApp,"c",1,&dwBytesWritten,NULL);
							 ThisApp->TransmittPickUpNumber = FALSE;
							 //Monitoraktualisierung
							 sprintf(ThisApp->LastTraCharacter,"%17s","c");
				        	 ThisApp->OnChangeLastTraCharacter = TRUE;
							 //Monitoraktualisierung
							 sprintf(ThisApp->PhonelineCondition,"%17s","offline");
							 ThisApp->OnChangePhonelineCondition = TRUE;
							 sprintf(ThisApp->LastRecCharacter,"%17s","V");
							 ThisApp->OnChangeLastRecCharacter = TRUE;
							 sprintf(ThisApp->SpeechRecognition,"%17s","inactive");		
							 strcpy(ThisApp->SpeechRecognitionView, "inactive");
							 ThisApp->OnChangeSpeechRecognition =TRUE;							 sprintf(ThisApp->SpeechProfileID,"%17s","unknown");
							 ThisApp->OnChangeSpeechProfileID = TRUE;
							 //Einfügen der Grafiksteuerung
							 ThisApp->OnChangeView = TRUE;
					 break;
					}
				}
			}
		break;
		case 'O':
			{//Monitoraktualisierung
			 sprintf(ThisApp->LastRecCharacter,"%17s","O");
		     ThisApp->OnChangeLastRecCharacter = TRUE;
			 //Wenn die Resettaste gedrückt wird, wird die Pick - Up - Number übertragen
				if (ThisApp->TransmittPickUpNumber)
					{switch (ThisApp->PickUpNumber)
						 {case 0:WriteFile(hCommApp,"1",1,&dwBytesWritten,NULL);
								 ThisApp->TransmittPickUpNumber = FALSE;
								 //Monitoraktualisierung
								 sprintf(ThisApp->LastTraCharacter,"%17s","1");
								 ThisApp->OnChangeLastTraCharacter = TRUE;
						  break;
						  case 1:WriteFile(hCommApp,"2",1,&dwBytesWritten,NULL);
								 ThisApp->TransmittPickUpNumber = FALSE;
								 //Monitoraktualisierung
								 sprintf(ThisApp->LastTraCharacter,"%17s","2");
								 ThisApp->OnChangeLastTraCharacter = TRUE;
						  break;
						  case 2:WriteFile(hCommApp,"3",1,&dwBytesWritten,NULL);
								 ThisApp->TransmittPickUpNumber = FALSE;
								 //Monitoraktualisierung
								 sprintf(ThisApp->LastTraCharacter,"%17s","3");
								 ThisApp->OnChangeLastTraCharacter = TRUE;
						  break;
						  case 3:WriteFile(hCommApp,"4",1,&dwBytesWritten,NULL);
								 ThisApp->TransmittPickUpNumber = FALSE;
								 //Monitoraktualisierung
								 sprintf(ThisApp->LastTraCharacter,"%17s","4");
								 ThisApp->OnChangeLastTraCharacter = TRUE;
						  break;
						  case 4:WriteFile(hCommApp,"5",1,&dwBytesWritten,NULL);
								 ThisApp->TransmittPickUpNumber = FALSE;
								 //Monitoraktualisierung
								 sprintf(ThisApp->LastTraCharacter,"%17s","5");
								 ThisApp->OnChangeLastTraCharacter = TRUE;
						  break;
						  case 5:WriteFile(hCommApp,"6",1,&dwBytesWritten,NULL);
								 ThisApp->TransmittPickUpNumber = FALSE;
								 //Monitoraktualisierung
								 sprintf(ThisApp->LastTraCharacter,"%17s","6");
								 ThisApp->OnChangeLastTraCharacter = TRUE;
						  break;
						  case 6:WriteFile(hCommApp,"7",1,&dwBytesWritten,NULL);
								 ThisApp->TransmittPickUpNumber = FALSE;
								 //Monitoraktualisierung
								 sprintf(ThisApp->LastTraCharacter,"%17s","7");
								 ThisApp->OnChangeLastTraCharacter = TRUE;
						  break;
						  case 7:WriteFile(hCommApp,"8",1,&dwBytesWritten,NULL);
								 ThisApp->TransmittPickUpNumber = FALSE;
								 //Monitoraktualisierung
								 sprintf(ThisApp->LastTraCharacter,"%17s","8");
								 ThisApp->OnChangeLastTraCharacter = TRUE;
						  break;
						  case 8:WriteFile(hCommApp,"9",1,&dwBytesWritten,NULL);
								 ThisApp->TransmittPickUpNumber = FALSE;
								 //Monitoraktualisierung
								 sprintf(ThisApp->LastTraCharacter,"%17s","9");
								 ThisApp->OnChangeLastTraCharacter = TRUE;
						  break;
						 }
					 } 
			}
		break;
		case 'S':
			{
			 sprintf(ThisApp->SafetyCutOff,"%17s","activated");
			 ThisApp->OnChangeSafetyCutOff = TRUE;
			 sprintf(ThisApp->LastRecCharacter,"%17s","S");
			 ThisApp->OnChangeLastRecCharacter = TRUE;
			 //Einfügen Grafiksteuerung !!!!
			 ThisApp->OnChangeDevice1Condition = TRUE;
			 ThisApp->OnChangeDevice2Condition = TRUE;
			 ThisApp->OnChangeDevice3Condition = TRUE;
			 ThisApp->Device1ON = FALSE;
			 ThisApp->Device2ON = FALSE;
			 ThisApp->Device3ON = FALSE;
			 ThisApp->OnChangeView = TRUE;
			}
		break;
		case 'R':
			{
			 //Softreset wird aktiviert
			 //Monitoraktualisierung
			 sprintf(ThisApp->LastRecCharacter,"%17s","R");
			 ThisApp->OnChangeLastRecCharacter = TRUE;
			 if (ThisApp->SpeechRecognitionActivated)
				{
				 WriteFile(hCommApp,"A",1,&dwBytesWritten,NULL);
				 //Monitoraktualisierung
				 sprintf(ThisApp->LastTraCharacter,"%17s","A");
				 ThisApp->OnChangeLastTraCharacter = TRUE;
				}
			 //Einfügen: Programmaufruf
			 WinExec ("Restart.exe",SW_SHOW);//auch Reboot.exe möglich !!!
			 //system ("edit ResetSimulation.txt");
			}
		break;
		case '1':
			{
			 //Gerät Nr.1 wird bearbeitet
			 sprintf(ThisApp->LastRecCharacter,"%17s","1");
			 ThisApp->OnChangeLastRecCharacter = TRUE;
			 sprintf(ThisApp->SafetyCutOff,"%17s","inactive");
			 ThisApp->OnChangeSafetyCutOff = TRUE;
			 dwEventMaskValue = 0;
			 WaitCommEvent(hCommApp,&dwEventMaskValue,NULL);
			 if ((dwEventMaskValue & EV_RXCHAR) == EV_RXCHAR)
				ReadFile(hCommApp,&RecCharBuffer,1,&dwBytesRead,NULL);	
			 switch (RecCharBuffer)
				 {case 'E':
					{
					 sprintf(ThisApp->LastRecCharacter,"%17s","E");
					 ThisApp->OnChangeLastRecCharacter = TRUE;
					 ThisApp->Device1ON = TRUE;
					 ThisApp->OnChangeDevice1Condition = TRUE;
					 // Einfügen der Grafiksteuerung !!!!
					 ThisApp->OnChangeView = TRUE;
					}	
				  break;
				  case 'A':
					{
					 sprintf(ThisApp->LastRecCharacter,"%17s","A");
					 ThisApp->OnChangeLastRecCharacter = TRUE;
					 ThisApp->Device1ON = FALSE;
					 ThisApp->OnChangeDevice1Condition = TRUE;
					 // Einfügen der Grafiksteuerung !!!!
					 ThisApp->OnChangeView = TRUE;
					}
				  break;
			     }	
			}
		break;
		case '2':
			{
			 //Gerät Nr.2 wird bearbeitet
			 sprintf(ThisApp->LastRecCharacter,"%17s","2");
			 ThisApp->OnChangeLastRecCharacter = TRUE;
			 sprintf(ThisApp->SafetyCutOff,"%17s","inactive");
			 ThisApp->OnChangeSafetyCutOff = TRUE;
			 dwEventMaskValue = 0;
			 WaitCommEvent(hCommApp,&dwEventMaskValue,NULL);
			 if ((dwEventMaskValue & EV_RXCHAR) == EV_RXCHAR)
				ReadFile(hCommApp,&RecCharBuffer,1,&dwBytesRead,NULL);	
			 switch (RecCharBuffer)
				 {case 'E':
					{
					 sprintf(ThisApp->LastRecCharacter,"%17s","E");
					 ThisApp->OnChangeLastRecCharacter = TRUE;
					 ThisApp->Device2ON = TRUE;
					 ThisApp->OnChangeDevice2Condition = TRUE;
					 // Einfügen der Grafiksteuerung !!!!
					 ThisApp->OnChangeView = TRUE;
					}	
				  break;
				  case 'A':
					{
					 sprintf(ThisApp->LastRecCharacter,"%17s","A");
					 ThisApp->OnChangeLastRecCharacter = TRUE;
					 ThisApp->Device2ON = FALSE;
					 ThisApp->OnChangeDevice2Condition = TRUE;
					 // Einfügen der Grafiksteuerung !!!!
					 ThisApp->OnChangeView = TRUE;
					}
				  break;
				 }
			}
		break;
		case '3':
			{
			 //Gerät Nr.3 wird bearbeitet
			 sprintf(ThisApp->LastRecCharacter,"%17s","3");
			 ThisApp->OnChangeLastRecCharacter = TRUE;
			 sprintf(ThisApp->SafetyCutOff,"%17s","inactive");
			 ThisApp->OnChangeSafetyCutOff = TRUE;
			 dwEventMaskValue = 0;
			 WaitCommEvent(hCommApp,&dwEventMaskValue,NULL);
			 if ((dwEventMaskValue & EV_RXCHAR) == EV_RXCHAR)
				ReadFile(hCommApp,&RecCharBuffer,1,&dwBytesRead,NULL);	
			 switch (RecCharBuffer)
				 {case 'E':
					{
					 sprintf(ThisApp->LastRecCharacter,"%17s","E");
					 ThisApp->OnChangeLastRecCharacter = TRUE;
					 ThisApp->Device3ON = TRUE;
					 ThisApp->OnChangeDevice3Condition = TRUE;
					 // Einfügen der Grafiksteuerung !!!!
					 ThisApp->OnChangeView = TRUE;
					}	
				  break;
				  case 'A':
					{
					 sprintf(ThisApp->LastRecCharacter,"%17s","A");
					 ThisApp->OnChangeLastRecCharacter = TRUE;
					 ThisApp->Device3ON = FALSE;
					 ThisApp->OnChangeDevice3Condition = TRUE;
					 // Einfügen der Grafiksteuerung !!!!
					 ThisApp->OnChangeView = TRUE;
					}
				  break;
				 }
			}
		break;
		case '4':
			{
			 //Spracherkennung wird aktiviert
			 sprintf(ThisApp->LastRecCharacter,"%17s","4");
			 ThisApp->OnChangeLastRecCharacter = TRUE;
			 sprintf(ThisApp->SpeechRecognition,"%17s","activated");
			 strcpy(ThisApp->SpeechRecognitionView, "activated");
			 ThisApp->OnChangeSpeechRecognition = TRUE;		
			 ThisApp->SpeechRecognitionActivated = TRUE;
			 //Einfügen der Grafiksteuerung
			 ThisApp->OnChangeView = TRUE;
			 //Einfügen: Bedienung der Spracherkennungssoftware
			 //Bei zu langer Redepause "A" senden -> bewirkt auflegen !!!
			}
		break;
		case '5':
			{
			 //Zahl "5" wird bei Bedarf hier ausgewertet
			 sprintf(ThisApp->LastRecCharacter,"%17s","5");
			 ThisApp->OnChangeLastRecCharacter = TRUE;
			}
		break;
		case '6':
			{
			 //Zahl "6" wird bei Bedarf hier ausgewertet
			 sprintf(ThisApp->LastRecCharacter,"%17s","6");
			 ThisApp->OnChangeLastRecCharacter = TRUE;
			}
		break;
		case '7':
			{
			 //Zahl "7" wird bei Bedarf hier ausgewertet
			 sprintf(ThisApp->LastRecCharacter,"%17s","7");
			 ThisApp->OnChangeLastRecCharacter = TRUE;
			}
		break;
		case '8':
			{
			 //Zahl "8" wird bei Bedarf hier ausgewertet
			 sprintf(ThisApp->LastRecCharacter,"%17s","8");
			 ThisApp->OnChangeLastRecCharacter = TRUE;
			}
		break;
		case '9':
			{
			 //Zahl "9" wird bei Bedarf hier ausgewertet
			 sprintf(ThisApp->LastRecCharacter,"%17s","9");
			 ThisApp->OnChangeLastRecCharacter = TRUE;
			}
		break;
		/*case '0':
			{
			 //Zahl "0" wird bei Bedarf hier ausgewertet
			 sprintf(ThisApp->LastRecCharacter,"%17s","0");
			 ThisApp->OnChangeLastRecCharacter = TRUE;
			}
		break;*/
	}
		
		
	/*	sprintf(ThisApp->PhonelineCondition,"%17s","online/offline");
		ThisApp->OnChangePhonelineCondition = TRUE;
		
		sprintf(ThisApp->SafetyCutOff,"%17s","inactive/activated");
		ThisApp->OnChangeSafetyCutOff = TRUE;		

		sprintf(ThisApp->LastRecCharacter,"%17s"," ");
		ThisApp->OnChangeLastRecCharacter = TRUE;
		
		sprintf(ThisApp->LastTraCharacter,"%17s"," ");
		ThisApp->OnChangeLastTraCharacter = TRUE

		sprintf(ThisApp->SpeechRecognition,"%17s","inactive/activated");
		ThisApp->OnChangeSpeechRecognition =TRUE;
		
		sprintf(ThisApp->SpeechProfileID,"%17s","0201/Paulin");
		ThisApp->OnChangeSpeechProfileID = TRUE;
	*/

	//SerialCommunication (m_hWnd); //Rekursiv - Aufruf!!!!!
	//ThisApp->ThreadRunFlag = FALSE;
	if (ThisApp->SetupReturnValue)
	ThisApp->OnChangeView = TRUE;
	return (0);


}

BOOL SetupConnection ()
{
	//Deklarationsteil
	DCB dcb;
	CMy8032commApp *ThisApp;
	ThisApp = (CMy8032commApp*)AfxGetApp();
	//Ende des Deklarationsteils

	// Initialisierungscode der Seriellenschnittstelle
	//Portnamen: \\.\COM1  Initialisierungsname:\\\\.\\COM1
	hCommApp = CreateFile    
		(ThisApp->COMPortNr,			// File Name	
		 GENERIC_READ | GENERIC_WRITE,	// Schreiben oder Lesen zulässig
		 0,								// File nicht teilbar
		 NULL,							// File nicht vererbar
		 OPEN_EXISTING,					// für die Port - Verwendung öffnen
		 FILE_ATTRIBUTE_NORMAL,			// keine File - Attribute
		 NULL);							// kein File - Attribut - Handle	
	//DCB - Struktur
	dcb.DCBlength = sizeof(DCB);		    // sizeof(DCB) 
	dcb.BaudRate = CBR_2400;				// current baud rate 
	dcb.fBinary = TRUE;						// binary mode, no EOF check 
	dcb.fParity = FALSE;					// enable parity checking 
	dcb.fOutxCtsFlow = FALSE;				// CTS output flow control 
	dcb.fOutxDsrFlow = FALSE;				// DSR output flow control 
	dcb.fDtrControl = DTR_CONTROL_DISABLE;  // DTR flow control type 
	dcb.fDsrSensitivity = FALSE;			// DSR sensitivity 
	dcb.fTXContinueOnXoff = FALSE;			// XOFF continues Tx 
	dcb.fOutX = FALSE;						// XON/XOFF out flow control 
	dcb.fInX = FALSE;					    // XON/XOFF in flow control 
	dcb.fErrorChar = FALSE;				    // enable error replacement 
	dcb.fNull = FALSE;						// enable null stripping 
	dcb.fRtsControl = RTS_CONTROL_DISABLE;  // RTS flow control 
	dcb.fAbortOnError = FALSE;				// abort reads/writes on error 
	//dcb.fDummy2:17;						// reserved 
	dcb.wReserved = 0;						// not currently used 
	//dcb.XonLim;							// transmit XON threshold 
	//dcb.XoffLim;							// transmit XOFF threshold 
	dcb.ByteSize = 8;						// number of bits/dcb., 4-8 
	dcb.Parity = NOPARITY;					// 0-4=no,odd,even,mark,space 
	dcb.StopBits = ONESTOPBIT;              // 0,1,2 = 1, 1.5, 2 
	/*char XonChar;							// Tx and Rx XON character 
	char XoffChar;							// Tx and Rx XOFF character 
	char ErrorChar;							// error replacement character 
	char EofChar;							// end of input character 
	char EvtChar;              				// received event character 
	dcb.wReserved1;*/						// reserved; do not use 
    
	SetupComm(hCommApp,
			  200,							//size of input buffer (in bytes)
			  200);							//size of output buffer (in bytes)
	
	SetCommMask(hCommApp,EV_RXCHAR);		//Erkennung eines empfangenes Zeichen aktiviert

	ThisApp->SetupReturnValue = SetCommState(hCommApp,&dcb);
	ThisApp->SetupPassed = TRUE;
	return(ThisApp->SetupReturnValue);
}

/////////////////////////////////////////////////////////////////////////////
// CMy8032commView drawing

void CMy8032commView::OnDraw(CDC* pDC)
{
	CMy8032commDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// Thread - Initialisierung (aber nur bei erstmaligen Programmstart -> 
	// -> ThreadRunFlag !!!!)
    CMy8032commApp *ThisApp;
	ThisApp = (CMy8032commApp*)AfxGetApp();
	//if (ThisApp->ThreadRunFlag == FALSE)
			{m_PSerialComm = AfxBeginThread
			 (SerialCommunication,
			 &m_hWnd,
			 THREAD_PRIORITY_ABOVE_NORMAL,
			 0,
			 CREATE_SUSPENDED);
			 m_PSerialComm->m_bAutoDelete = FALSE;
			 m_PSerialComm->ResumeThread ();
			 SetTimer(2,500,NULL);
			}
	
	// TODO: add draw code for native data here
	//Bitmap anzeigen
	CDC MemDC;
	MemDC.CreateCompatibleDC (NULL);
	MemDC.SelectObject (&m_Bitmap1);
	pDC->BitBlt
		(43,					//logische horizontale Zielkoordinate
		 40,					//logische vertikale Zielkoordinate
		 m_Bitmap1Width,		//Breite des zu übertragenen Blocks (logische Koordinate)
		 m_Bitmap1Height,	//Höhe des zu übertragenen Blocks (logische Koordinate)
		 &MemDC,			//Quellengerätekontext
		 0,					//logische horizontale Quellkoordinate
		 0,					//logische vertikale Quellkoordinate
		 SRCAND);			//Übertragungsart

	pDC->BitBlt
		(183,					//logische horizontale Zielkoordinate
		 40,					//logische vertikale Zielkoordinate
		 m_Bitmap1Width,		//Breite des zu übertragenen Blocks (logische Koordinate)
		 m_Bitmap1Height,	//Höhe des zu übertragenen Blocks (logische Koordinate)
		 &MemDC,			//Quellengerätekontext
		 0,					//logische horizontale Quellkoordinate
		 0,					//logische vertikale Quellkoordinate
		 SRCAND);			//Übertragungsart
	
	pDC->BitBlt
		(323,					//logische horizontale Zielkoordinate
		 40,					//logische vertikale Zielkoordinate
		 m_Bitmap1Width,		//Breite des zu übertragenen Blocks (logische Koordinate)
		 m_Bitmap1Height,	//Höhe des zu übertragenen Blocks (logische Koordinate)
		 &MemDC,			//Quellengerätekontext
		 0,					//logische horizontale Quellkoordinate
		 0,					//logische vertikale Quellkoordinate
		 SRCAND);			//Übertragungsart

MemDC.SelectObject (&m_Bitmap2);
pDC->BitBlt
		(463,					//logische horizontale Zielkoordinate
		 21,					//logische vertikale Zielkoordinate
		 m_Bitmap2Width,		//Breite des zu übertragenen Blocks (logische Koordinate)
		 m_Bitmap2Height,	//Höhe des zu übertragenen Blocks (logische Koordinate)
		 &MemDC,			//Quellengerätekontext
		 0,					//logische horizontale Quellkoordinate
		 0,					//logische vertikale Quellkoordinate
		 SRCAND);			//Übertragungsart

	//Bitmap beschriften (mit den aktuellen Gerätenamen)
	pDC->SelectStockObject (ANSI_FIXED_FONT);//Standard - Schriftart
	pDC->SetBkMode (TRANSPARENT);
	
	i = strlen(ThisApp->m_Geraet1View);
	X = 30+60 - (i*8)/2;
	pDC->TextOut (X,140,ThisApp->m_Geraet1View);
	
	i = strlen(ThisApp->m_Geraet2View);
	X = 170+60 - (i*8)/2;
	pDC->TextOut (X,140,ThisApp->m_Geraet2View);
	
	i = strlen(ThisApp->m_Geraet3View);
	X = 311+60 - (i*8)/2;
	pDC->TextOut (X,140,ThisApp->m_Geraet3View);

	//Anzeigen der jeweiligen Gerätezustände
	pDC->SetTextAlign (TA_CENTER);
	pDC->TextOut (502,140,ThisApp->SpeechRecognitionView); //Spracherkennung
	
	HICON hicon;
	if (ThisApp->OnChangeDevice1Condition)
		{
		 switch (ThisApp->Device1ON)
			{
			 case TRUE: hicon = AfxGetApp()->LoadIcon(IDI_LightOn);
			 break;
			 case FALSE: hicon = AfxGetApp()->LoadIcon(IDI_LightOff);
			 break;
			}
		 pDC->DrawIcon (74, 50, hicon);
		}
	
	if (ThisApp->OnChangeDevice2Condition)
		{
		 switch (ThisApp->Device2ON)
			{
			 case TRUE: hicon = AfxGetApp()->LoadIcon(IDI_LightOn);
			 break;
			 case FALSE: hicon = AfxGetApp()->LoadIcon(IDI_LightOff);
			 break;
			}
		 pDC->DrawIcon (214, 50, hicon);
		}
	
	if (ThisApp->OnChangeDevice3Condition)
		{
		 switch (ThisApp->Device3ON)
			{
			 case TRUE: hicon = AfxGetApp()->LoadIcon(IDI_LightOn);
			 break;
			 case FALSE: hicon = AfxGetApp()->LoadIcon(IDI_LightOff);
			 break;
			}
		 pDC->DrawIcon (354, 50, hicon);
		}
}


/////////////////////////////////////////////////////////////////////////////
// CMy8032commView diagnostics

#ifdef _DEBUG
void CMy8032commView::AssertValid() const
{
	CView::AssertValid();
}

void CMy8032commView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy8032commDoc* CMy8032commView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy8032commDoc)));
	return (CMy8032commDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy8032commView message handlers

void CMy8032commView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	// Entsorgungscode für Serielle Schnittstelle 
	SetCommMask(hCommApp,0);							//Einstellung der Defaultwerte
	PurgeComm(hCommApp,PURGE_TXABORT | PURGE_RXABORT |	//Sende- /Empfangsabbruch
						PURGE_TXCLEAR | PURGE_RXCLEAR); //Löschen der beiden Buffer
	CloseHandle(hCommApp);
	KillTimer(2);
}



void CMy8032commView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CMy8032commApp *ThisApp;
		 ThisApp = (CMy8032commApp*)AfxGetApp();
	if (ThisApp->OnChangeView)
		{
		 CMy8032commDoc *ThisDoc =
					 (CMy8032commDoc*)((CFrameWnd*)ThisApp->m_pMainWnd)->GetActiveDocument ();
		 ThisDoc->UpdateAllViews(NULL,0,NULL);
		 ThisApp->OnChangeView = FALSE;
		}
	CView::OnTimer(nIDEvent);
}

