

//
// assign43.cpp
// Deven Schwartz
// 3/30/2021
// assign4.3
// Assigment 43: Linear and Circular Linked Lists
// Description: The program cretes a list and plays Josephus game with the input provided by the user.
// Flow: Program plays josephus game.
// References: List examples provided on website: http://mathcs.wilkes.edu/~bracken/cs226/sp2014/1529_001.pdf.
// Assistance: None
//
//Testing: I have thoroughly tested my code and have fixed any errors that I have found.   
//
//Time: ~30 minutes. Not sure on the exact time spent







#include "listj.h"
using namespace std;
int main()
{

  //common output
  cout<<"Deven Schwartz"<<endl;
  cout<<"Assignment 4.3: Linear and Circular Linked Lists"<<endl;
  cout<<"Plays Josephus game with provided input.\n"<<endl;
  //




    cout << "Enter the number of nodes to add to the list (N): " << endl;
    int Nnodes;

      // check for valid input have user reenter until a valid input is accepted
    while(true){
      
      cin >> Nnodes;
      if(cin.good()){
        break;
      }else{
        cout<<"You entered invalid input, reenter the number of nodes \n";
        cin.clear();
        cin.ignore(120,'\n');
      }

    }

    cout << "You entered: " << Nnodes << endl;


  //create a list to use
  list mylist; 

  //add n nodes to the list
  for(int i = 1; i <= Nnodes; i++){
    mylist.insertElement(i); 
  }

  //get the number of passes from the user
  cout << "Enter the number of passes (M): " << endl;
  int passes;

      // check for valid input have user reenter until a valid input is accepted
    while(true){
      
      cin >> passes;
      if(cin.good()){
        break;
      }else{
        cout<<"You entered invalid input, reenter the number of passes \n";
        cin.clear();
        cin.ignore(120,'\n');
      }

    }

    cout << "You entered: " << passes << endl;




  //call function
  int winner;
  winner = mylist.Josephus(passes);
  //print winner or empty list cases
  if(winner == 0){
    cout<<"No winner the list was empty"<<endl;
  }else{
    cout<<"The winner is "<< winner <<endl;
  }





  cout<<"ending"<<endl;
}//end main
