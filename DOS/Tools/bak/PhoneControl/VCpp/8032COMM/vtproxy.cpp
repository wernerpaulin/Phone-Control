//------------------------------------------------------------------------------
//
// COPYRIGHT:
// ----------
// Copyright (C) International Business Machines Corp., 1996.
//
// DISCLAIMER OF WARRANTIES:
// -------------------------
// The following [enclosed] code is sample code created by IBM
// Corporation.  This sample code is not part of any standard IBM
// product and is provided to you solely for the purpose of
// assisting you in the development of your applications.  The
// code is provided "AS IS", without warranty of any kind.  IBM
// shall not be liable for any damages arising out of your use of
// the sample code, even if they have been advised of the
// possibility of such damages.
//
//------------------------------------------------------------------------------
//
//  VTProxy.cpp - implements methods of the VTProxy class.
//
//     * * * Refer to VTProxy.h for a description of this class. * * *
//
//------------------------------------------------------------------------------

#include "vtproxy.h"                   // VTProxy class definition
#include <stdio.h>

//------------------------------------------------------------------------------
//  VTProxy()
//------------------------------------------------------------------------------
//
//  This method preforms basic member attribute initialization, nothing fancy.
//
//------------------------------------------------------------------------------

VTProxy::VTProxy()
{
   m_connected = 0;                    // basic initialization...
   m_bRecognizing = FALSE;
   m_bMsgWaiting = FALSE;
   m_bPhraseWaiting = FALSE;
   m_bwordWaiting = FALSE;
   m_bBadWordWaiting = FALSE;
   m_playbackStatus = 0;
   m_bannotationWaiting = FALSE;

   m_lastDisplayedWord = NULL;
}

//------------------------------------------------------------------------------
//  ~VTProxy()
//------------------------------------------------------------------------------
//
//  This method cleans things up
//
//------------------------------------------------------------------------------

VTProxy::~VTProxy()
{
   m_wordlist.deleteAllNodes();

   disconnect();                       // seems like a good idea
}


//------------------------------------------------------------------------------
//  connect()
//------------------------------------------------------------------------------
//
//  This method connects the application to the VoiceType engine in two steps.
//  First the API session is opened, then SmConnect() is called to engage the
//  engnie.
//
//------------------------------------------------------------------------------

int VTProxy::connect( char * appName, HWND hWnd, int connectID, BOOL saveAudio )
{
   int    rc;
   SmArg  smargs [ 30 ];
   int    smc;
   SM_MSG reply;

   if (!m_connected)
   {
      // Checking the API version ensures that the application was built with
      // a version of SMAPI which is the same as or older than the version
      // of VoiceType which is installed on the users computer.

      rc = SmApiVersionCheck( SM_API_VERSION_STRING, &m_InstAPIVer );

      if ( rc == SM_RC_WRONG_SM_VERSION )
      {
         storeMessage( "This application requires a newer version VoiceType" );
      }

      else
      {
         // Set up arguments for SmOpen() call
         smc = 0;

         // do not try "smc++" inside call to SmSetArg, see Prog Ref
         SmSetArg( smargs [ smc ], SmNapplicationName, appName );
         smc++;
         SmSetArg( smargs [ smc ], SmNwindowHandle, hWnd );
         smc++;
         SmSetArg( smargs [ smc ], SmNconnectionId, connectID );
         smc++;

         rc = SmOpen( smc, smargs );


         if ( rc == SM_RC_OK )
         {
            storeMessage( "Open OK" );

            // Set up arguments for SmConnect() call
            smc = 0;

            // do not try "smc++" inside call to SmSetArg, see Prog Ref
            SmSetArg( smargs [ smc ], SmNuserId,   SM_USE_CURRENT );
            smc++;
            SmSetArg( smargs [ smc ], SmNenrollId, SM_USE_CURRENT );
            smc++;
            SmSetArg( smargs [ smc ], SmNtask,     SM_USE_CURRENT );
            smc++;
            SmSetArg( smargs [ smc ], SmNrecognize, TRUE );
            smc++;

            // Connect to the Speech Engine
            rc = SmConnect( smc, smargs, &reply );

            if ( rc == SM_RC_OK )
            {
               m_connected = TRUE;

               setData( reply );       // save user/enroll/task data from reply

               storeMessage( " & Connect OK" );

               // Enable (or not) the saving of recorded audio during reco
               SmSet( SM_SAVE_AUDIO, saveAudio, &reply );
            }
            else
            {
               storeMessage( "Error on SmConnect: %s, rc=%d", 
                             SmReturnRcDescription(rc), rc);
            }
         }
         else
         {
            storeMessage( "Error on SmOpen: %s, rc=%d", 
                          SmReturnRcDescription(rc), rc);
         }
      }
   }
   else
      storeMessage( "Already Connected!" );

   return( rc );
}


//------------------------------------------------------------------------------
//  disconnect()
//------------------------------------------------------------------------------
//
//  This method discnnects the application from the engine and the API
//
//------------------------------------------------------------------------------

int VTProxy::disconnect( void )
{
   int    rc;
   SM_MSG reply;

   if ( m_connected )                  // already disconnected?
   {
      if ( m_bRecognizing )            // is recognition happening?
         stopRecognizing();             // stop reco before disconnect

      rc = SmDisconnect( 0, NULL, &reply );

      if ( rc == SM_RC_OK )
      {
         rc = SmClose();

         if ( rc == SM_RC_OK )
            m_connected = 0;
         else
            storeMessage( "Error closing" );
      }
      else
         storeMessage( "Error disconnecting from engine" );
   }
   else
      storeMessage( "Already Disconnected!" );


   return( rc );
}


//------------------------------------------------------------------------------
//  setData()
//------------------------------------------------------------------------------
//
//  This method gets various information from a reply structure and stores it.
//
//------------------------------------------------------------------------------

