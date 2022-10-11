

//
// assign42.cpp
// Deven Schwartz
// 3/25/2021
// assign4.2
// Assigment 42: Linear and Circular Linked Lists
// Description: The program uses the created circular list class to manipulate a sorted linked list via 
//a menu provided, looping the menu until the user chooses to exit.
// Flow: Program loops a menu allowing a user to change a circular list.
// References: List examples provided on website: http://mathcs.wilkes.edu/~bracken/cs226/sp2014/1529_001.pdf.
// Assistance: None
//
//Testing: I have thoroughly tested my code and have errors that I have not fixed.   
//1.) incorrect file name exits program and does not prompt for a new file name.
//other) incorrect input in a file will cause the program to stop reading data but keeps any data up until the point of stopping
//ex: if data in file is 1,2,3,a,5,6 the list will be 1,2,3 
 


//Time: ~1 hours. Not sure on the exact time spent




#include "listc.h"
using namespace std;
int main()
{

  //common output
  cout<<"Deven Schwartz"<<endl;
  cout<<"Assignment 4.3: Linear and Circular Linked Lists"<<endl;
  cout<<"Loops through a menu of choices that allow for the manipulation of a circular list.\n"<<endl;
  //




    cout << "Enter a file name to create the list: " << endl;
    string infile;

      // check for valid input have user reenter until a valid input is accepted
    while(true){
      
      cin >> infile;
      if(cin.good()){
        break;
      }else{
        cout<<"You entered invalid input, reenter a file name \n";
        cin.clear();
        cin.ignore(120,'\n');
      }

    }

    cout << "You entered: " << infile << endl;


  //create a list to use
  //list mylist("t1.txt"); 
  //list mylist;
  list mylist(infile); 


  //variable to store the menu input
  char input;  
  //loop menu until exited by user
  while(input != '7'){

    cout << " \nEnter: " << endl; 
    cout << "   1 to display the list. " << endl; 
    cout << "   2 to find an item. " << endl; 
    cout << "   3 to insert an element into the list. " << endl; 
    cout << "   4 to delete an element from the list. " << endl; 
    cout << "   5 to add elements to the list from a file. " << endl; 
    cout << "   6 to display the number of items in the list. " << endl; 
    cout << "   7 to exit the menu. " << endl; 
    
    cin >> input;

    cout << "	\nYou entered: " << input << endl; 

    //switch to handle the input chocies 
    switch(input)
    {
    
    case '1': //calls displaylist and list is displayed
      cout << "(Displaying the list)" << endl;
      mylist.displayList();

      cout<<"\nReturning to menu selection"<<endl;
      break; 
    


    case '2': //find an item, asks user for an int to find in the list and prints result
      cout << "(Finding an item)" << endl;
      //to store location of found value
      int itempos;
      //ask for int
      cout << "Enter an integer to find in the list: " << endl;
      int infind;

      // check for valid input have user reenter until a valid input is accepted
      while(true){
      
        cin >> infind;
        if(cin.good()){
          break;
        }else{
          cout<<"You entered invalid input, reenter an integer \n";
          cin.clear();
          cin.ignore(120,'\n');
        }

      
      }

      cout << "You entered: " << infind << endl ;
      //call findelement
      itempos = mylist.findElement(infind); 
      //print the position of the element

      if(itempos != 0){
        cout<<"The value you entered ("<< infind <<") is in position " << itempos<< endl;
      }else{
        cout<<"The value you entered ("<< infind <<") is not in the list " << endl;
      }

      cout<<"\nReturning to menu selection"<<endl;
      break;
    


    case '3': //insert an item into the list ask for a integer and call insertelement
      cout << "(Inserting an item)" << endl; 
      cout << "Enter an integer to add to the list: " << endl;
      int innum;

      // check for valid input have user reenter until a valid input is accepted
      while(true){
      
        cin >> innum;
        if(cin.good()){
          break;
        }else{
          cout<<"You entered invalid input, reenter an integer \n";
          cin.clear();
          cin.ignore(120,'\n');
        }

      }

      cout << "You entered: " << innum << endl ;
      cout << innum << " has been added to the list." << endl ;
      mylist.insertElement(innum); 
      
      cout<<"\nReturning to menu selection"<<endl;
      break;
    


    case '4': //delete an item ask for a integer to delete call deleteelement print result
      cout << "(Deleting an item from the list)" << endl;
      int delitem;
      //ask for int to remove
      cout << "Enter an integer to remove from the list: " << endl;
      
      // check for valid input have user reenter until a valid input is accepted
      while(true){
      
        cin >> delitem;
        if(cin.good()){
          break;
        }else{
          cout<<"You entered invalid input, reenter an integer \n";
          cin.clear();
          cin.ignore(120,'\n');
        }

      }

      cout << "You entered: " << delitem << endl;
      //store result of deletion
      bool removed;
      
      removed = mylist.deleteElement(delitem); 	
      //print reults
      if(removed){
        cout<< delitem << " has been removed from the list"<<endl;

      }else{
        cout<< delitem << " is not in list"<<endl;
      }
      cout<<"\nReturning to menu selection"<<endl;
      break;
    



    case '5':
      cout << "(Add elements from a file)" << endl;
      
      
      while(true){
      
        cin >> infile;
        if(cin.good()){
          break;
        }else{
          cout<<"You entered invalid input, reenter a file name \n";
          cin.clear();
          cin.ignore(120,'\n');
        }

      }

      cout << "You entered: " << infile << endl;
      
     // send file to fileInsert 
      
      
      mylist.fileInsert(infile); 	
      
      
      cout<<"\nReturning to menu selection"<<endl;
      





      break;




    case '6': //calls numberofelements and prints the result.
      cout << "(Displaying number of items in the list)" << endl; 
      int numitems;
      numitems = mylist.numberOfElements();
      cout<<"There is " << numitems << " element(s) in the list."<<endl;
      cout<<"\nReturning to menu selection"<<endl;
      break;


    case '7':
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

//you must declare another list object using the copy constructor - making a copy of the first object declared. You must then print the new object and then terminate.
  cout<<"Creating a copy of the list and printing the new list: "<<endl;

  list newlist(mylist);
  newlist.displayList();


  cout<<"ending"<<endl;
}//end main
