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

#include <stdlib.h>                    // defines free()

#include "Vtword.h"                    // class definition

//-----------------------------------------------------------------------------
//

VTWord::VTWord( void ) :
    ListNode()
{
   m_state = 0;
   m_currentAlt = 1;
   spelling = NULL;
}


//-----------------------------------------------------------------------------
//

VTWord::~VTWord( void )
{
   if ( spelling )
      free( spelling );
}


//-----------------------------------------------------------------------------
//

unsigned long VTWord::setNextAlt( unsigned long max )
{ 
   m_currentAlt++;

   if ( m_currentAlt > max)
      m_currentAlt = 1;

   return( m_currentAlt );
}

//-----------------------------------------------------------------------------
//

//-----------------------------------------------------------------------------
//

