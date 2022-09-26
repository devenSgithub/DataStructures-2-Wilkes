

//
// assign10.cpp
// Deven Schwartz
// 5/6/2021
// assign10
// Assigment 10: graphs
// Description: Creates a graph with the user provided information then allows the user to preform several different functions via a menu, 
//after exiting the menu the graph is copied and the copied graph is printed via DFS from 0.
// Flow: A graph is created and then a menu is looped for the user ending with a copied graph that displays.
// References: List examples provided on website: http://mathcs.wilkes.edu/~bracken/cs226/sp2014/1529_001.pdf.
// Assistance: Dr. Bracken - fix for BFS, had temp incrementing in the incorrect spot.
//
//Testing: I have thoroughly tested my code and have not found any errors.   
//1.) no problems found  
 
//Time: ~4 hours. Not sure on the exact time spent





#include<fstream>
#include<cassert>
#include<iostream>
#include"queuei.h"
#include"graph.h"
#include<string>
int main()
{



    //common output
    cout<<"Deven Schwartz"<<endl;
    cout<<"Assignment 10: graphs"<<endl;
    cout<<"Creates a graph given user information then loops a menu allowing user to display the created grap. Ends with a displayed copied graph.\n"<<endl;
    //

    //create the graph
    graph mygraph;


    //variable to store the menu input
    char input;  
    //loop menu until exited by user
    while(input != '4'){

        cout << " \nEnter: " << endl; 
        cout << "   1 to Do a depth-first search. " << endl; 
        cout << "   2 to Do a topological sort. " << endl; 
        cout << "   3 to Do a breadth-first search. " << endl; 
        cout << "   4 to Exit the program. " << endl; 
        
        cin >> input;

        cout << "	\nYou entered: " << input << endl; 

        //switch to handle the input chocies 
        switch(input)
        {
        
        case '1': //DFS
            cout << "(Do a depth-first search)" << endl;

            cout << "Enter the starting index: " << endl;
            int DFSindex;

            // check for valid input have user reenter until a valid input is accepted
            while(true){
            
                cin >> DFSindex;
                if(cin.good()){
                break;
                }else{
                cout<<"You entered invalid input, reenter an integer \n";
                cin.clear();
                cin.ignore(120,'\n');
                }

            }

            cout << "You entered: " << DFSindex << endl ;
            bool DFSsuccess;
            
            DFSsuccess = mygraph.DFS(DFSindex);

            if(DFSsuccess){
                cout<<"DFS successful from: "<<DFSindex<<endl;
            }else{
                cout<<"DFS was unsuccessful from: "<<DFSindex<<endl;
            }
            

            cout<<"\nReturning to menu selection"<<endl;
            break; 
            


        case '2': //topological sort
            cout << "(Do a topological sort)" << endl;
            
            mygraph.topological();

            cout<<"\nReturning to menu selection"<<endl;
            break;
            


        case '3': //BFS
            cout << "(Do a breadth-first search)" << endl; 
            
            cout << "Enter the starting index: " << endl;
            int BFSindex;

            // check for valid input have user reenter until a valid input is accepted
            while(true){
            
                cin >> BFSindex;
                if(cin.good()){
                break;
                }else{
                cout<<"You entered invalid input, reenter an integer \n";
                cin.clear();
                cin.ignore(120,'\n');
                }

            }

            cout << "You entered: " << BFSindex << endl ;

            bool BFSsuccess;

            BFSsuccess = mygraph.BFS(BFSindex);

            if(BFSsuccess){
                cout<<"BFS successful from: "<<BFSindex<<endl;
            }else{
                cout<<"BFS was unsuccessful from: "<<BFSindex<<endl;
            }


            
            cout<<"\nReturning to menu selection"<<endl;
            break;
        


        case '4':
            //exit case
            cout << "(Exiting the menu.)" << endl; 
            cout<<"-Goodbye-" << endl;
            break;
        
        default:
            cout << "Invalid Selection. Please Enter Again." << endl; 
        }//switch end

        
        cout << endl; 
    }//loop end


    /*
      Prior to exiting the program, you must exercise your copy constructor. 
      Declare an graph object using the copy constructor for the graph object that you just exercised. 
      Then call DFS for the copied object specifying node 0.
    */

    cout << "Creating a copy of the graph." << endl; 
    graph copygraph(mygraph);
    bool success = true;

    success = copygraph.DFS(0);
    if (success){
        cout << "DFS (from node 0) of copygraph was successful." << endl; 
    }

  
}//end of main