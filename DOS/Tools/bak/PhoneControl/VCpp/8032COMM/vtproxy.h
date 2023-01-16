//------------------------------------------------------------------------------
//
//    COPYRIGHT:
//    ----------
//    Copyright (C) International Business Machines Corp., 1996.
//
//      DISCLAIMER OF WARRANTIES:
//      -------------------------
//      The following [enclosed] code is sample code created by IBM
//      Corporation.  This sample code is not part of any standard IBM
//      product and is provided to you solely for the purpose of
//      assisting you in the development of your applications.  The
//      code is provided "AS IS", without warranty of any kind.  IBM
//      shall not be liable for any damages arising out of your use of
//      the sample code, even if they have been advised of the
//      possibility of such damages.
//
//------------------------------------------------------------------------------
//
//  VTProxy.h - Defines the VTProxy class.  
//
//  This class is a C++ wrapper for a subset of IBM VoiceType SMAPI.
//  The VTProxy class can be used by VoiceType client applications 
//  to interface the IBM VoiceType engine for basic speech 
//  recognition features.  VTProxy provides high level methods for a
//  variety of task required by an application.  The following tasks 
//  are supported:
//
//     * Session state such as connnect and disconnect.
//     * Interacts with VoiceType messages, errors, etc.
//     * Basic microphone tasks on/off/query.
//     * Stores words for correction, save/restore session.
//     * Manages speech focus
//     * Demonstrates use of synchronous API's
//     * Support for grammar based recognition
//
//
//  LIMITATIONS:
//  This sample code is intended to illustrate certain basic techniques
//  and so it does not support all functions needed for a robust 
//  comercial speech aware application.  It illustrates one of many 
//  possible ways to use SMAPI in a C++ program, and may be suitable
//  as a starting point for a more complete application.  The following
//  limitations exist in the VTProxy class:
//
//     * exclusive use of synchronous API's - this provides code which
//       is easier to understand, but is SLOWER and LESS RESPONSIVE
//       than using asynchronous SM API's.
//
//     * No support for keyboard editing of recognized text - a great
//       deal of code is required to maintain synchronization of text
//       in a GUI control and the text held by the application (in 
//       this case the VTProxy wordlist (VTWord objects collected by
//       a DoublyLinkedList object).
//
//     * Rudimentary word correction -  no support for display and 
//       selection of a list of alternative words, user typed alternate
//       words, or adding new words.  See VTProxy::correctSelection()
//       implementation for more information.
//
//     * Only supports dictation at end of text - does not support moving
//       insertion point and dictating into middle of existing text.
//
//     * TBD - more (or less) stuff goes here
//
//     * retrieves current language code for the caller as a two byte
//       character string
//
//------------------------------------------------------------------------------
#ifndef INCL_VTPROXY_H
#define INCL_VTPROXY_H

#ifdef _MSC_VER                        // indicates Microsoft Compiler
   #include "stdafx.h"                 // defines HWND for connect()
#else
   #include <windows.h>                // defines HWND for connect()
#endif

#include "smapi.h"                     // IBM VoiceType APIs
#include "dllist.h"                    // linked list class
#include "vtword.h"                    // reco'ed word as list object

class VTProxy                          // see notes (above)
{
   public:

      VTProxy();                       // ctor
      ~VTProxy();                      // dtor

      int connect( char * appName, HWND hWnd,      // proxy/app to engine
                   int connectID, BOOL saveAudio ); 

      int disconnect( void );                      // disconnect from engine
      int beginDictation( BOOL wantStopCommand );  // mic on
   
      int engineMessage( LPARAM lParam );  // receives messages from engine

      const char *getMessage( void );      // get text of engine message

      BOOL isMessageWaiting( void )        // indicates msg waiting
         { return ( m_bMsgWaiting ); }

      const char *getPhrase( void );       // get text of phrase
      const char *getPhraseVocab( void );  // get vocab of current phrase

      BOOL isPhraseWaiting( void )         // indicates phrase waiting
         { return ( m_bPhraseWaiting ); }

      BOOL isAnnotationWaiting( void )     // indicates annotaion waiting
         { return ( m_bannotationWaiting ); }

      const char *getStrAnnotation( void );// get string annotation
      long getNumAnnotation( void );       // get numeric annotation

      BOOL isWordWaiting( void )           // indicates word(s) waiting
         { return ( m_bwordWaiting ); }

      VTWord * getLastDisplayedWord( void )    // tracks display progress
         { return ( m_lastDisplayedWord ); }

      void allWordsProcessed( void );      // app has displayed all words

      void setAppIndex( int newIndex )     // synch VTProxy with app
         { m_appIndex = newIndex; }

      int getAppIndex( void )              // synch app with VTProxy
         { return( m_appIndex ); } 
      BOOL isBadWordWaiting( void )        // indicates bad word(s) waiting
         { return ( m_bBadWordWaiting ); }

      const char *getBadWords( BOOL reset );    // get bad words


