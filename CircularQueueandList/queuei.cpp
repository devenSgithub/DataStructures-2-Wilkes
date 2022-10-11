// *********************************************************
// Implementation file QueueP.cpp for the ADT queue.
// Pointer-based implementation.
// *********************************************************
#include "queuei.h"  // header file
#include <stddef.h>  // for NULL
#include <iostream>
// The queue is implemented as a circular linked list
// with one external pointer to the back of the queue.
struct queueNode
{  queueItemType Item;
   ptrType       Next;
};  // end struct

queueClass::queueClass()  
{
  numberofqueueelements=0;
  BackPtr=NULL;

}  // end default constructor



queueClass::~queueClass()
{
}  // end destructor

bool queueClass::QueueIsEmpty() const
{
	return bool(BackPtr == NULL);

}  // end QueueIsEmpty

void queueClass::QueueInsert(queueItemType NewItem,
                             bool& Success)
{

}  // end QueueInsert

void queueClass::QueueDelete(bool& Success)
{

}  // end QueueDelete

void queueClass::QueueDelete(queueItemType& QueueFront, 
                             bool& Success)
{

}  // end QueueDelete

void queueClass::GetQueueFront(queueItemType& QueueFront, 
                               bool& Success) const
{

}  // end GetQueueFront

void queueClass::QueuePrint() const
{

}
int queueClass::NumberOfQueueElements() const
{
    return numberofqueueelements;    
}
// End of implementation file.
 


