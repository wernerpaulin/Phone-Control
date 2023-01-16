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
// File:    DLLIST.CPP
//
// Purpose: Implements DoublyLinkedList class methods providing an object
//          oriented doubly linked list dynamic data structure.
//

#include "dllist.h"                    // defines the list class

//----------------------------------------------------------------------------
//  DoublyLinkedList()
//
//  Purpose: class constructor
//

DoublyLinkedList::DoublyLinkedList( void )
{
   headNode = NULL;
   tailNode = NULL;
   currentNode = NULL;
   count = 0L;
}

//----------------------------------------------------------------------------
//  ~DoublyLinkedList()
//
//  Purpose: class destructor
//
//

DoublyLinkedList::~DoublyLinkedList( void )
{
   deleteAllNodes();
}

//----------------------------------------------------------------------------
//  addNode()
//
//  Purpose: inserts the a new node into the list BETWEEN CURRENT AND
//           IT'S NEXT.
//

void DoublyLinkedList::addNode( ListNode * newNode )
{
   if (headNode != NULL)               // list is NOT empty
   {
      if ( currentNode == NULL )       // current needs to be reset!
         currentNode = tailNode;

      if ( currentNode->getNextPtr() != NULL ) // current is NOT last
      {
         newNode->setNextPtr( currentNode );
         newNode->setPrevPtr( currentNode->getPrevPtr() );
      }
      else                             // current IS last
      {
         newNode->setNextPtr( NULL );
         newNode->setPrevPtr( currentNode );
         currentNode->setNextPtr( newNode );
         tailNode = newNode;
      }
   }

   else                                // list was empty
   {
      headNode = tailNode = newNode;
      newNode->setNextPtr( NULL );
      newNode->setPrevPtr( NULL );
   }

   currentNode = newNode;
   count += 1;
}


//----------------------------------------------------------------------------
//  deleteCurrentNode()
//
//  Purpose: removes the node pointed to by 'currentNode' from the list
//           and returns a pointer to it.  'currentNode' is moved to
//           the next node in the list unless there is no next, in which
//           case current is moved to the previous node.
//

ListNode * DoublyLinkedList::deleteCurrentNode( void )
{
   temp1 = currentNode;

   if (temp1 != NULL)                  // make sure list is not empty
   {
      temp1 = currentNode->getNextPtr();

      if (temp1 != NULL)               // current is NOT last
         temp1->setPrevPtr( currentNode->getPrevPtr() );
      else                             // current is last
         tailNode = currentNode->getPrevPtr();  // 'rewind' tailnode

      temp1 = currentNode->getPrevPtr();

      if (temp1 != NULL)               // current is NOT first
         temp1->setNextPtr( currentNode->getNextPtr() );
      else                             // current is first!!
         headNode = currentNode->getNextPtr();

      temp1 = currentNode;
      if ((currentNode->getNextPtr()) != NULL) // will we fall off the end?
         currentNode = currentNode->getNextPtr();  // no, point to next
      else                                         // yes! take a step back.
         currentNode = currentNode->getPrevPtr();  // even if NULL (now empty!)

      count -= 1;                      // one less node in the list
   }

   return( temp1 );                    // deleted or not!!
}

//----------------------------------------------------------------------------
//  deleteAllNodes()
//
//  Purpose: removes allNodesFromTheList
//
//

void DoublyLinkedList::deleteAllNodes( void )
{
   ListNode * pNode = headNode;

   while ( pNode )
   {
      pNode = deleteCurrentNode();
      delete pNode;
      pNode = headNode;
   }
}


//----------------------------------------------------------------------------
//  getFirst()
//
//  Purpose: standard OO get method, returns a pointer to the first node in
//           the list and sets 'currentNode' to it.
//

ListNode * DoublyLinkedList::getFirst( void )
{
   currentNode = headNode;
   return( currentNode );
}

//----------------------------------------------------------------------------
//  getFirstNU()
//
//  Purpose: standard OO get method, returns a pointer to the first node in
//           the list and DOES NOT UPDATE 'currentNode'.
//

ListNode * DoublyLinkedList::getFirstNU( void )
{
   return( headNode );
}

//----------------------------------------------------------------------------
//  getNext()
//
//  Purpose: standard OO get method, returns a pointer to the node after
//           'currentNode' and sets 'currentNode' to it.  'currentNode'
//           will become NULL if it pointed to the last node to begin
//           with.
//

ListNode * DoublyLinkedList::getNext( void )
{
   if (currentNode != NULL)
      currentNode = currentNode->getNextPtr();
   return( currentNode );
}

//----------------------------------------------------------------------------
//  getNextNU()
//
//  Purpose: standard OO get method, returns a pointer to the node after
//           'currentNode' and sets 'currentNode' to it.  'currentNode'
//           will become NULL if it pointed to the last node to begin
//           with.
//

ListNode * DoublyLinkedList::getNextNU( ListNode * aNodePtr )
{
   if (aNodePtr != NULL)
      aNodePtr = aNodePtr->getNextPtr();
   return( aNodePtr );
}

//----------------------------------------------------------------------------
//  getCurrent()
//
//  Purpose: standard OO get method, just returns 'currentNode'.
//
//

ListNode * DoublyLinkedList::getCurrent( void )
{
   return( currentNode );
}

//----------------------------------------------------------------------------
//  getPrev()
//
//  Purpose: standard OO get method, returns a pointer to the node previous
//           to 'currentNode' and sets 'currentNode' to it.  'currentNode'
//           will become NULL if it pointed to the first node to begin
//           with.
//

ListNode * DoublyLinkedList::getPrev( void )
{
   if (currentNode != NULL)
      currentNode = currentNode->getPrevPtr();
   return( currentNode );
}

//----------------------------------------------------------------------------
//  getPrevNU()
//
//  Purpose: standard OO get method, returns a pointer to the node after
//           'currentNode' and sets 'currentNode' to it.  'currentNode'
//           will become NULL if it pointed to the last node to begin
//           with.
//

ListNode * DoublyLinkedList::getPrevNU( ListNode * aNodePtr )
{
   if (aNodePtr != NULL)
      aNodePtr = aNodePtr->getPrevPtr();
   return( aNodePtr );
}

//----------------------------------------------------------------------------
//  getLast()
//
//  Purpose: standard OO get method, returns a pointer to the last node in
//           the list and sets 'currentNode' to it.
//

ListNode * DoublyLinkedList::getLast( void )
{
   currentNode = tailNode;
   return( currentNode );
}

//----------------------------------------------------------------------------
//  getLastNU()
//
//  Purpose: standard OO get method, returns a pointer to the last node in
//           the list and DOES NOT UPDATE 'currentNode'.
//

ListNode * DoublyLinkedList::getLastNU( void )
{
   return( tailNode );
}
