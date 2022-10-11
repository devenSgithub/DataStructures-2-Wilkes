

//
// assign44.cpp
// Deven Schwartz
// 3/25/2021
// assign4.4
// Assigment 44: Linear and Circular Linked Lists
// Description: the program takes to files and creates 
//list with them then creates a new list of the intercetion of the two list and prints all three.
// Flow: Program creates lists and prints them.
// References: List examples provided on website: http://mathcs.wilkes.edu/~bracken/cs226/sp2014/1529_001.pdf.
// Assistance: None
//
//Testing: I have thoroughly tested my code and have errors that I have not fixed.   
//1.) incorrect file name exits program and does not prompt for a new file name.
//other) incorrect input in a file will cause the program to stop reading data but keeps any data up until the point of stopping
//ex: if data in file is 1,2,3,a,5,6 the list will be 1,2,3 

//Time: ~30 minutes. Not sure on the exact time spent






#include "list.h"
using namespace std;
int main()
{

  //common output
  cout<<"Deven Schwartz"<<endl;
  cout<<"Assignment 4.4: Linear and Circular Linked Lists"<<endl;
  cout<<"Create two list with files then a list of the intersection of the lists.\n"<<endl;
  //




    cout << "Enter a file name to create list 1: " << endl;
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
  list mylist1(infile); 


  cout << "Enter a file name to create list 2: " << endl;

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


  list mylist2(infile);




  cout<<"Creating a list with the intercetion of the two list previously created: "<<endl;
  //create the intersection list
  list newlist(mylist1, mylist2);
  cout<<"Displaying List 1: "<<endl;
  //print list1 
  mylist1.displayList();
  cout<<"Displaying List 2: "<<endl;
  //print list2
  mylist2.displayList();
  cout<<"Displaying List Intersection: "<<endl;
  //print newlist
  newlist.displayList();


  cout<<"ending"<<endl;
}//end main
