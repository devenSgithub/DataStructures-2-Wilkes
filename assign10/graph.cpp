
//graph.cpp
#include"queuei.h" // for queues
#include "graph.h"  // header file
#include <stddef.h>  // for NULL
#include <iostream>


graph::graph()  
{
    //set the topological list to NULL
    topologicallist = NULL;
    //var for the number of vertices
    int n;
      
    cout << "Enter the number of vertices: " << endl;
      
    // check for valid input have user reenter until a valid input is accepted
    while(true){
      
        cin >> n;
        if(cin.good() && n >= 0){
            break;
        }else{
            cout<<"You entered invalid input, reenter an integer \n";
            cin.clear();
            cin.ignore(120,'\n');
        }

    }

    cout << "You entered: " << n << endl;
    //set numberofelements to n for future use in BFS/DFS
    numberofelements = n;
    //initilize adj array to NULL
    adj = new graphnodep[n];
    for (int i = 0; i < n; i++){
        adj[i]=NULL;
    }

    char input;  
    //loop question until exited by user
    while(input != 'n'){

        cout << " \nDo you have an edge to enter? Enter: " << endl; 
        cout << "y for yes. " << endl; 
        cout << "n for no. " << endl; 
           
        cin >> input;
        cout << "	\nYou entered: " << input << endl; 

        //switch to handle the input chocies 
        switch(input)//could have used a if/else, switch not really necessary
        {
        
        case 'y': 
            cout << "Adding an edge." << endl;
            //Prompt the user first for the first node in the edge, n1, and then the second node in the edge, n2. 
            //Allocate a node to represent the edge, storing n2 in the name of the newly created node. 
            //Enter the newly created node into n1's adjacency list. 
            
            // get the first node
            cout << "Enter the first node in the edge: " << endl;
            int n1;

            // check for valid input have user reenter until a valid input is accepted
            while(true){
                cin >> n1;
                if(cin.good() && n1 < n){
                break;
                }else{
                cout<<"You entered invalid input, reenter an integer \n";
                cin.clear();
                cin.ignore(120,'\n');
                }
            }

            cout << "You entered: " << n1 << endl ;

            //get the second node to add to n1 list
            cout << "Enter the second node in the edge: " << endl;
            int n2;

            // check for valid input have user reenter until a valid input is accepted
            while(true){
                cin >> n2;
                if(cin.good() && n2 < n){
                break;
                }else{
                cout<<"You entered invalid input, reenter an integer \n";
                cin.clear();
                cin.ignore(120,'\n');
                }
            }

            cout << "You entered: " << n2 << endl ;

            //node to store n2
            graphnode *temp;
            temp = new graphnode;
            temp->name = n2;
            temp->next = NULL;

            //add n2 node to n1 list
            if (adj[n1] == NULL){
                adj[n1] = temp;
            }else{
                temp->next = adj[n1];
                adj[n1] = temp;
            }
            
            break; 

        case 'n': 
            cout << "No more edges to add." << endl;

            break;
        
        default:
            cout << "Invalid Selection. Please Enter Again." << endl; 
        }//switch end


        cout << endl; 
    }//loop end

/* testing check
    graphnode *temptest;
    temptest = new graphnode;
    temptest = adj[0];
    if(temptest != NULL){
        cout << temptest->name << endl; 
        temptest = temptest->next;
        cout<<"in here"<<endl;
    }
    //cout << temptest->name << endl; 
    //temptest = temptest->next;
    //cout << temptest->name << endl; 

*/

}  // end default constructor



graph::graph(const graph &g1){
    //copy constructor 
    //set to NULL
    topologicallist = NULL;
    //num to g1 num
    numberofelements = g1.numberofelements;
    //test check
    //cout<<numberofelements<<endl;

    //
    adj = new graphnodep[numberofelements];
    //loop through adj
    for (int i = 0; i < numberofelements; i++){
        
        //var to move through each list in adj
        graphnode *temp;
        temp = new graphnode;
        temp = g1.adj[i];

        //vars to get the next list item and the newly created list.
        graphnode *temp2;
        temp2 = new graphnode;
        graphnode *temp3;
        temp3 = new graphnode;

        //var to store the start position 
        graphnode *start;
        start = new graphnode;

        if(temp != NULL){
            //loop through

            temp2->name = temp->name;
            start = temp2;
            //temp2->next = NULL;
            while(temp!=NULL){
                //loop through putting each item into the list
                temp = temp->next;
                if(temp != NULL){
                    temp3->name = temp->name;
                    temp2->next = temp3;
                    temp2 = temp2->next;
                }
            }
            //set last position to NULL for searches.
            temp2->next = NULL;
            adj[i] = start;

        }else{
            //null just set to NULL
            adj[i] = NULL;
        }

    }

}



