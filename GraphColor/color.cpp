//color.cpp

#include "color.h"  // header file
#include <stddef.h>  // for NULL
#include <iostream>


colorgraph::colorgraph()  
{
   
    int indata;



    string fn;
    cout<<"Enter the name of a file containing the data"<<endl;

    // check for valid input have user reenter until a valid input is accepted
    while(true){
        
        cin >> fn;
        if(cin.good()){
            break;
        }else{
            cout<<"You entered invalid input, reenter a file name \n";
            cin.clear();
            cin.ignore(120,'\n');
        }

    }

    cout << "You entered: " << fn << endl;


    ifstream fin;
    fin.open(fn.c_str());
    assert (fin.is_open());

    fin>>indata;
    //cout<<indata<<endl;//test
    numberofelements = indata;

    //initilize adj array to NULL
    adj = new graphnodep[indata];
    for (int i = 0; i < indata; i++){
        adj[i]=NULL;
    }

    indegreearray = new inDegreep[indata];
    for (int i = 0; i < indata; i++){
        inDegree *tempdegree;
        tempdegree = new inDegree;
        tempdegree->nodename = i;
        tempdegree->indegreeOfNode = 0;
        indegreearray[i]=tempdegree;
    }

    coloredarray = new int[indata];
    for (int i = 0; i < indata; i++){
        coloredarray[i]=0;//0 will be uncolored
    }

    //indegreearray//coloredarray
    int intemp;
    int intemp2;


    while (true){

        fin>>indata;
        if (fin.eof()){
            break;
        }
        intemp = indata;
        fin>>indata;
        intemp2 = indata;

        if (fin.eof()){
            break;
        }

        //cout<<"got data"<<intemp<<intemp2<<endl;working
        //increase indegree of both 
        inDegree *tempincrease1;
        tempincrease1 = new inDegree;
        tempincrease1 = indegreearray[intemp];
        tempincrease1->indegreeOfNode = tempincrease1->indegreeOfNode + 1;
        indegreearray[intemp]=tempincrease1;

        inDegree *tempincrease2;
        tempincrease2 = new inDegree;
        tempincrease2 = indegreearray[intemp2];
        tempincrease2->indegreeOfNode = tempincrease2->indegreeOfNode + 1;
        indegreearray[intemp2]=tempincrease2;



        graphnode *temp;
        temp = new graphnode;
        //add n2 node to n1 list and n1 to n2

        temp->name = intemp2;
        temp->next = NULL;
        if (adj[intemp] == NULL){
            adj[intemp] = temp;
        }else{
            temp->next = adj[intemp];
            adj[intemp] = temp;
        }
        //cout<<"entering 1"<<endl;//test

        graphnode *temp2;
        temp2 = new graphnode;
        temp2->name = intemp;
        temp2->next = NULL;
        if (adj[intemp2] == NULL){
            adj[intemp2] = temp2;
        }else{
            temp2->next = adj[intemp2];
            adj[intemp2] = temp2;
        }
        //cout<<"entering 2"<<endl;//test



    }
    cout<<"\nThe graph has been made."<<endl;
    cout<<"\nDisplaying the adjacency list:"<<endl;

    graphnode *tempdisplay;
    tempdisplay = new graphnode;

    for (int i = 0; i < numberofelements; i++){
        
        cout<<"The list for "<< i <<": "<<endl;

        tempdisplay = adj[i];
        
        while(tempdisplay != NULL){
            cout<< tempdisplay->name <<endl;
            tempdisplay = tempdisplay->next;
           
        }

    }

    inDegree *tempdisplaydeg;
    tempdisplaydeg = new inDegree;
    cout<<"\nDisplaying the degree list:"<<endl;
    for (int i = 0; i < numberofelements; i++){
        tempdisplaydeg = indegreearray[i];
        cout<<"The degree of "<< i <<": "<<tempdisplaydeg->indegreeOfNode<<endl;

    }

    
    //cout<<indegreearray[1]->indegreeOfNode<<"newtest"<<endl;//working


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




colorgraph::~colorgraph()
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



int colorgraph::colorit(){

    
    mergeSort(indegreearray);


    
    //check
    inDegree *tempdisplaydeg;
    tempdisplaydeg = new inDegree;
    cout<<"\nDisplaying the sorted degree list:"<<endl;
    for (int i = 0; i < numberofelements; i++){
        tempdisplaydeg = indegreearray[i];
        cout<<"The degree of "<< tempdisplaydeg->nodename <<": "<<tempdisplaydeg->indegreeOfNode<<endl;

    }

    cout<<"\nColoring the graph."<<endl;

    int color = 1;
    //welsh color
    bool test = true;
    while(test){
        
        for (int i = 0; i < numberofelements; i++){
            if(coloredarray[indegreearray[i]->nodename] == 0){
                coloredarray[indegreearray[i]->nodename] = color;
                test = true;
                //cout<<"colored "<<endl;
                color++;
                break;
            }
            test = false;//break out completed colors

            //cout<<"still here "<<endl;

        }

        //cout<<"out  here "<<endl;
        for (int i = 0; i < numberofelements; i++){
            if(coloredarray[i] == 0){
                //check table and compares
                //cout<<"a color is 0: "<<i<<endl;
                graphnode *temp;
                temp = new graphnode;
                temp = adj[i];
                bool testflag = false;
                while(temp != NULL){
                    
                    if(coloredarray[temp->name] == color-1){
                        //cout<<"the color is adj"<<endl;
                        testflag = true;
                        //break;//adj with the same color
                    }


                    temp = temp->next;
                    
                }
                if(!testflag){
                    //cout<<"in here"<<endl;
                    coloredarray[i] = color-1;
                }


            }
            //cout<<"backin "<<endl;

        }

    }

    //print array test.
    /*
    for (int i = 0; i < numberofelements; i++){
        cout<<"colors:"<<endl;
        cout<<i<<" the color is "<<coloredarray[i]<<endl;

    }
*/

    return color - 1;
}

void colorgraph::Printcolor(){

    cout<<"\nPrinting the colored list:"<<endl;
    for (int i = 0; i < numberofelements; i++){
        
        cout<<"Node "<<i<<": the color is: "<<coloredarray[i]<<endl;

    }

}







void colorgraph::mergeSort(inDegreep * a)  {

    //make an empty copy of a
    inDegreep *tmpArray;
    tmpArray = new inDegreep[numberofelements];
    for (int i = 0; i < numberofelements; i++){
        tmpArray[i]=NULL;
    }

    mergeSort( a, tmpArray, 0, numberofelements - 1 );

/*
    inDegree *tempdisplaydeg;
    tempdisplaydeg = new inDegree;
    cout<<"Displaying the sorted degree list:"<<endl;
    for (int i = 0; i < numberofelements; i++){
        tempdisplaydeg = a[i];
        cout<<"The degree of "<< tempdisplaydeg->nodename <<": "<<tempdisplaydeg->indegreeOfNode<<endl;

    }
*/
}






void colorgraph::mergeSort(inDegreep * a, inDegreep * tmpArray, int left, int right)  {

    if( left < right ){
        int center = ( left + right ) / 2;
        mergeSort( a, tmpArray, left, center );
        mergeSort( a, tmpArray, center + 1, right );
        merge( a, tmpArray, left, center + 1, right );
    }

}




void colorgraph::merge(inDegreep * a, inDegreep * tmpArray, int leftPos, int rightPos, int rightEnd)  {
   
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    // Main loop
    while( leftPos <= leftEnd && rightPos <= rightEnd ){
        if( a[ leftPos ]->indegreeOfNode >= a[ rightPos ]->indegreeOfNode ){
            tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
        }else{
            
            
            tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );
        }
    }
    while( leftPos <= leftEnd ){ // Copy rest of first half
        tmpArray[ tmpPos++ ] = std::move( a[ leftPos++ ] );
    }
    while( rightPos <= rightEnd ){ // Copy rest of right half
        tmpArray[ tmpPos++ ] = std::move( a[ rightPos++ ] );
        
    }


    // Copy tmpArray back
    for( int i = 0; i < numElements; ++i, --rightEnd ){
        a[ rightEnd ] = std::move( tmpArray[ rightEnd ] );
    }




}





