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
//-----------------------------------------------------------------------------
//
//  TBD - Document this class
//

#ifndef INCL_VTWORD                    // prevent recursive inclusion
#define INCL_VTWORD

#include "smapi.h"
#include "listnode.h"                  // inheret from listnode

#define VTWORD_INFIRM    0
#define VTWORD_FIRM      1

//-----------------------------------------------------------------------------
//

class VTWord : public ListNode
{
   private:
      int m_state;                     // object state
      unsigned int m_currentAlt;       // index of current alternate word

   public:
      short spelling_size;
      char * spelling;
      long tag;
      int appIndex;


      VTWord( void );                  // ctor
      ~VTWord( void );                 // dtor

      int getState( void ) 
         { return ( m_state ); }

      void setState( int newState ) 
         { m_state = newState; }

      unsigned long getAltIndex( void )
         { return( m_currentAlt ); }

      unsigned long setNextAlt( unsigned long max );
};

#endif