graph::~graph()
{
    //destructor
    //clear adj

    graphnode *temp;
    temp = new graphnode;

    for (int i = 0; i < numberofelements; i++){
        //adj[i]=NULL;
        temp = adj[i];
        //if(adj[i]==NULL){
            //cout<<"empty list"<<endl;
        //}
        while(adj[i] != NULL){
            temp = adj[i];
            adj[i] = temp->next;
            //delete check
            //cout<<"deleting "<<temp->name<<endl;
            delete temp;
        }

    }

}



bool graph::BFS(int V){

    //valid input
    if(V >= numberofelements || V < 0){
        return false; //V is not in the graph so end
    }
    //otherwise do BFS


    queueClass bfsqueue;
    bool successqueue;
    int outV;

    //array to marked visted nodes
    //0 not visited
    //1 is visited
    int visited[numberofelements];
    for (int i = 0; i < numberofelements; i++){
        visited[i] = 0;
    }

    visited[V] = 1;
    cout <<"BFS visiting: "<< V << endl;
    //enqueue V
    bfsqueue.QueueInsert(V, successqueue);

    while(!bfsqueue.QueueIsEmpty()){

        bfsqueue.QueueDelete(outV, successqueue);
        //outV adj list
        graphnode *temp;
        temp = new graphnode;
        temp = adj[outV];
        
        while (temp != NULL){
            //enqueue non visited
            if(visited[temp->name] == 0){
                bfsqueue.QueueInsert(temp->name, successqueue);
                visited[temp->name] = 1;
                cout <<"BFS visiting: "<< temp->name << endl;
            }

            //move to next in list
            temp = temp->next;
        }
    }

    //return true at end
    return true;

}



bool graph::DFS(int V){

    if(topologicallist != NULL){
        //must be cleared before starting for top case//
        graphnode *temp;
        temp = new graphnode;
        
        while(topologicallist != NULL){
            temp = topologicallist;
            topologicallist = topologicallist->next;
            delete temp;
        }
    }


    if(V >= numberofelements || V < 0){
        return false; //V is not in the graph so end
    }
    //otherwise do DFS

    //initialization
    //0 = white
    //1 = gray
    //2 = black

    int vistedcolorarray[numberofelements];
    for (int i = 0; i < numberofelements; i++){
        vistedcolorarray[i] = 0;
    }
    //for check
    /*
    for (int i = 0; i < numberofelements; i++){
        cout << vistedcolorarray[i] << endl;
    }
    */

    //v to end
    for (int i = V; i <= numberofelements - 1; i++){
        if (vistedcolorarray[i] == 0){
            DFSVisit(i, vistedcolorarray);
        }
            
    }
    //begining to V
    for (int i = 0; i <= V - 1; i++){
        if (vistedcolorarray[i] == 0){
            DFSVisit(i, vistedcolorarray);
        }          
    
    }

    //return true at end
    return true;

}

void graph::DFSVisit(int V, int* vistedcolorarray){
    //for check
    //cout << "in dfsvisit" << endl;
    /*graphnode *temp;
    temp = new graphnode;
    temp = adj[V]->next;
    if (temp!=NULL){
        cout << temp->name << endl;
    }
    cout << vistedcolorarray[V] << endl;
    vistedcolorarray[V] = 1;
    cout << vistedcolorarray[V] << endl;
    */

    vistedcolorarray[V] = 1;//1 is gray
    cout <<"DFS visiting: "<< V << endl;

    graphnode *temp;
    temp = new graphnode;
    temp = adj[V];
    
    while(temp != NULL){
        if(vistedcolorarray[temp->name] == 0){
            DFSVisit(temp->name, vistedcolorarray);
        }else if(vistedcolorarray[temp->name] == 1){
            //cycle exist 
            cycletest = true;
            
        }
        temp = temp->next;
    }
    
    vistedcolorarray[V] = 2;//black
    if(cycletest == false){
        //enter into topological list
        //topologicallist//headnode
        graphnode *tempin;
        tempin = new graphnode;
        tempin->name = V;
        tempin->next = topologicallist;
        topologicallist = tempin;
    }

}



//topological
void graph::topological(){

    cycletest = false;
    //calls dfs with 0
    cout <<"Calling DFS with 0."<< endl;
    DFS(0);

    if(cycletest){
        cout <<"A cycle exist in the graph so no list can be made."<< endl;
    }else{
        //display the sorted list.
        cout <<"A cycle does not exist in the graph. The results are:"<< endl;
        graphnode *temp;
        temp = new graphnode;
        temp = topologicallist;

        while(temp != NULL){
            cout <<temp->name<< endl;
            temp = temp->next;
        }

    }

}




