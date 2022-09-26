

//
// assign4a.cpp
// Deven Schwartz
// 3/17/2021
// assign4a
// Assigment 4: Introduction to Linked Lists
// Description: The program uses the created list class to manipulate a sorted linked list via 
//a menu provided, looping the menu until the user chooses to exit.
// Flow: Program loops a menu allowing a user to change a list.
// References: List examples provided on website: http://mathcs.wilkes.edu/~bracken/cs226/sp2014/1529_001.pdf.
// Assistance: None
//
//Testing: I have thoroughly tested my code and it works properly however I did find some potintial problems.   
//1.) Delete is only deleting the first occurance of a value, not sure if wanted all occurances of a value deleted or
//just the first if mulitiple occurances ###to change: loop through list until end, remove each occurance when value is found 
//2.)Same type of thing occurs with find if multiple values in the list are the same, find will return the first occurance positon 
//Time: ~3-4 hours. Not sure on the exact time spent







#include "list.h"
using namespace std;
int main()
{

  //common output
  cout<<"Deven Schwartz"<<endl;
  cout<<"Assignment 4: Introduction to Linked Lists"<<endl;
  cout<<"Loops through a menu of choices that allow for the manipulation of a list.\n"<<endl;
  //




  //create a list to use
  list mylist; 

  //variable to store the menu input
  char input;  
  //loop menu until exited by user
  while(input != '6'){

    cout << " \nEnter: " << endl; 
    cout << "   1 to display the list. " << endl; 
    cout << "   2 to find an item. " << endl; 
    cout << "   3 to insert an element into the list. " << endl; 
    cout << "   4 to delete an element from the list. " << endl; 
    cout << "   5 to display the number of items in the list. " << endl; 
    cout << "   6 to exit the menu. " << endl; 
    
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
    


    case '5': //calls numberofelements and prints the result.
      cout << "(Displaying number of items in the list)" << endl; 
      int numitems;
      numitems = mylist.numberOfElements();
      cout<<"There is " << numitems << " element(s) in the list."<<endl;
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




  cout<<"ending"<<endl;
}//end main