void VTProxy::setData( SM_MSG reply )
{
   SmGetUserId( reply, &m_DefaultUserID );
   SmGetEnrollId( reply, &m_DefaultEnrollID );
   SmGetTask( reply, &m_DefaultTask );
   if ( !storeLangCode( reply) )
	  /* on error, default to US */
	  strcpy( m_achLangCode, "en_us" );
}


//------------------------------------------------------------------------------
//  defineStopCommand()
//------------------------------------------------------------------------------
//
//  This method defines a mini grammar with just "stop dictation"
//
//------------------------------------------------------------------------------

BOOL VTProxy::defineStopCommand( void )
{
   char * stopCommand = "Stop dictation";
   SM_VOCWORD vocab;
   SM_VOCWORD * pVocab;

   vocab.flags = 0;
   vocab.spelling = stopCommand;
   vocab.spelling_size = strlen( stopCommand );

   pVocab = &vocab;

   return ( defineVocabulary( "stopcmd", 1, &pVocab ) );
}


//------------------------------------------------------------------------------
//  beginDictation()
//------------------------------------------------------------------------------
//
//  This method performs a sequence of SMAPI steps which result in beginning
//  the dictation process.
//
//------------------------------------------------------------------------------

int VTProxy::beginDictation( BOOL wantStopCommand )
{
   int rc;
   SM_MSG reply;

   if ( m_connected == TRUE )          // can't dictate unless connected
   {
      if ( m_bRecognizing )                // redundant begin dictation?
         storeMessage( "Already dictating" );
      else                                 // OK, try to begin dictation.
      {
         // The Programmers Reference - Session Sharing - Navigator Session
         // section says: "...it is desirable for an application to to exclude
         // navigator vocabularies, which are normally always active during 
         // dictation recognition to allow the user to enter words that may 
         // also be in the navigator's command vocabulary..."

         SmSet( SM_ENABLE_EXCLUSIVE_VOCABS, TRUE, &reply );

         rc = SmHaltRecognizer( &reply );  // required to enable a vocab

         if ( rc == SM_RC_OK )
         {
            rc = SmEnableVocab( "text", &reply );     // 'text' is dict vocab

            if ( rc == SM_RC_OK )
            {

               if ( wantStopCommand )
               {
                  defineStopCommand();    // define stop command for dictation
                  enableVocabulary( "stopcmd" );      // turn on stopcmd
               }

               startRecognizing();   // request focus, mike on, and reco next
            }
            else
            {
               storeMessage( 
                   "Error on SmEnableVocab( \"text\" ): %s, rc=%d\n\n%s%s",
                   SmReturnRcDescription(rc), rc,
                   "Install dictation and/or select the General Dictation ",
                   "Vocabulary\nin the Control Panel, VoiceCenter Properties");
            }
         }
         else
         {
            storeMessage( "Error on SmHaltRecognizer: %s, rc=%d", 
                          SmReturnRcDescription(rc), rc);
         }
      }
   }
   else
      storeMessage( "Must connect first" );


   return( rc );
}


//------------------------------------------------------------------------------
//  engineMessage()
//------------------------------------------------------------------------------
//
//  This method gets called by the application to handle messages from the
//  engine.  In general the easy ones are handled directly and the more
//  involved processing is passed on to other VTProxy methods.
//
//------------------------------------------------------------------------------

int VTProxy::engineMessage( LPARAM lParam )
{
   int type;
   int rc;
   char *p_msg;
   SM_MSG reply;

   // Received message from Speech Engine

   // Request to receive a message from the Engine
   SmReceiveMsg( lParam, &reply );

   // Retrieve the type of message that was received
   SmGetMsgType( reply, &type );

   // Retrieve Return Code
   SmGetRc( reply, &rc );

   storeMessage( "" );                     // clear message string
   m_bMsgWaiting = FALSE;                  // indicate no msg

   storePhrase( "" );                     // clear Phrase string
   m_bPhraseWaiting = FALSE;               // indicate no phrase

   if ( rc != SM_RC_OK )
   {
      SmGetRcName( reply, &p_msg );    // Retrieve message name

      if ( type != SM_RECOGNIZED_TEXT )// too numerous and uninteresting!
         storeMessage( p_msg );
   }

   switch ( type )
   {
      case SM_FOCUS_GRANTED:
         if (m_bRecognizing)
         {
            beginListening();
         }
         storeMessage( "SM_FOCUS_GRANTED" );
         break;

      case SM_FOCUS_LOST:
         storeMessage( "SM_FOCUS_LOST" );
         break;

      case SM_REQUEST_MIC_ON:
         storeMessage( "SM_REQUEST_MIC_ON" );
         beginListening();
         break;

      case SM_REQUEST_MIC_OFF:
         storeMessage( "SM_REQUEST_MIC_OFF" );
         stopRecognizing();
         break;

      case SM_REQUEST_DETACH:
         storeMessage( "SM_REQUEST_DETACH" );
         disconnect();
         break;

      case SM_RECOGNIZED_PHRASE:    // Grammar/FSG stuff only message
         storeMessage( "Got SM_RECOGNIZED_PHRASE" );
         if ( !processRecognizedPhrase( reply ) )
         {
             storeMessage( "Error on SM_RECOGNIZED_PHRASE" );
         }
         break;

      case SM_RECOGNIZED_WORD:     // both dictation and grammars
         storeMessage( "Got SM_RECOGNIZED_WORD" );
         if ( !processRecognizedWord( reply ) )
         {
            storeMessage( "Error on SmRecognizeNextWord" );
         }
         break;

      case SM_RECOGNIZED_TEXT:     // Dictation only message
         engineWords( reply );
         break;

      case SM_UTTERANCE_COMPLETED:
         storeMessage( "SM_UTTERANCE_COMPLETED" );
         break;

      case SM_REPORT_ENGINE_ERROR:
         storeMessage( "SM_REPORT_ENGINE_ERROR" );
         processEngineError(reply, rc);
         break;

      case SM_PLAY_WORDS_STATUS:
         m_playbackStatus = type;
         break;

      default:
         storeMessage( "*** Received unexpected SM message ***" );
         break;
   }

   return( rc );
}


