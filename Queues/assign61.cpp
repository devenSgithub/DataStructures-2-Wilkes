

//
// assign61.cpp
// Deven Schwartz
// 4/5/2021
// assign6.1
// Assigment 61: Queues
// Description: The program uses the created queue class to make a queue from file data then it calculates the sum 
//and average of the queue, printing the queue before and after the calculations
// Flow: Program creates a queue and calculates the average and sum of the queue.
// References: List examples provided on website: http://mathcs.wilkes.edu/~bracken/cs226/sp2014/1529_001.pdf.
// Assistance: None
//
//Testing: I have thoroughly tested my code and have errors that I have not fixed.   
//1.) average is printing integers even if it should be a float number
 
//Time: ~1.5 hours. Not sure on the exact time spent





#include<fstream>
#include<cassert>
#include<iostream>
#include"queuei.h"
#include<string>
int main()
{



   //common output
  cout<<"Deven Schwartz"<<endl;
  cout<<"Assignment 6.1: Queues"<<endl;
  cout<<"Creates a linked list queue from a file and caluclates the sum and average.\n"<<endl;
  //
   string fn;
   ifstream fin;
   int newitem;
   bool success = true;
   queueClass queue1;



  
  cout<<"Please enter the name of the file containing your data:"<<endl;
  cin>>fn;
  cout<<"The file name entered is: "<<fn<<endl;
  fin.open(fn.c_str());
  assert(fin.is_open());
  while(true)
  {
     fin>>newitem;
     if(fin.eof() || !fin.good())
     {
        break;
     }
     cout<<"About to insert ("<< newitem <<") into the queue. "<<endl;
     //Insert newitem into the queue
     queue1.QueueInsert(newitem,success);
     
  }//end of input loop
   cout<<"Printing the queue: "<<endl;

   queue1.QueuePrint();

   int front, sum, count;
   count = 0;
   float avg;
   avg = 0.0;
   sum = 0.0;

   bool successout;
   queueClass newqueue;
   queue1.QueueDelete(front, successout);
   if(successout){
      
      do {
         sum = sum + front;
         count = count + 1;
         //cout<<"test"<<front<<endl;
         newqueue.QueueInsert(front, success);
         queue1.QueueDelete(front, successout);
         
         

      }while(successout);
    
      cout<<"The sum: "<< sum <<endl;
      avg = sum/count;
      cout<<"The average: "<< avg <<endl;
   }else{
      cout<<"The queue is empty."<<endl;
   }
   cout<<"Printing the queue: "<<endl;
   newqueue.QueuePrint();

  
 
  
}//end of main