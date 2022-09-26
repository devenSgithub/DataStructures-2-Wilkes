


#include "general.h"


generaltree::generaltree()
{
 root=NULL;
 //numberofelements = 0;


 cout << "Enter an integer to make the root: " << endl;
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
    gennode *temp;
    temp = new gennode;
    temp->item = innum;
    
    root = temp;
    
    char inchar;
    bool success;
    while(true){

        cout<<"Do you still want to ented numbers (y/n): ";        
        while(true){
            cin >> inchar;
            if(cin.good()){
                break;
            }else{
                cout<<"You entered invalid input, reenter an integer \n";
                cin.clear();
                cin.ignore(120,'\n');
            }


        }

        cout << "You entered: " << inchar << endl ;
        if (inchar == 'n'){
            break;
        }else{

            success = treeinsert();


        }

    }






}









bool generaltree::treeinsert(){

    //cout<<"made it here"<<endl;//check


    int insertnum;
    cout<<"Enter the parent of the element: ";        
    while(true){
        cin >> insertnum;
        if(cin.good()){
            break;
        }else{
            cout<<"You entered invalid input, reenter an integer \n";
            cin.clear();
            cin.ignore(120,'\n');
        }


    }

    cout << "You entered: " << insertnum << endl ;

    //check the node exist.
    
    gennode *temp2;
    temp2 = new gennode;
    temp2 = treefind(insertnum);
    if(temp2->item !=insertnum){
        return false;
    }
    //cout<<"exited search"<<endl;
    //parent is at temp2


    cout<<"Enter the element to insert: ";        
    while(true){
        cin >> insertnum;
        if(cin.good() && !elementexist(insertnum)){
            break;
        }else{
            cout<<"You entered invalid input, reenter an integer \n";
            cin.clear();
            cin.ignore(120,'\n');
        }


    }

    cout << "You entered: " << insertnum << endl ;

    gennode *innode;
    innode = new gennode;
    innode->item = insertnum;

    //temp2 = parent

   


    if(temp2->firstchild == NULL){
        //cout<<"fc is null"<<endl;
        //cout<<temp2->item<<endl;
        temp2->firstchild = innode;
        innode->parent = temp2;
        innode->siblinglist = NULL;
        innode->prevsibling = NULL;
        //cout<<temp2->firstchild->item<<endl;


    }else{
        //cout<<"fc is not null"<<endl;
        temp2 = temp2->firstchild;
        while(temp2->siblinglist != NULL){
            //cout<<"entering "<<temp2->item<<endl;
            temp2 = temp2->siblinglist;
        }
        //at end of list insert here
        //cout<<temp2->item<<endl;
        //cout<<"inserted: "<<endl;
        temp2->siblinglist = innode;
        innode->parent = temp2->parent;
        innode->prevsibling = temp2;

       // temp2 = temp2->siblinglist;
        //cout<<temp2->item<<endl;

    }



return true;



}








bool generaltree::elementexist(int num){
    gennode *temp;
    temp = new gennode;
    temp = root;

    if(temp->item == num){
        //cout<<"root is number"<<endl;
        //temp2 = temp;
        return true;
        //insert here.
    }else{
        if(temp->firstchild == NULL){
            //cout<<"no position"<<endl;
            return false;
        }else{
            temp = temp->firstchild;
        }
        while(temp != root || temp->item == num){
            if(temp->item == num){
                //is parent
                //cout<<"element exist"<<endl;
                //temp2 = temp;
                return true;
                break;
            }else if(temp->firstchild != NULL){
                temp = temp->firstchild;
                //cout<<temp->item<<endl;

            }else if(temp->siblinglist != NULL){
                temp = temp->siblinglist;
                //cout<<temp->item<<endl;
            }else{
                //cout<<"check"<<endl;
                temp = temp->parent;
                //cout<<temp->item<<endl;
                if(temp==root){
                    //cout<<"break out"<<endl;
                    return false;
                }
                while(temp->siblinglist == NULL){
                    //cout<<"in here"<<endl;
                    if(temp->item == root->item){
                        //cout<<"not found"<<endl;
                        return false;
                    }else{
                        //cout<<"moving up"<<endl;
                        temp = temp->parent;
                    }

                }
                temp = temp->siblinglist;
            }
        }
        //temp2 = temp;

    }


    return false;


}


bool generaltree::displaychildren(){

    int innum;
    cout<<"Enter the element to display the children of: ";        
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
    
    //search for the position 





    gennode *temp;
    temp = new gennode;

    temp = treefind(innum);

    //cout<<temp->item<<endl;
    if (temp->item != innum){
        return false;
    }else{
        
        if(temp->firstchild != NULL){
            temp = temp->firstchild;
            while(temp->siblinglist !=NULL){
                cout<<temp->item<<endl;
                temp = temp->siblinglist;
            }
            cout<<temp->item<<endl;
        }else{
            cout<<"The node has no children."<<endl;
        }


        return true;

    }


}





