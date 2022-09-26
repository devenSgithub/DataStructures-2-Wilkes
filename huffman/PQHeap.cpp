// *********************************************************
// Implementation file Heap.cpp for the ADT heap.
// *********************************************************
#include "PQHeap.h"  // header file for class Heap

Heap::Heap() : size(0)
{
}  // end default constructor

bool Heap::heapIsEmpty() const
{
    if (size == 0){
        return true;
    }else{
        return false;
    }
   
}  // end heapIsEmpty

void Heap::heapInsert(huffmannode *newItem)
        
// Method: Inserts the new item after the last item in the
// heap and trickles it up to its proper position. The
// heap is full when it contains MAX_HEAP items.
{
    huffmannode *temp;
    temp = new huffmannode;
    temp->symbol = newItem->symbol;
    temp->frequency = newItem->frequency;
    temp->nodetype = newItem->nodetype;
    temp->left = newItem->left;
    temp->right = newItem->right;
    
    //cout<<temp->symbol<<", insert working, "<<temp->frequency<<endl;//check 

    
    if (size == MAX_HEAP){
        cout<<"heap full"<<endl;
    }else{
        size++;
        
        items[size-1] = temp;
        //move to proper position.
        int position = size-1;
        bool testcase = true;
        if (position == 0){
            testcase = false;
        }else{
            
            while(testcase){
                int parentpos = (position-1)/2;
                huffmannode *parenttemp;
                parenttemp = items[parentpos];
                huffmannode *postemp;
                postemp = items[position];
                if(parenttemp->frequency > postemp->frequency){
                    huffmannode *temp2;
                    temp2 = new huffmannode;
                    temp2 = parenttemp;
                    items[parentpos] = items[position];
                    items[position] = temp2;
                    
                }else{
                    testcase = false;
                }


            }
        }


       
    }
    
   
}  // end heapInsert

huffmannode* Heap::heapDelete()  //huffmannode *rootItem
        
// Method: Swaps the last item in the heap with the root
// and trickles it down to its proper position.
{
    huffmannode *temp;
    temp = new huffmannode;

    temp = items[0];
    //rebuild the heap so that heap is still a heap
    //move the last item in the array to the root 
    //decrease size by 1
    //
    items[0] = items[size - 1];
    //heap rebuild from the root position 0//
    //heapRebuild(0);
    size = size - 1;








    return temp;
}  // end heapDelete
// method returns the size of the heap
int Heap::heapSize()
{
    return size;
	
}//end of function

void Heap::heapRebuild(int root)
{
    //recursivly move the root to its correct position so that heap remains a min heap
   
}  // end heapRebuild
void Heap::heapDisplay()
{
    //display test
    huffmannode *temp;
    for(int i = 0; i <= size-1; i++){
        if(items[i]!=NULL){
            temp = items[i];
            
            cout<<"symbol = "<<temp->symbol<<", frequency = "<<temp->frequency<<" display test"<<endl;
        }
    }
   
  
}//end heapDisplay
// End of implementation file.