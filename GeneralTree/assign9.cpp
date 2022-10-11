

//
// assign9.cpp
// Deven Schwartz
// 4/13/2021
// assign9
// Assigment 9: General Trees
// Description: The program creates a general tree then loops through a menu
// Flow: Program loops a menu allowing a user to change a tree.
// References: List examples provided on website: http://mathcs.wilkes.edu/~bracken/cs226/sp2014/1529_001.pdf.
// Assistance: None
//
//Testing: I have tested my code and have errors that I have not fixed.   
//  
//1.) I did not add a recursive find used an iterative one I know you recommended to create a recursive 
//one but I had already created a nonrecursive find so I just used that. (**If I have time will change to recursive)
//
//

//Time: ~4 hours. Not sure on the exact time spent


#include<fstream>
#include<cassert>
#include<iostream>
#include"general.h"
#include<string>
int main()
{

  //common output
  cout<<"Deven Schwartz"<<endl;
  cout<<"Assignment 9: General Trees "<<endl;
  cout<<"A general tree is created and then a menu is looped through to allow the user to manipulate the tree.\n"<<endl;
  //



  generaltree mytree;

  
  char input;  
  //loop menu until exited by user
  while(input != '8'){

    cout << " \nEnter: " << endl; 
    cout << "   1 to Search for an item in the general tree. " << endl; 
    cout << "   2 to Display all children of a node. " << endl; 
    cout << "   3 to Display all siblings of a node. " << endl; 
    cout << "   4 to Display left siblings of a node. " << endl; 
    cout << "   5 to Display right siblings of a node. " << endl; 
    cout << "   6 to Display the parent of a node. " << endl; 
    cout << "   7 to Add a node to the tree. " << endl; 
    cout << "   8 to exit the menu. " << endl; 
    
    cin >> input;

    cout << "	\nYou entered: " << input << endl; 

    //switch to handle the input chocies 
    switch(input)
    {
    
    case '1': 
      cout << "(Search for an item in the general tree)" << endl;

      cout << "Enter an integer to find in the tree: " << endl;
      int infind;
      bool success;

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
      success = mytree.elementexist(infind); 
      if(success){
        cout<<infind<<" was found in the tree."<<endl;
      }else{
        cout<<infind<<" was not found in the tree."<<endl;
      }

      cout<<"\nReturning to menu selection"<<endl;
      break; 
    


    case '2': //calls display children
      cout << "(Display all children of a node)" << endl;
      mytree.displaychildren();

      cout<<"\nReturning to menu selection"<<endl;
      break;
    


    case '3': //calls display siblings
      cout << "(Display all siblings of a node)" << endl; 
      mytree.displayall();
      //mytree.displayleft();
      cout<<"\nReturning to menu selection"<<endl;
      break;
    


    case '4': //calls display left 
      cout << "(Display left siblings of a node.)" << endl;
      mytree.displayleft();


      cout<<"\nReturning to menu selection"<<endl;
      break;
    



    case '5':
      cout << "(Display right siblings of a node)" << endl;
      mytree.displayright();
      
       	
      
      
      cout<<"\nReturning to menu selection"<<endl;
      


      break;




    case '6': //calls displayparent.
      cout << "(Display the parent of a node)" << endl; 
      
      mytree.displayparent();

      cout<<"\nReturning to menu selection"<<endl;
      break;


    case '7':

      cout << "(Add a node to the tree)" << endl;
      bool insuccess;
      insuccess = mytree.treeinsert();
      if(insuccess){
        cout<<"The item was entered into the tree."<<endl;
      }else{
        cout<<"The item could not be entered."<<endl;
      }
      break;


    case '8':
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







  
}//end of