//------------------------------------------------------------------------------
//  getMessage()
//------------------------------------------------------------------------------
//
//  This method resets the flag and returns the current message(s) from the 
//  engine.
//
//------------------------------------------------------------------------------

const char *VTProxy::getMessage( void )
{
   m_bMsgWaiting = FALSE;
   return m_message;
}


//------------------------------------------------------------------------------
//  storeMessage()
//------------------------------------------------------------------------------
//
//  This method formats and accumulates message(s) from the engine.
//
//------------------------------------------------------------------------------

void VTProxy::storeMessage(const char* pszFormat, ...)
{
   va_list vaArgList;
   char    *messageStart;

   if ( isMessageWaiting() )           // if already holding msg append
   {
      messageStart = m_messageEnd;     // point to end
   }
   else
   {
      messageStart = m_message;        // point to beginning
   }

   va_start(vaArgList, pszFormat);     // right out of K & R!
   vsprintf(messageStart, pszFormat, vaArgList);
   va_end(vaArgList);

   m_messageEnd = m_message + strlen( m_message );  

   m_bMsgWaiting = TRUE;               // indicate something to get
}


//------------------------------------------------------------------------------
//  getPhrase()
//------------------------------------------------------------------------------
//
//  This method resets the flag and returns the current reco'ed phrase(s) from 
//  the engine.
//
//------------------------------------------------------------------------------

const char *VTProxy::getPhrase( void )
{
   m_bPhraseWaiting = FALSE;
   return m_phrase;
}


//------------------------------------------------------------------------------
//  storePhrase()
//------------------------------------------------------------------------------
//
//  This method formats and accumulates phrases(s) from the engine.
//
//------------------------------------------------------------------------------

void VTProxy::storePhrase(const char* pszFormat, ...)
{
   va_list vaArgList;
   char    *phraseStart;

   if ( isPhraseWaiting() )
   {
      strcat( m_phrase, " " );
      phraseStart = m_phraseEnd + 1;
   }
   else
   {
      phraseStart = m_phrase;
   }

   va_start(vaArgList, pszFormat);
   vsprintf(phraseStart, pszFormat, vaArgList);
   va_end(vaArgList);

   m_phraseEnd = m_phrase + strlen( m_phrase );

   m_bPhraseWaiting = TRUE;
}


//------------------------------------------------------------------------------
//  getPhraseVocab()
//------------------------------------------------------------------------------
//
//  This method returns the vocab name from which the current phrase was reco'ed
//
//------------------------------------------------------------------------------

const char *VTProxy::getPhraseVocab( void )
{
   return m_phrase_vocab;
}


//------------------------------------------------------------------------------
//  storePhraseVocab()
//------------------------------------------------------------------------------
//
//  This method stores the name of the vocab from which the current phrase was
//  reco'ed.
//
//------------------------------------------------------------------------------

void VTProxy::storePhraseVocab(const char *vocabName)
{
   strcpy(m_phrase_vocab, vocabName);
}


//------------------------------------------------------------------------------
//  getStrAnnotation()
//------------------------------------------------------------------------------
//
//  This method returns string which contains annotations for the current 
//  phrase.
//
//------------------------------------------------------------------------------

const char *VTProxy::getStrAnnotation( void )
{
   m_bannotationWaiting = FALSE;
   
   return m_StrAnnotation; 
}


//------------------------------------------------------------------------------
//  getNumAnnotation()
//------------------------------------------------------------------------------
//
//  This method returns the numeric annotation for the current phrase.
//
//------------------------------------------------------------------------------

long VTProxy::getNumAnnotation( void )
{ 
   m_bannotationWaiting = FALSE;

   return m_NumAnnotation;
}


//------------------------------------------------------------------------------
//  getBadWords()
//------------------------------------------------------------------------------
//
//  This method returns string which contains annotations for the current 
//  phrase.
//
//------------------------------------------------------------------------------

const char *VTProxy::getBadWords( BOOL reset )
{
   if ( reset )
      m_bBadWordWaiting = FALSE;
   
   return m_badWords; 
}


//------------------------------------------------------------------------------
//  engineWords()
//------------------------------------------------------------------------------
//
//  This method takes a SM_MSG of type SM_RECOGNIZED_TEXT and makes engine
//  calls to retrieve firm then infirm words from it.  Firm words are added
//  to the wordlist by calls to VTProxy::addWordToList() and infirm words
//  are concatenated into the m_infirmbuff string
//
//------------------------------------------------------------------------------

int VTProxy::engineWords( SM_MSG reply )
{
   int rc;                             // return code
   int state = 0;               // processing state: 0=firm, 1=infirm, 2=done
   unsigned long k;                    // just a kounter :)
   unsigned long wordcount;            // how many words engine has for us
   SM_WORD *pword;                     // utility pointer

   strcpy( m_infirmbuff, "" );         // throw away any existing infirm words

   rc = SmGetFirmWords( reply, &wordcount, &pword );  // start with firm words

   // this loop processes firm words, then infirm words
   while (state < 2)
   {
      if ( rc == SM_RC_OK )
      {
         for (k = 0; k < wordcount; k++)  // each (in)firm word
         {
            if ( pword->spelling_size )   // word is not NULL
            {

               if ( state == 0 )          // firm words, keep around
               {
                  addWordToList( pword );
               }

               else                       // infirm words, lump into a buffer
               {
                  // TBD - account for undersized infirm buffer
                  strcat( m_infirmbuff, pword->spelling );
                  strcat( m_infirmbuff, " " );
               }
            }

            else                          // word is NULL, rejected noise
            {
               storeMessage( "Rejected noise" );  // TBD - why this never happens?
            }

            pword++;                   // proceed to next word
         }
      }

      state++;

      rc = SmGetInfirmWords( reply, &wordcount, &pword );
   }

   return( rc );
}