      BOOL isConnected( void ) { return( m_connected ); }
      BOOL isRecognizing( void ) { return( m_bRecognizing ); }
      BOOL defineGrammar( const char *grammarName, 
                          const char *vocabularyName );
      BOOL defineWordList( const char *grammarName, 
                          const char *vocabularyName );                          
      BOOL defineVocabulary( const char *vocabularyName,
                             int iNumWords,
                             SM_VOCWORD **pVocPtrs);
      BOOL undefineVocabulary( const char *vocabularyName );
      BOOL enableVocabulary( const char *vocabularyName );
      BOOL isVocabDefined(BOOL* bResult, const char *theVocabulary );
      BOOL isVocabEnabled( const char *theVocabulary );
      BOOL recognizing() { return m_bRecognizing; }
      BOOL startRecognizing();
      BOOL stopRecognizing();
      BOOL stopDictation();
      BOOL beginListening();      
      BOOL processAnnotations( const SM_MSG * reply );

      const char * getInstAPIVer( void )
        { return m_InstAPIVer; }
      const char * getDefaultUserID( void )
        { return m_DefaultUserID; }
      const char * getDefaultEnrollID( void )
        { return m_DefaultEnrollID; }
      const char * getDefaultTask( void )
        { return m_DefaultTask; }
      const char *getInfirmBuff( void )
	     { return m_infirmbuff; }
      BOOL disableGrammar( const char *vocabularyName );
      void processEngineError(SM_MSG reply, int rcEngine);

      // language querying support
      const char* getLanguageCode()		// returns five byte language code
                  { return m_achLangCode; }
      const char* getLanguageCodeTail()         // returns the final two char country only
                  { return m_achLangCode + 3; }

      // ---------------------------------------------------------
      // translated linked list methods to wordlist datatype
      // See dllist.h for details of each method.
      //
      // 'NU' at the end of the method name means 'No Update' of
      // the list class internal "current node" pointer.
      VTWord * correctSelection( int selFirst, int selLast );

      VTWord * getFirstWord( void )
         { return( (VTWord *) m_wordlist.getFirst() ); }

      VTWord * getFirstWordNU( void )
         { return( (VTWord *) m_wordlist.getFirstNU() ); }

      VTWord * getPrevWord( void )
         { return( (VTWord *) m_wordlist.getPrev() ); }

      VTWord * getNextWord( void )
         { return( (VTWord *) m_wordlist.getNext() ); }

      VTWord * getNextWordNU( VTWord * aWordPtr )
         { return( (VTWord *) m_wordlist.getNextNU( aWordPtr ) ); }

      VTWord * getCurrentWord( void )
         { return( (VTWord *) m_wordlist.getCurrent() ); }

      VTWord * getLastWord( void )
         { return( (VTWord *) m_wordlist.getLast() ); }

      VTWord * getLastWordNU( void )
         { return( (VTWord *) m_wordlist.getLastNU() ); }

      VTWord * deleteCurrentWord( void )
         { return( (VTWord *) m_wordlist.deleteCurrentNode() ); }

   private:
   
      // attributes
      BOOL m_bRecognizing;             // reco status (mic on/off)
      BOOL m_bMsgWaiting;              // indicates new message is stored
      BOOL m_bPhraseWaiting;           // indicates new Phrase is stored
      BOOL m_bannotationWaiting;       // indicates new annotation is stored
      BOOL m_bwordWaiting;             // indicates new/changed word(s)
      BOOL m_bBadWordWaiting;          // indicates new bad words are stored
      int m_playbackStatus;            // (correction) audio playback progress
      char m_message[256];             // engine message
      char *m_messageEnd;              // end of current message ptr
      char m_phrase[256];              // engine phrase
      char *m_phraseEnd;               // end of current phrase ptr
      char m_phrase_vocab[256];        // vocab of origin for current phrase
      char m_StrAnnotation[256];       // all annotations for a phrase
      long m_NumAnnotation;            // single numeric annotation for a phrase
      int m_appIndex;                  // current app char insertion point
      char m_badWords[256];            // all annotations for a phrase
      char m_achLangCode[8];           // code of connected speech language

      DoublyLinkedList m_wordlist;     // data strcture for recognized words
      VTWord * m_lastDisplayedWord;    // points to last word displayed

      int m_connected;                 // engine connect status
      char * m_InstAPIVer;
      char * m_DefaultUserID;
      char * m_DefaultEnrollID;
      char * m_DefaultTask;

      char m_infirmbuff[256];          // infirm words

      // methods
		void storeMessage(const char* pszFormat, ...); // format & 
                                       // store a message
		void storePhrase(const char* pszFormat, ...); // format & 
                                       // store a phrase
		void storePhraseVocab(const char *vocabName); // store vocab name 

      // language code querying //
      BOOL	storeLangCode( SM_MSG reply);	// extracts and stores curr lang

      BOOL defineStopCommand( void );  // define "stop-dictation" grammar
      void setData( SM_MSG reply );    // store connect data
      int engineWords( SM_MSG reply ); // process recognized words
      BOOL addWordToList( SM_WORD *pword );  // insert word into list
      BOOL processRecognizedPhrase(SM_MSG reply);
      BOOL processRecognizedWord(SM_MSG reply);
};
#endif
