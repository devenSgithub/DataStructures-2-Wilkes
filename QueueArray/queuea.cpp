// *********************************************************
// Implementation file QueueP.cpp for the ADT queue.
// 
// *********************************************************
#include "queuea.h"  // header file
#include <stddef.h>  // for NULL
#include <iostream>
// The queue is array based.
struct queueNode
{  
   int front = 0;
   int back = 0;
   int size = 10;
   int *arrayqueue;
};  // end struct

queueClass::queueClass()  
{
  numberofqueueelements=0;
  front= -1;
  back = -1;
  arrayqueue = new int[size];


}  // end default constructor



queueClass::~queueClass()
{
}  // end destructor

bool queueClass::QueueIsEmpty() const
{
  if (front == -1){
    return true;
  }else{
    return false;
  }
	//return true;

}  // end QueueIsEmpty





void queueClass::QueueInsert(queueItemType NewItem,
                             bool& Success)
{

  if(back+1 == front || (front == 0 && back == (size-1))){
    cout<<"queue full"<<endl;//reallocate the size to increase 
  }else{
    if(back == size - 1){
      if(front != 0){
        back = 0;//to front
      }
    }else{
      back++;//increment back position
      front =0;
      arrayqueue[back] = NewItem;
      numberofqueueelements = numberofqueueelements + 1;
      Success = true;
    }
  }
  if(front == -1){
    front = 0;
    //back = 0;
  }




}  // end QueueInsert





void queueClass::QueueDelete(bool& Success)
{

  //int temp;
  if(front == -1){
    cout<<"empty queue"<<endl;//reallocate the size when empty
    arrayqueue = new int[10]; // will change size back to the default of 10.
    Success = false;
  }else{
    //temp = arrayqueue[front];
    if(front == back){
      front = -1;
      back = -1;
    }else{
      if(front == size-1){
        front = 0;
      }else{
        front++;
      }
    }
    numberofqueueelements = numberofqueueelements - 1;
    Success = true;
  }





}  // end QueueDelete

void queueClass::QueueDelete(queueItemType& QueueFront, 
                             bool& Success)
{


int temp;
  if(front == -1){
    cout<<"empty queue"<<endl;//reallocate the size when empty
    Success = false;
  }else{
    temp = arrayqueue[front];
    if(front == back){
      front = -1;
      back = -1;
    }else{
      if(front == size-1){
        front = 0;
      }else{
        front++;
      }
    }
    numberofqueueelements = numberofqueueelements - 1;
    QueueFront = temp;
    Success = true;
  }






}  // end QueueDelete

void queueClass::GetQueueFront(queueItemType& QueueFront, 
                               bool& Success) const
{
  if(front!= -1){
    QueueFront = arrayqueue[front];
    Success = true;
  }else{
    Success = false;
    QueueFront = 0;
  }


}  // end GetQueueFront

void queueClass::QueuePrint() const
{


  //int temp;
  if(front == -1){
    cout<<"empty queue"<<endl;//empty queue case
  }else{
    if(back < front){
      for(int i=front;i<=size-1;i++){
			  cout<<arrayqueue[i]<<endl;
      }
			for(int i=0;i<=back;i++){//array back to start 
			  cout<<arrayqueue[i]<<endl;
      }
    }else{
      for(int i=front;i<=back;i++){//nothing deleted yet
        cout<<arrayqueue[i]<<endl;
      }
    }
  }






}
int queueClass::NumberOfQueueElements() const
{
    return numberofqueueelements;    
}
// End of implementation file.
 













