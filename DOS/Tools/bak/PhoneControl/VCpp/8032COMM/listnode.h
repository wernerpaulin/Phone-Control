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
// File:    LISTNODE.HPP
//
// Purpose: Defines the ListNode class, objects derived from this class
//          can be managed by the DoublyLinkedList class providing an
//          oriented doubly linked list dynamic data structure.
//
//          Typically a new 'listable' class is derived from ListNode
//          and a DoublyLinkedList object is created.  Objects of the
//          new class derived from ListNode are added to the 
//          DoublyLinkedList object using DoublyLinkedList::addNode().
//
//-----------------------------------------------------------------------------

#ifndef INCL_LISTNODE                  // prevent recursive inclusion
#define INCL_LISTNODE

#include <iostream.h>                  // defines NULL


class ListNode
{
   private:
      ListNode * nextPtr;              // points to next node in the list
      ListNode * prevPtr;              // points to previous node in the list
      unsigned long nindex;            // identifies a node

   public:
      ListNode( void );                // ctor
      virtual ~ListNode( void );       // dtor

      ListNode * getNextPtr( void );             // returns pointer to next
      void setNextPtr( ListNode * newNext );     // sets pointer to next
      ListNode * getPrevPtr( void );             // returns pointer to previous
      void setPrevPtr( ListNode * newPrev );     // sets pointer to previous

      void setIndex( unsigned long newIndex )    // set node ID
         { nindex = newIndex; }

      unsigned long getIndex( void )             // return node ID
         { return( nindex ); }
};

#endif
