#include<fstream>
#include<cassert>
#include<iostream>
#include"queuei.h"
#include<string>
int main()
{
  string fn;
  ifstream fin;
  int newitem;
  //  bool success;
  queueClass queue1;
  cout<<"please enter the name of the file containing your data"<<endl;
  cin>>fn;
  cout<<"The file name entered is "<<fn<<endl;
  fin.open(fn.c_str());
  assert(fin.is_open());
  while(true)
  {
     fin>>newitem;
     if(fin.eof())
     {
        break;
     }
     cout<<"About to insert "<<newitem<<"   into the queue "<<endl;
     //Insert newitem into the queue
     
  }//end of input loop
  //print the contents of the queue
  //calculate sum and average
  //be sure to handle empty queue properly  
  
}//end of main