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
//   TBD - document this class
//
//-----------------------------------------------------------------------------

#include "listnode.h"                  // ListNode class definition

//-----------------------------------------------------------------------------
//

ListNode::ListNode( void )
{
   nextPtr = prevPtr = NULL;           // non-assumimg basic initialization
   nindex = 0L;
}

//-----------------------------------------------------------------------------
//

ListNode::~ListNode( void )
{
}

//-----------------------------------------------------------------------------
//

ListNode * ListNode::getNextPtr( void )
{
   return( nextPtr );
}

//-----------------------------------------------------------------------------
//

void ListNode::setNextPtr( ListNode * newNext )
{
   nextPtr = newNext;
}

//-----------------------------------------------------------------------------
//

ListNode * ListNode::getPrevPtr( void )
{
   return( prevPtr );
}

//-----------------------------------------------------------------------------
//

void ListNode::setPrevPtr( ListNode * newPrev )
{
   prevPtr = newPrev;
}

