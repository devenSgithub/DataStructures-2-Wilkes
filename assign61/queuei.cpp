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
  bool successtest;
  while(BackPtr != NULL){
    QueueDelete(successtest);
    //cout<<"clearing"<<endl;
  }
}  // end destructor





bool queueClass::QueueIsEmpty() const
{
	return bool(BackPtr == NULL);

}  // end QueueIsEmpty




void queueClass::QueueInsert(queueItemType NewItem,
                             bool& Success)
{
  Success = false;
  ptrType temp;
  temp = new queueNode;
  temp->Item = NewItem;
  if(BackPtr == NULL){
    BackPtr = temp;
    BackPtr->Next = temp;
    numberofqueueelements = numberofqueueelements + 1;
    Success = true;
    //break;
  }else{
    temp->Next = BackPtr->Next;
    BackPtr->Next = temp;
    BackPtr = temp;
    numberofqueueelements = numberofqueueelements + 1;
    Success = true;
    //break;

  }


  
}  // end QueueInsert




void queueClass::QueueDelete(bool& Success)
{

  Success = false;
  ptrType temp;
  temp = new queueNode;
  
  if(numberofqueueelements > 0){
    temp = BackPtr->Next;
    //QueueFront = temp->Item;
    Success = true;

    if(temp == BackPtr){
      BackPtr = NULL;
      
    }else{
      BackPtr->Next = temp->Next;

    }
    numberofqueueelements = numberofqueueelements - 1;
    delete temp;
  }




}  // end QueueDelete






void queueClass::QueueDelete(queueItemType& QueueFront, 
                             bool& Success)
{

  Success = false;
  ptrType temp;
  temp = new queueNode;
  
  if(numberofqueueelements > 0){
    temp = BackPtr->Next;
    QueueFront = temp->Item;
    Success = true;

    if(temp == BackPtr){
      BackPtr = NULL;
      
    }else{
      BackPtr->Next = temp->Next;

    }
    numberofqueueelements = numberofqueueelements - 1;
    delete temp;
  }







}  // end QueueDelete






void queueClass::GetQueueFront(queueItemType& QueueFront, 
                               bool& Success) const
{

  Success = false;
  ptrType temp;
  temp = new queueNode;
  
  if(numberofqueueelements > 0){
    temp = BackPtr->Next;
    QueueFront = temp->Item;
    Success = true;
  }



}  // end GetQueueFront






void queueClass::QueuePrint() const
{
  if(numberofqueueelements > 0){
    ptrType temp;
    temp = new queueNode;
    temp = BackPtr->Next;
    while(temp != BackPtr){
      cout<<temp->Item<<endl;
      temp = temp->Next;
    }
    cout<<temp->Item<<endl;
  }


}





int queueClass::NumberOfQueueElements() const
{
    return numberofqueueelements;    
}
// End of implementation file.
 


