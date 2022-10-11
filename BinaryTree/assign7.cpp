 //main file



//
// assign7.cpp
// Deven Schwartz
// 4/7/2021
// assign7
// Assigment 7: Binary Trees
// Description: The program uses the created list class to manipulate a array based binary tree via 
//a menu provided, looping the menu until the user chooses to exit.
// Flow: Program loops a menu allowing a user to change a binary tree.
// References: List examples provided on website: http://mathcs.wilkes.edu/~bracken/cs226/sp2014/1529_001.pdf.
//Also used math.h for pow function.
// Assistance: None
//
//Testing: I have tested my code and have errors/problems that I need to fix.   
//1.) I have not added a stop so that negative values cannot be entered in to the tree.
//this does not cause problems in most cases unless a -1 is entered
//2.) I never got the traversals to work (commented out the code/deleted it)
//I have changed the code in the menu to instead use a basic display so that the tree is still printed in some way
//3.)


//Time: ~4 hours. Not sure on the exact time spent







#include "BTstack.h"
#include "sbinarytree.h"
#include <math.h>

using namespace std;
int main()
{

    //common output
    cout<<"Deven Schwartz"<<endl;
    cout<<"Assignment 7: Binary Trees"<<endl;
    cout<<"Loops through a menu of choices that allow for the manipulation of an array based complete tree.\n"<<endl;
   



    //create a list to use
    binarytree mytree; 

    //variable to store the menu input
    int storeitem = 0;
    bool success = false;
    int input;  
    //loop menu until exited by user
    while(input != 10 ){
        //if(input == 0){
            //break;
       // }
        cout << " \nEnter: " << endl; 
        cout << "   1 to Add an element to the binary tree. " << endl; 
        cout << "   2 to Delete an element from the tree. " << endl; 
        cout << "   3 to Display level i of the tree. " << endl; 
        cout << "   4 to Preform an Inorder traversal of the tree. " << endl; 
        cout << "   5 to Preform an Preorder traversal of the tree. " << endl; 
        cout << "   6 to Preform an Postorder traversal of the tree. " << endl; 
        cout << "   7 to Print the height of the tree. " << endl; 
        cout << "   8 to Print the number of elements in the tree. " << endl; 
        cout << "   9 to Print a message stating whether the tree is a full binary tree or not. " << endl; 
        cout << "   10 to exit the menu. " << endl; 
        
        //cin >> input;

        while(true){
            
            cin >> input;
            if(cin.good()){
                break;
            }else{
                cout<<"You entered invalid input, reenter an integer \n";
                cin.clear();
                cin.ignore(120,'\n');
            }

        }





        cout << "	\nYou entered: " << input << endl; 

        //switch to handle the input chocies 
        switch(input)
        {
        
        case 1: //calls additem and adds provided element to the list
            cout << "(Add an element to the binary tree)" << endl;

            cout << "Enter an integer to add to the tree: " << endl;
            //int storeitem;

            // check for valid input have user reenter until a valid input is accepted
            while(true){
            
                cin >> storeitem;
                if(cin.good()){
                break;
                }else{
                cout<<"You entered invalid input, reenter an integer \n";
                cin.clear();
                cin.ignore(120,'\n');
                }

            }

            cout << "You entered: " << storeitem << endl ;
            cout << storeitem << " has been added to the list." << endl ;
            mytree.additem(storeitem, success); 

            if(success){
                cout<<"The item ("<<storeitem<<") was added to the tree."<<endl;
            }else{
                cout<<"The item ("<<storeitem<<") was not added to the tree. (Tree is full)"<<endl;
            }


            
            cout<<"\nReturning to menu selection"<<endl;
            break; 
            


        case 2: //calls deleteitem and removes the last element in the tree
            cout << "(Delete an element from the tree)" << endl;


            mytree.deleteitem(storeitem, success);
            if(success){
                cout<<"The item ("<<storeitem<<") was deleted from the tree."<<endl;
            }else{
                cout<<"Nothing was deleted from the tree. (Tree is empty)"<<endl;
            }


            
            
            cout<<"\nReturning to menu selection"<<endl;
            break;
        


        case 3: //displays level provided by the user.
            cout << "(Display level i of the tree)" << endl; 





            cout << "Enter a level to display from the tree: " << endl;

            // check for valid input have user reenter until a valid input is accepted
            while(true){
            
                cin >> storeitem;
                if(cin.good()){
                break;
                }else{
                cout<<"You entered invalid input, reenter an integer \n";
                cin.clear();
                cin.ignore(120,'\n');
                }

            }

            cout << "You entered: " << storeitem << endl ;
            cout <<"Level "<< storeitem << " is being displayed." << endl ;
            mytree.displaylevel(storeitem); 

                    
        
            cout<<"\nReturning to menu selection"<<endl;
            break;
        


        case 4: //calls inorder function
            cout << "(Inorder traversal)" << endl;

            mytree.inorderdisplay();
            mytree.displayall();



            cout<<"\nReturning to menu selection"<<endl;
            break;
        


        case 5: //calls preorder function.
            cout << "(Preorder traversal)" << endl; 
        
            mytree.preorderdisplay();
            mytree.displayall();

            cout<<"\nReturning to menu selection"<<endl;
            break;


        case 6: //calls postorder function.
            cout << "(Postorder traversal)" << endl; 

            mytree.postorderdisplay();
            mytree.displayall();

            cout<<"\nReturning to menu selection"<<endl;
            break;
        
        case 7: //calls height function and prints the result.
            cout << "(Print the height of the tree)" << endl; 
            
            storeitem = mytree.treeheight();
            cout<<"The hieght of the tree is "<< storeitem <<endl;



            cout<<"\nReturning to menu selection"<<endl;
            break;



        case 8: //calls numberofelements and prints the result.
            cout << "(Print the number of elements in the tree)" << endl; 
            
            storeitem = mytree.treeelements();
            cout<<"The number of elements in the tree is "<< storeitem <<endl;

            cout<<"\nReturning to menu selection"<<endl;
            break;


        case 9: //determines if the tree is full.
            cout << "(Print a message stating whether the tree is a full binary tree or not)" << endl; 
            
           
            
//2^(height)-1
            storeitem = mytree.treeheight();
            storeitem = pow(2, storeitem) - 1;

            if(storeitem == mytree.treeelements()){
                cout<<"Tree is a full binary tree."<<endl;
            }else{
                cout<<"Tree is not a full binary tree."<<endl;
            }



            cout<<"\nReturning to menu selection"<<endl;
            break;


        case 10:
        //exit case
            cout << "(Exiting the menu.)" << endl; 
            cout<<"-Goodbye-" << endl;
            break;
       // case 0:
        //exit case
           // cout << "(Exiting the menu.)" << endl; 
          //  cout<<"-Goodbye-" << endl;
           // break;
        default:
            cout << "Invalid Selection. Please Enter Again." << endl; 
            
        }//switch end

        //new line to make prints look nice
        cout << endl; 
    }//loop end





//mytree.displayall();

/*   //testing stuff
cout<<"\n\n"<<endl;

   //int temp = 0;
    bool suc;

    binarytree tree;
   
    tree.additem(1,suc);
    tree.additem(2,suc);
    tree.additem(3,suc);
    tree.additem(4,suc);
    tree.additem(5,suc);
    //tree.additem(6,suc);
    //tree.additem(7,suc);
    //tree.additem(8,suc);
    //tree.additem(3,suc);
    tree.displayall();
    tree.inorderdisplay();
   */


    cout<<"ending"<<endl;
}//end main