bool generaltree::displayparent(){

    int innum;
    cout<<"Enter the element to display the parent of: ";        
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
    
    //search for the position 





    gennode *temp;
    temp = new gennode;

    temp = treefind(innum);

    //cout<<temp->item<<endl;
    if (temp->item != innum){
        return false;
    }else{
        
        if(temp->parent != NULL){
            temp = temp->parent;
            
            cout<<temp->item<<endl;
        }else{
            cout<<"The node is the root."<<endl;
        }


        return true;

    }


}



bool generaltree::displayleft(){

    int innum;
    cout<<"Enter the element to display the left siblings of: ";        
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
    
    //search for the position 





    gennode *temp;
    temp = new gennode;

    temp = treefind(innum);

    //cout<<temp->item<<endl;
    if (temp->item != innum){
        cout<<"Node does not exist."<<endl;
        return false;
    }else{
        
        if(temp->prevsibling != NULL){
            temp = temp->prevsibling;
            while(temp->prevsibling !=NULL){
                cout<<temp->item<<endl;
                temp = temp->prevsibling;
            }
            cout<<temp->item<<endl;
        }else{
            cout<<"The node has no left siblings."<<endl;
        }


        return true;

    }


}



bool generaltree::displayright(){

    int innum;
    cout<<"Enter the element to display the right siblings of: ";        
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
    
    //search for the position 





    gennode *temp;
    temp = new gennode;

    temp = treefind(innum);

    //cout<<temp->item<<endl;
    if (temp->item != innum){
        cout<<"Node does not exist."<<endl;
        return false;
    }else{
        
        if(temp->siblinglist != NULL){
            temp = temp->siblinglist;
            while(temp->siblinglist !=NULL){
                cout<<temp->item<<endl;
                temp = temp->siblinglist;
            }
            cout<<temp->item<<endl;
        }else{
            cout<<"The node has no right siblings."<<endl;
        }


        return true;

    }


}



bool generaltree::displayall(){

    int innum;
    cout<<"Enter the element to display all of the siblings of: ";        
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
    
    //search for the position 





    gennode *temp;
    temp = new gennode;

    temp = treefind(innum);

    //cout<<temp->item<<endl;
    if (temp->item != innum){
        cout<<"Node does not exist."<<endl;
        return false;
    }else{
        
        if(temp->prevsibling != NULL){
            temp = temp->prevsibling;
            while(temp->prevsibling != NULL){
                //cout<<temp->item<<endl;
                temp = temp->prevsibling;
            }
            while(temp->siblinglist != NULL){
                if(temp->item != innum){
                    cout<<temp->item<<endl;
                    temp = temp->siblinglist;
                }else{
                    temp = temp->siblinglist;
                }
            }
            if(temp->item != innum){
                cout<<temp->item<<endl;
            }
        }else if(temp->siblinglist != NULL){
            temp = temp->siblinglist;
            //cout<<temp->item<<endl;
            while(temp->siblinglist != NULL){
                cout<<temp->item<<endl;
                temp = temp->siblinglist;
            }
            cout<<temp->item<<endl;
            return true;

        }else{
            cout<<"The node has no siblings."<<endl;
        }


        return true;

    }


}







//not a recursive find
gennode* generaltree::treefind(int finditem){
    
    gennode *temp;
    temp = new gennode;
    //temp->item = finditem;
    temp = root;


    if(temp->item == finditem){
        //display the children here.



        return temp;

    }else{
        if(temp->firstchild == NULL){
            cout<<"The node does not exist."<<endl;
            return temp;
        }else{
            temp = temp->firstchild;
        }
        while(temp != root || temp->item == finditem){
            if(temp->item == finditem){
                //display here
                return temp;
            }else if(temp->firstchild != NULL){
                temp = temp->firstchild;
                //cout<<temp->item<<endl;

            }else if(temp->siblinglist != NULL){
                temp = temp->siblinglist;
                //cout<<temp->item<<endl;
            }else{
                //cout<<"check"<<endl;
                temp = temp->parent;
                //cout<<temp->item<<endl;
                if(temp==root){
                    //cout<<"break out"<<endl;
                    return temp;
                }
                while(temp->siblinglist == NULL){
                    //cout<<"in here"<<endl;
                    if(temp->item == root->item){
                        cout<<"The node does not exist."<<endl;
                        return temp;
                    }else{
                        //cout<<"moving up"<<endl;
                        temp = temp->parent;
                    }

                }
                temp = temp->siblinglist;
            }
        }
        //temp2 = temp;

    }















    return temp;

}