//------------------------------------------------------------------------------
//  addWordToList()
//------------------------------------------------------------------------------
//
//  This method takes a pointer to a SM_WORD structure which comes from the
//  engine, creates a new VTWord object and adds it to the VTProxy wordlist
//  at the end of the list.
//
//------------------------------------------------------------------------------

BOOL VTProxy::addWordToList( SM_WORD *pword )
{
   VTWord *pVTWord = NULL;             // utility pointer
   VTWord *p_insert = getLastWord();   // point to end of list

   pVTWord = new VTWord();
   m_wordlist.addNode( pVTWord );      // add new word to list

   // store position of word in the application
   pVTWord->appIndex = m_appIndex;
   m_appIndex += pword->spelling_size;

   // put contents of engine word into app word list object
   pVTWord->tag = pword->tag;
   pVTWord->spelling_size = pword->spelling_size;

   pVTWord->spelling =
      (char *) malloc( pword->spelling_size * sizeof( char ));

   if ( pVTWord->spelling )            // allocation worked
      strcpy( pVTWord->spelling, pword->spelling );

   pVTWord->setState( VTWORD_FIRM );   // each word knows it's firm/infirm

   m_bwordWaiting = TRUE;              // indicate word(s) ready for display

   return( TRUE );
}


//------------------------------------------------------------------------------
//  allWordsProcessed()
//------------------------------------------------------------------------------
//
//  This method is a signal from the caller that all words have been read from
//  the wordlist.
//
//------------------------------------------------------------------------------

void VTProxy::allWordsProcessed( void )
{
   m_bwordWaiting = FALSE;                // app has displayed all words
   m_lastDisplayedWord = getLastWord();   // point to end of list
}


//------------------------------------------------------------------------------
//  correctSelection()
//------------------------------------------------------------------------------
//
//  This method implements a RUDIMENTARY form of word correction. An
//  application can use this method to replace a word with the next
//  alternative  word offered by the engine.  The implementation
//  wraps back to the first choice after the last choice.  This
//  method introduces the concept of maintaining sychronization of
//  the word list and the text stored in the application's control
//  (i.e. Windows Multi-line edit control).
//
//  LIMITATIONS:
//  Typically an application will display a list of all of the
//  alternatives so the user can select one.  Another typical feature
//  which is not implemented here would be to offer the user the
//  ability to enter the correct word explicitly and have the word
//  added should it not already exist.  This example is further
//  limited in that it does not support correcting two words into one,
//  this is important as explained in the documentation of
//  SmQueryAlternates() in the API reference.
//
//  APPROACH:
//  The engine is called to play the audio of the word or utterance in
//  question, then queried for alternative words. The word stored in
//  the proxy class wordlist is replaced with the next alternate, and
//  the appIndex attribute of all words which follow get updated to
//  maintain synchronization.
//
//------------------------------------------------------------------------------

VTWord * VTProxy::correctSelection( int selFirst, int selLast )
{
   int rc;                             // return code from the engine
   unsigned long i;                    // loop counter
   unsigned long altIndex;             // index of an alternate word
   unsigned long count;                // count of alternate words
   int delta;                          // diff between size of old/new words
   long tags[1];                       // holds tags of words to be corrected
   SM_MSG reply;                       // SMAPI call reply structure
   SM_WORD * pWord;                    // a utility word pointer
   VTWord * pWalk;                     // pointer to traverse list for synch
   VTWord * pVTWord = getFirstWordNU();      // start at beginning of list

   // first find the word being corrected in the wordlist by matching the
   // GUI's current selection to the appIndex attribure stored in each
   // VTWord object

   while ( pVTWord )                         // not at end of (empty) list
   {
      if ( pVTWord->appIndex == selFirst )   // find the word in the list
         break;
      else
         pVTWord = getNextWordNU( pVTWord ); // keep going
   }

   // either the word has been found, or we ran off the end of the list

   if ( pVTWord != NULL )              // did not run off end of list
   {
      tags[0] = pVTWord->tag;          // ONLY CORRECTING ONE WORD (see above)

      // TBD error handling...
      rc = SmQueryAlternates( 1, tags, &reply );      // get all alternates

      rc = SmGetAlternates( reply, &count, &pWord );  // set up looping

      if ( count )                                    // more than 0 alt's
      {
         altIndex = pVTWord->setNextAlt( count );     // which alt is next?

         for ( i = 1; i < altIndex; i++ )             // traverse alt list
            pWord++;

         // The word string in the wordlist object gets re-sized
         free( pVTWord->spelling );
         pVTWord->spelling =
            (char *) malloc( pWord->spelling_size * sizeof( char ) );

         if ( pVTWord->spelling )                      // allocation OK
         {
            delta = pWord->spelling_size;              // size of new word
            delta -= pVTWord->spelling_size;           // ...now size delta

            // word obect gets updated with new string and size
            pVTWord->spelling_size = pWord->spelling_size;
            strcpy( pVTWord->spelling, pWord->spelling );

            // synchronize appIndex between GUI control and wordlist
            pWalk = getNextWordNU( pVTWord );
            while ( pWalk )                            // not at end of list
            {
               pWalk->appIndex += delta;               // adjust
               pWalk = getNextWordNU( pWalk );         // traverse
            }
         }
      }

      rc = SmPlayWords( 1, tags, SM_PLAY_WORDS_CONTIGUOUS, &reply );
      // (rc == SM_RC_OK) means engine knows I want to play the words...
   }
   else                                // ran off end of list
      pVTWord = NULL;

   return( pVTWord );
}


//------------------------------------------------------------------------------
//  defineGrammar()
//------------------------------------------------------------------------------
//  Defines the current grammar file to the speech engine.
//------------------------------------------------------------------------------

