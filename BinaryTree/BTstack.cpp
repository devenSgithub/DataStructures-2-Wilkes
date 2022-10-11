//stack file




#include "BTstack.h"
stack::stack()
{
 top=NULL;
 numberofelements = 0;
}




stack::~stack()
{

    bool success = true;
    int temp1 = 0;
    int temp2 = 0;
    while(success){
        pop(temp1, temp2, success);
        //cout<<"del"<<endl;
    }
   // cout<<"del"<<endl;

 
}


void stack::push(int item, int index, bool& Success) {
    
    node* temp;
    temp = new node;
    temp->treeitem = item;
    temp->treeindex = index;

    if (top == NULL){
        top = temp;
        top->next = NULL;

    }else{
        temp->next = top;
        top = temp;
    }

    Success = true;


}




void stack::pop(int& removeditem, int& removedindex, bool& Success) {
    
    if(top == NULL){
        removedindex = -1;
        removeditem = -1;
        Success = false;
    }else{
        removedindex = top->treeindex;
        removeditem = top->treeitem;
        node* temp;
        temp = new node;
        temp = top;

        top = top->next;

        delete temp;
        Success = true;

    }

    
}



void stack::display() {
    
    node* temp;
    temp = new node;
    temp = top;

    while(temp != NULL){
        cout<< "Item: " << temp->treeitem<<"   Index: "<< temp->treeindex <<endl;
        temp = temp->next;
    }

    


}

