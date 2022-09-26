

//
// assign62.cpp
// Deven Schwartz
// 4/5/2021
// assign6.2
// Assigment 62: Queues
// Description: The program uses the created array queue class to manipulate queue via 
//a menu provided, looping the menu until the user chooses to exit.
// Flow: Program loops a menu allowing a user to change a queue.
// References: List examples provided on website: http://mathcs.wilkes.edu/~bracken/cs226/sp2014/1529_001.pdf.
// Assistance: None
//
//Testing: I have tested my code and have errors/problems that I have not fixed.   
//1.) I never implemented the size of the array so if the array fills to the default max size then no new items can be added so operations 
//that occur after the max size is reached will not be correct sometimes.

//Time: ~2 hours. Not sure on the exact time spent






#include<fstream>
#include<cassert>
#include<iostream>
#include"queuea.h"
#include<string>
int main()
{

//common output
  cout<<"Deven Schwartz"<<endl;
  cout<<"Assignment 6.2: Queues"<<endl;
  cout<<"Loops through a menu of choices that allow for the manipulation of a queue.\n"<<endl;
  //







    int newitem = 0;
    int front = 0;
    bool success;
    queueClass queue1;

//variable to store the menu input
  char input;  
  //loop menu until exited by user
  while(input != '6'){

    cout << " \nEnter: " << endl; 
    cout << "   1 to Enqueue data onto queue. " << endl; 
    cout << "   2 to Dequeue and print data from the queue. " << endl; 
    cout << "   3 to Print data at the front without dequeing. " << endl; 
    cout << "   4 to Print entire queue. " << endl; 
    cout << "   5 to Print status: empty or not empty. " << endl; 
    cout << "   6 to Exit Program. " << endl; 
    //cout << "   7 to exit the menu. " << endl; 
    
    cin >> input;

    cout << "	\nYou entered: " << input << endl; 

    //switch to handle the input chocies 
    switch(input)
    {
    
    case '1': //
      cout << "(Enqueue data onto queue)" << endl;
      
    
      //ask for int to remove
      cout << "Enter an integer to add to the queue: " << endl;
      
      // check for valid input have user reenter until a valid input is accepted
      while(true){
      
        cin >> newitem;
        if(cin.good()){
          break;
        }else{
          cout<<"You entered invalid input, reenter an integer \n";
          cin.clear();
          cin.ignore(120,'\n');
        }

      }

      cout << "You entered: " << newitem << endl;





        queue1.QueueInsert(newitem, success);



      cout<<"\nReturning to menu selection"<<endl;
      break; 
    


    case '2': //remove an item from the queue
      cout << "(Dequeue and print data from the queue)" << endl;
      
        queue1.QueueDelete(front, success);
        if(success){
            cout<<"The removed item is: "<<front<<endl;
        }else{
            cout<<"The queue is empty."<<endl;
        }


      cout<<"\nReturning to menu selection"<<endl;
      break;
    


    case '3': //print first item in the queue
      cout << "(Print data at the front without dequeing)" << endl; 
     
        queue1.GetQueueFront(front, success);
        if(success){
            cout<<"The front item is: "<<front<<endl;
        }else{
            cout<<"The queue is empty."<<endl;
        }
            

      
      cout<<"\nReturning to menu selection"<<endl;
      break;
    


    case '4': //prints the queue
      cout << "(Print entire queue)" << endl;

        cout<<"Printint the queue:"<<endl;
        queue1.QueuePrint();


      
      cout<<"\nReturning to menu selection"<<endl;
      break;
    



    case '5':
      cout << "(Print status: empty or not empty)" << endl;
      

      success = queue1.QueueIsEmpty();

      if (success == 1){
          cout<<"The queue is empty. "<<endl;
      }else{
            cout<<"The queue is not empty. "<<endl;
      }
     
      
      cout<<"\nReturning to menu selection"<<endl;
      


      break;




    


    case '6':
    //exit case
      cout << "(Exiting the menu.)" << endl; 
      cout<<"-Goodbye-" << endl;
      break;
    
    default:
      cout << "Invalid Selection. Please Enter Again." << endl; 
    }//switch end

    //new line to make prints look nice
    cout << endl; 
  }//loop end








  

  
}//end of main