BOOL VTProxy::defineGrammar( const char *fsgName,
                             const char *vocabularyName )
{
   SM_MSG reply;
   int rc;
   BOOL bVocabAlreadyDefined = FALSE;
   BOOL bSuccess = FALSE;

   if ( isVocabDefined(&bVocabAlreadyDefined, vocabularyName ) )
   {
      char tempVocab[_MAX_PATH];
      strcpy( tempVocab, vocabularyName );
      char tempFsgName[_MAX_PATH];
      strcpy( tempFsgName, fsgName );

      if (!bVocabAlreadyDefined)
      {
         // Grammar is not defined...define it.
         rc = SmDefineGrammar(tempVocab, tempFsgName, 0, &reply);

         if (rc != SM_RC_OK)
         {
             storeMessage("Error on SmDefineGrammar: %s, rc=%d", 
                          SmReturnRcDescription(rc), rc);
         }
         else
         {
            bSuccess = TRUE;
         }
      }
      else
      {
         storeMessage("Vocabulary <%s> alrady defined",
                       vocabularyName);
      }
   }

   return ( bSuccess );
}


//------------------------------------------------------------------------------
//  defineWordList()
//------------------------------------------------------------------------------
//  Defines the current grammar file to the speech engine.
//------------------------------------------------------------------------------

BOOL VTProxy::defineWordList( const char *WordListName,
                             const char *vocabularyName )
{
   BOOL bVocabAlreadyDefined = FALSE;
   BOOL bSuccess = FALSE;

   SM_VOCWORD  **pVocPtrs;      // Dynamic array of pointers to 
                                // vocabulary structures
   int         i;
   int         iNumWords = 0;
   int         tempSize;
   char        *tempStr;
   int         MAXSIZE = 1000;
   char        buff[ 1000 ];
   FILE      * wdlfile;


   if ( isVocabDefined(&bVocabAlreadyDefined, vocabularyName ) )
   {
      char tempVocab[_MAX_PATH];
      strcpy( tempVocab, vocabularyName );
      char tempWordListName[_MAX_PATH];
      strcpy( tempWordListName, WordListName );

      if (!bVocabAlreadyDefined)
      {
         if( (wdlfile = fopen( WordListName, "rt" )) == NULL )
         {
            return( FALSE );
         }

         while (!feof( wdlfile ))       // read the whole file, count lines
         {
            if ( fgets( buff, MAXSIZE, wdlfile ) )   // handle eof
            {
               if ( buff[0] != '\n' )                // skip blank lines
                  iNumWords++;                       // count actual
            }
         }
         rewind( wdlfile );                          // start over

         if ( !iNumWords )                           // no words!
         {
            storeMessage( "Error: no words found in <%s>", vocabularyName );
            return( bSuccess );
         }

         pVocPtrs = (SM_VOCWORD **)malloc(sizeof(SM_VOCWORD *) * iNumWords);

         for (i=0; i < iNumWords; i++)
         {
            // allocate & build vocabulary word structures
            pVocPtrs[i] = (SM_VOCWORD *)malloc(sizeof(SM_VOCWORD));
            pVocPtrs[i]->flags = 0;            // reserved value

            tempStr = (char *)malloc( MAXSIZE );

            fgets( tempStr, MAXSIZE, wdlfile );
            while ( tempStr[0] == '\n' )
               fgets( tempStr, MAXSIZE, wdlfile );

            tempSize = strlen( tempStr ) - 1;
            if ( tempStr[ tempSize ] == '\n' )   // last word/phrase may not have '\n'
               tempStr[ tempSize ] = '\0';       // replace '\n' with '\0'

            pVocPtrs[i]->spelling_size = tempSize;
            pVocPtrs[i]->spelling = tempStr;
         }

         fclose( wdlfile );

         // Define the vocabulary with SMAPI
         tempSize = strlen(tempVocab);
         bSuccess = defineVocabulary( tempVocab, iNumWords, pVocPtrs);

         // free up storage no longer needed
         for (i=0; i < iNumWords; i++)
         {
            free( pVocPtrs[i]->spelling );
            free( pVocPtrs[i]);
         }
         free( pVocPtrs );
      }
      else
      {
         storeMessage("Vocabulary <%s> alrady defined",
                       vocabularyName);
      }
   }

   return ( bSuccess );
}


//------------------------------------------------------------------------------
//  defineVocabulary()
//------------------------------------------------------------------------------
//  Defines the current grammar file to the speech engine.
//------------------------------------------------------------------------------

BOOL VTProxy::defineVocabulary( const char *vocabularyName,
                                int        iNumWords,
                                SM_VOCWORD **pVocPtrs)
{
   SM_MSG reply;
   int rc;
   BOOL bVocabAlreadyDefined = FALSE;
   unsigned long badcount = 0;
   SM_VOCWORD *pBadVocWords;

   if ( isVocabDefined(&bVocabAlreadyDefined, vocabularyName ) )
   {

      char tempVocab[_MAX_PATH];
      strcpy( tempVocab, vocabularyName );

      if (!bVocabAlreadyDefined)
      {
         // Vocabulary is not defined...define it.
         rc = SmDefineVocab(tempVocab, iNumWords, pVocPtrs, &reply);

         if (rc == SM_RC_OK)
         {
             // see if any of the words have no pronouniation available.
             rc = SmGetVocWords( reply, &badcount, &pBadVocWords );  
             if ( rc == SM_RC_OK )
             {
                if( badcount )
                {
                   unsigned long i = 0;
                   m_bBadWordWaiting = TRUE;
                   m_badWords[0] = '\0';
                   while( i < badcount )
                   {
                      strcat( m_badWords, "\"" );
                      strcat( m_badWords, pBadVocWords[i].spelling );
                      strcat( m_badWords, "\", " );
                      i++;
                   }

                   rc = (int) badcount;
                }
             }
             else
             {
                storeMessage("Error on SmGetVocWord: %s, rc=%d", 
                             SmReturnRcDescription(rc), rc);
             }
         }
         else
         {
             storeMessage("Error on SmDefineVocab: %s, rc=%d", 
                          SmReturnRcDescription(rc), rc);
         }
      }

   }

   return (rc == SM_RC_OK);
}


