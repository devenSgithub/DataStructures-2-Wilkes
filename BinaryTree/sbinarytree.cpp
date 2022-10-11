//tree file include the stack stuff


#include "BTstack.h"
#include "sbinarytree.h"
#include <math.h>

struct treenode
{

    int size = 100;
    int *treearray;
  
  
};




binarytree::binarytree(){
    
    treearray = new int[size];
    for (int i = 0; i < size; i++) {
      treearray[i] = -1;
    }

    

    height = 0;
    numberofelements = 0;
}




binarytree::~binarytree()
{
 //nothing needed
}



void binarytree::additem(int item, bool& Success) {
    
    if(numberofelements == 101){
        //tree full cannot add
        Success = false;
    }else{
        //not full add to array and increase count
        treearray[numberofelements] = item;
        numberofelements = numberofelements + 1;
        Success = true;
        //get a new height to store using the hieght function when added//====================
        height = treeheight();


    }


}


void binarytree::deleteitem(int& item, bool& Success) {
    
    if(numberofelements == 0){
        //tree empty cannot delete
        Success = false;
    }else{
        //not empty can delete and decrease count
        item = treearray[numberofelements - 1];
        treearray[numberofelements - 1] = -1;
        numberofelements = numberofelements - 1;
        Success = true;
        //get a new height to store using the hieght function when added//====================
        height = treeheight();
    }


}

//displayall
void binarytree::displayall() {//function used to test stuff
    int temp = numberofelements-1;
    int temp1,temp2;
    stack tempstack;
    bool suc = true;
    while(temp != -1){
        tempstack.push(treearray[temp], temp, suc);
        //cout<<treearray[temp-1]<<endl;
        temp--;
    }
    tempstack.pop(temp1,temp2,suc);
    while (suc){
        cout<<temp1<<"   "<<temp2<<endl;
        tempstack.pop(temp1,temp2,suc);
        
    }

}

int binarytree::treeheight() {

    int temp = 0;
    int count = 0;
    do{
        // 2i+1 left child
        if(treearray[temp] != -1){
            count = count + 1;
        }
        temp = (2 * temp) + 1;
        


    }while(treearray[temp] != -1 && temp <= 100);

    return count;



}



int binarytree::treeelements() {

    return numberofelements;

}



void binarytree::displaylevel(int level) {

    if(level > height){
        cout<<"The level selected is not in the tree."<<endl;
    }else{
        int temp = 0;
        for (int i = 1; i <= level-1; i++) {
            temp = (temp * 2) + 1;
        }
        int numatheight = pow(2, (level-1));
        for ( int j = temp; j < (temp + numatheight); j++) {
            if(treearray[j] != -1){
                cout<<treearray[j]<<endl;
            }
        }
        //
    }



}




void binarytree::inorderdisplay() {//not working 

    stack newstack;
    //int current = 0;
   // int remitem = 0;
  //  int remindex = 0;
  //  bool success = true;


/*
    while(true){
        while(current != -1 || current >size){
            newstack.push(treearray[current], current, success);
            current = (2*current) + 1;
        }

        //check if stack is empty
        newstack.pop(remitem,remindex,success);
        if(success == false){
            //if yes end
            break;
        }else{//else add item back and contiune
            newstack.push(remitem, remindex, success);
        }    

        newstack.pop(remitem,remindex,success);    
        cout<<remitem<<"   "<<remindex<<endl;
        current = (current - 1)/2;
        current = (2*current) + 2;

    }


*/


  

}

void binarytree::preorderdisplay() {//not working 
    stack newstack;
    //int current = 0;
   // int remitem = 0;
   // int remindex = 0;
   // bool success = true;


    

}

void binarytree::postorderdisplay() {//not working 
    stack newstack;
    //int current = 0;
   // int remitem = 0;
   // int remindex = 0;
  //  bool success = true;
    

}
//end of file