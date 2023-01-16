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
// File:    DLLIST.HPP
//
// Purpose: Defines the SdoublyLinkedList class which provides an object
//          oriented doubly linked list dynamic data structure.
//

#ifndef INCL_DLLIST
#define INCL_DLLIST

#include "listnode.h"

class DoublyLinkedList
{
   private:
      ListNode * headNode;
      ListNode * tailNode;
      ListNode * currentNode;
      ListNode * temp1;
      unsigned long count;
   public:
      DoublyLinkedList( void );
      virtual ~DoublyLinkedList( void );
      void addNode( ListNode * newNode );
 //   void addHeadNode( ListNode * newNode );
      ListNode * deleteCurrentNode( void );
      void deleteAllNodes( void );
      ListNode * getFirst( void );
      ListNode * getFirstNU( void );
      ListNode * getNext( void );
      ListNode * getNextNU( ListNode * aNodePtr );
      ListNode * getCurrent( void );
      ListNode * getPrev( void );
      ListNode * getPrevNU( ListNode * aNodePtr );
      ListNode * getLast( void );
      ListNode * getLastNU( void );
      unsigned long getCount( void ) { return( count ); }
};

#endif