//------------------------------------------------------------------------------
//  enableVocabulary()
//------------------------------------------------------------------------------
//  Enables the vocabulary in the speech engine.
//------------------------------------------------------------------------------

BOOL VTProxy::enableVocabulary( const char *vocabularyName )
{
   SM_MSG  reply;
   int     rc;

   char tempVocab[_MAX_PATH];
   strcpy( tempVocab, vocabularyName );

   rc = SmEnableVocab(tempVocab, &reply);
   if (rc != SM_RC_OK)
   {
      storeMessage("Error on SmEnableVocab of <%s>: %s, rc=%d", 
                vocabularyName, SmReturnRcDescription(rc), rc);
   
   }
   
   return (rc == SM_RC_OK);
}


//------------------------------------------------------------------------------
//  isVocabDefined()
//------------------------------------------------------------------------------
//  Determines whether or not the currently vocab is already defined.
//------------------------------------------------------------------------------

BOOL VTProxy::isVocabDefined(BOOL* bResult,
                            const char *theVocabulary )
{
   SM_MSG reply;
   int rc;
   ULONG nNumVocabs;
   char** pVocabs;

   *bResult = FALSE;

   rc = SmQueryVocabs(&reply);

   if (rc == SM_RC_OK)
   {
      rc = SmGetVocabList(reply, &nNumVocabs, &pVocabs);
      if (rc == SM_RC_OK)
      {
         for (UINT i = 0; i < nNumVocabs && !(*bResult); i++)
         {
            if (strcmp(theVocabulary, pVocabs[i]) == 0)
            {
               *bResult = TRUE;
            }
         }
      }
      else
      {
         storeMessage("Error on SmGetVocabList: %s, rc=%d", 
                      SmReturnRcDescription(rc), rc);
      }

   }
   else
   {
      storeMessage("Error on SmQueryVocabs: %s, rc=%d", 
                   SmReturnRcDescription(rc), rc);
   }

   return (rc == SM_RC_OK);
}


//------------------------------------------------------------------------------
//  isVocabEnabled()
//------------------------------------------------------------------------------
//  Determines whether or not the currently vocab is already enabled.
//------------------------------------------------------------------------------

BOOL VTProxy::isVocabEnabled( const char *theVocabulary )
{
   
   SM_MSG reply;
   int    rc;
   ULONG  nNumVocabs;
   char** pVocabs;
   BOOL   enabled = FALSE;

   rc = SmQueryEnabledVocabs(&reply);

   if (rc == SM_RC_OK)
   {
      rc = SmGetVocabList(reply, &nNumVocabs, &pVocabs);
      if (rc == SM_RC_OK)
      {
         for (UINT i = 0; i < nNumVocabs && !(enabled); i++)
         {
            if (strcmp(theVocabulary, pVocabs[i]) == 0)
            {
               enabled = TRUE;
            }
         }
      }
      else
      {
         storeMessage("Error on SmGetVocabList: %s, rc=%d", 
                      SmReturnRcDescription(rc), rc);
      }

   }
   else
   {
      storeMessage("Error on SmQueryEnabledVocabs: %s, rc=%d", 
                   SmReturnRcDescription(rc), rc);
   }

   return ( enabled );
}


//------------------------------------------------------------------------------
//  startRecognizing()
//------------------------------------------------------------------------------
//  Initiates recognition processing
//------------------------------------------------------------------------------

BOOL VTProxy::startRecognizing()
{
   SM_MSG reply;
   int rc;

   rc = SmRequestFocus(&reply);

   switch (rc)
   {
      case SM_RC_FOCUS_GRANTED:

         // Already have focus, go ahead and start listening.
         if ( beginListening() )
         {
            m_bRecognizing = TRUE;
         }
         break;

      case SM_RC_OK:

         // Will begin listening after SM_FOCUS_GRANTED arrives.
         m_bRecognizing = TRUE;
         break;

      default:
         storeMessage("Error on SmRequestFocus: %s, rc=%d", 
                      SmReturnRcDescription(rc), rc);
   }

   return ( m_bRecognizing );
}


//------------------------------------------------------------------------------
//  stopRecognizing()
//------------------------------------------------------------------------------
//  Terminates recognition processing
//------------------------------------------------------------------------------

BOOL VTProxy::stopRecognizing()
{
   SM_MSG  reply;
   int     rc;
   BOOL    stopOK = FALSE;

   rc = SmRequestFocus( &reply );

   // SM_RC_OK means the engine now knows this app wants speech 
   // focus and will give it to this app as soon as it can.
   //
   // SM_RC_FOCUS_GRANTED means this app already had focus,
   // this happens for example, when SmConnect is called and
   // this is the only SMAPI client application connected.

   if ( rc == SM_RC_OK || SM_RC_FOCUS_GRANTED )
   {
      rc = SmMicOff( &reply );

      if ( rc == SM_RC_OK || rc == SM_RC_MIC_ALREADY_OFF )
      {
         SmSet( SM_ENABLE_EXCLUSIVE_VOCABS, FALSE, &reply ); // for dictation

         m_bRecognizing = FALSE;
         stopOK = TRUE;
      }
      else
      {
         storeMessage( "Error on SmMicOff: %s, rc=%d", 
                       SmReturnRcDescription(rc), rc);
      }
   }
   else
   {
      storeMessage( "Error on SmRequestFocus: %s, rc=%d", 
                    SmReturnRcDescription(rc), rc);
   }

   return( stopOK );
}


//------------------------------------------------------------------------------
//  stopDictation()
//------------------------------------------------------------------------------
//  Terminates dictation processing
//------------------------------------------------------------------------------

BOOL VTProxy::stopDictation()
{
   BOOL stopOK = FALSE;

   if( m_connected )
   {
      if ( m_bRecognizing )
      {
         if ( stopRecognizing() )
         {
            disableGrammar( "stopcmd" );
            disableGrammar( "text" );
            stopOK = TRUE;
         }
      }
      else
      {
         storeMessage( "Error: stopDictation() called while not recognizing" );
      }
   }
   else
   {
      storeMessage( "Error: stopDictation() called while not connected" );
   }


   return( stopOK ) ;
}


//------------------------------------------------------------------------------
//  beginListening()
//------------------------------------------------------------------------------
//  Terminates recognition processing
//------------------------------------------------------------------------------

BOOL VTProxy::beginListening()
{
   SM_MSG reply;


   int rc = SmMicOn(&reply);

   if ( rc == SM_RC_OK || rc == SM_RC_MIC_ALREADY_ON )
   {
 
      rc = SmRecognizeNextWord(&reply);
      if (rc != SM_RC_OK)
      {
         storeMessage("Error on SmRecognizeNextWord: %s, rc=%d", 
                      SmReturnRcDescription(rc), rc);
      }
   }
   else
   {
      storeMessage("Error on SmMicOn: %s, rc=%d", 
                   SmReturnRcDescription(rc), rc);
   }

   return( rc == SM_RC_OK );
}


//------------------------------------------------------------------------------
//  processRecognizedPhrase()
//------------------------------------------------------------------------------
//  Handles the phrase recognized by the engine.
//------------------------------------------------------------------------------

BOOL VTProxy::processRecognizedPhrase(SM_MSG reply)
{

   SM_WORD* pWords;
   ULONG nNumWords, nFlags;
   SM_MSG replySync;

   int rc = SmGetFirmWords(reply, &nNumWords, &pWords);

   if (rc == SM_RC_OK)
   {
      rc = SmGetPhraseState(reply, &nFlags);
      if (rc == SM_RC_OK)
      {

         m_phrase[0] = '\0'; // initialize the phrase buffer
         if (nFlags & SM_PHRASE_REJECTED)
         {
            storePhrase("??");
            storeMessage(" ??");
         }
         else
         {
            processAnnotations( &reply );
         }


         storeMessage(" Recognized:");

         ULONG nCounter = nNumWords;
         while (nCounter > 0)
         {
            storePhrase("%s", (LPCTSTR)pWords->spelling);
            storeMessage(" <%s>", (LPCTSTR)pWords->spelling);
            pWords++;
            nCounter--;
         }

         char  *vocabName;
         rc = SmGetVocabName(reply, &vocabName );
         if (rc == SM_RC_OK)
         {
            storeMessage(" in vocabulary <%s>", vocabName);
            storePhraseVocab( (LPCTSTR)vocabName );

            rc = SmRecognizeNextWord(&replySync);
            if (rc != SM_RC_OK)
            {
               storeMessage("Error on SmRecognizeNextWord: %s, rc=%d", 
                            SmReturnRcDescription(rc), rc);
            }
         }
         else
         {
            storeMessage("Error on SmGetVocabName: %s, rc=%d", 
                         SmReturnRcDescription(rc), rc);
         }

      }
      else
      {
         storeMessage("Error on SmGetPhraseState: %s, rc=%d", 
                      SmReturnRcDescription(rc), rc);
      }
   }
   else
   {
      storeMessage("Error on SmGetFirmWords: %s, rc=%d", 
                   SmReturnRcDescription(rc), rc);
   }

   return (rc == SM_RC_OK);
}


//------------------------------------------------------------------------------
//  processRecognizedWord()
//------------------------------------------------------------------------------
//  Handles the word recognized by the engine.
//------------------------------------------------------------------------------

BOOL VTProxy::processRecognizedWord(SM_MSG reply)
{

   SM_WORD *pWords;
   ULONG    nNumWords;
   SM_MSG   replySync;

   int rc = SmGetFirmWords(reply, &nNumWords, &pWords);
   if (rc == SM_RC_OK)
   {
      m_phrase[0] = '\0'; // initialize the phrase buffer

      ULONG nCounter = nNumWords;
      while (nCounter > 0)
      {
         if ( ( strlen( (LPCTSTR)pWords->spelling ) == 0 )&&
            ( strlen( (LPCTSTR)pWords->vocab ) == 0 ) )
         {
            storePhrase( "??" );
            storeMessage(" [ ?? Unrecognized Word ]",
                           (LPCTSTR)pWords->spelling,
                           (LPCTSTR)pWords->vocab);
         }
         else
         {
            storePhrase("%s", (LPCTSTR)pWords->spelling);
            storePhraseVocab( (LPCTSTR)pWords->vocab );

            storeMessage(" [ Recognized: <%s> in vocabulary <%s> ]",
               (LPCTSTR)pWords->spelling,
               (LPCTSTR)pWords->vocab);

            if ( !strcmp( "stopcmd", pWords->vocab ) )   // special case!
               stopDictation();
         }
         pWords++;
         nCounter--;
      }

      rc = SmRecognizeNextWord(&replySync);
      if (rc != SM_RC_OK)
      {
         storeMessage("Error on SmRecognizeNextWord: %s, rc=%d", 
                      SmReturnRcDescription(rc), rc);
      }

   }
   else
   {
      storeMessage("Error on SmGetFirmWords: %s, rc=%d", 
                   SmReturnRcDescription(rc), rc);
   }

   return (rc == SM_RC_OK);
}


//------------------------------------------------------------------------------
//  disableGrammar()
//------------------------------------------------------------------------------
//  disables the currently defined grammars.
//------------------------------------------------------------------------------

BOOL VTProxy::disableGrammar( const char *vocabularyName )
{
   SM_MSG reply;
   int rc = SM_RC_OK;

   if (strlen( vocabularyName ) > 0)
   {

      char tempStr[_MAX_PATH];
      strcpy( tempStr, vocabularyName );

      rc = SmDisableVocab( tempStr, &reply);
      if (rc != SM_RC_OK)
      {
         storeMessage("Error on SmDisableVocab: %s, rc=%d", 
            SmReturnRcDescription(rc), rc);
      }
   }

   return (rc == SM_RC_OK);
}


//------------------------------------------------------------------------------
//  ProcessEngineError()
//------------------------------------------------------------------------------
//  Handles errors reported by the engine (basically, displays a message).
//------------------------------------------------------------------------------

void VTProxy::processEngineError(SM_MSG reply, int rcEngine)
{
   ULONG nSeverity;

   int rc = SmGetSeverity(reply, &nSeverity);

   if (rc == SM_RC_OK)
   {
      switch (nSeverity)
      {
         case SM_ENGINE_INFO:
            storeMessage("*** SM_ENGINE_INFO: %d ***", rcEngine);
            break;

         case SM_ENGINE_WARNING:
            storeMessage("*** SM_ENGINE_WARNING: %d ***", rcEngine);
            break;

         case SM_ENGINE_ERROR:
            storeMessage("*** SM_ENGINE_ERROR: %d ***", rcEngine);
            break;

         case SM_ENGINE_TERMINAL_ERROR:
            storeMessage("*** SM_ENGINE_TERMINAL_ERROR: %d ***", rcEngine);
            break;

         default:
            storeMessage("*** UNKNOWN SEVERITY: %d ***", rcEngine);
            break;
      }

   }
   else
   {
      storeMessage("*** SM_REPORT_ENGINE_ERROR SmGetSeverityFailed, rc=%d", rc);
   }

   return;
}


//------------------------------------------------------------------------------
//  undefineVocabulary()
//------------------------------------------------------------------------------
//  This method undefines the current grammar file to the speech engine.
//------------------------------------------------------------------------------

BOOL VTProxy::undefineVocabulary( const char *vocabularyName )
{
   SM_MSG reply;
   int rc;

   char tempVocab[_MAX_PATH];
   strcpy( tempVocab, vocabularyName );

   // Vocabulary is not defined...define it.
   rc = SmUndefineVocab(tempVocab, &reply);

   if (rc != SM_RC_OK)
   {
      storeMessage("Error on SmUndefineVocab: %s, rc=%d", 
                    SmReturnRcDescription(rc), rc);
   }

   return (rc == SM_RC_OK);
}


//------------------------------------------------------------------------------
//  processAnnotations()
//------------------------------------------------------------------------------
//  This method extracts grammar annotations and puts them into a string.
//
//  It shows how SmGetAnnotations sets a pointer to a list of Annotations
//  and a counter value for looping.  This implementation is rather specialized
//  in that it only bothers with string and numeric type annotations. For
//  numeric annotations it only expects one per phrase (the last annotation is
//  stored.  For strings the quotes are stripped and the annotations are all 
//  appended into m_StrAnnotation separated by blank spaces.   Unexpected 
//  annotations are handled by returning non-zero.
//
//------------------------------------------------------------------------------

BOOL VTProxy::processAnnotations( const SM_MSG * reply )
{
   int rc = SM_RC_OK;
   ULONG i;
   ULONG nNumWordsA;
   SM_ANNOTATION * annotations;
   char temp[256];

   temp[ 0 ] = m_StrAnnotation[0] = '\0';      // init the annotation string
   m_bannotationWaiting = FALSE;

   rc = SmGetAnnotations( *reply, &nNumWordsA, &annotations );

   if ( rc == SM_RC_OK )
   {
      for ( i = 0; i < nNumWordsA; i++ )
      {
         switch( annotations->type )
         {
            case SM_ANNOTATION_NONE:
            case SM_ANNOTATION_OTHER:
               rc = 1;                 // signal unhandled annotation type
               break;

            case SM_ANNOTATION_NUMERIC:
               m_NumAnnotation = annotations->annodata.numeric;
               m_bannotationWaiting = TRUE;
               break;


            case SM_ANNOTATION_STRING:
               strcat( m_StrAnnotation, annotations->annodata.string );
               strcat( m_StrAnnotation, " " );
               m_bannotationWaiting = TRUE;
               break;

            default:
               storeMessage( "ERROR: UNKNOWN ANNOTATION TYPE! type = %d", 
                              annotations->type );
            break;
         }

         ++annotations;
      }
   }
   else
      storeMessage("Error on SmGetAnnotations: %s, rc=%d", 
                    SmReturnRcDescription(rc), rc);

   return( rc == SM_RC_OK );
}


//------------------------------------------------------------------------------
//  storeLangCode()
//------------------------------------------------------------------------------
//
// This function places a two byte language code (US, UK, ES, IT, FR or GR)
// into the internal buffer. The reply structure should be the one returned
// by the CONNECT
//------------------------------------------------------------------------------

BOOL VTProxy::storeLangCode( SM_MSG reply)   // returns two byte language code
{
   int            rc;                                   // SMAPI return code
   unsigned long  ulNumOfLangs;                         // size and
   char**         apchLangs;                            //  list of languages

   // return empty string in case of trouble
   m_achLangCode[0] = '\0';

   // check for a connected engine 
   if ( !isConnected() )
   {
      return FALSE;
   }

   // fetch in our language code
   ulNumOfLangs = 0;
   apchLangs    = NULL;

   rc = SmGetLanguages( reply, &ulNumOfLangs, &apchLangs);

   if ( (rc != SM_RC_OK) || (ulNumOfLangs == 0) || (apchLangs == NULL) )
   {
      return FALSE;                    // error on query
   }

   // extract active language, which should always be first
   char * pchFirst = apchLangs[0];
   if ( pchFirst == NULL )
   {
      return FALSE;                    // something went wrong
   }

   // check whether we got good info or not
   // good info has format "XX_YY",
   // where: YY == XX       if XX == GR, FR, IT or ES
   //        YY is UK or US if XX == EN
  if ( strlen( pchFirst) != 5 || pchFirst[2] != '_' )
   { 
      return FALSE;                    // badly formatted language code
   }
   else
      strcpy( m_achLangCode, pchFirst); // good info, worthy of being unpacked
 
   return TRUE;                        // all is well
}

