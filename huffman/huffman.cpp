
#include "huffman.h"

huffman::huffman(string fn)
{


    //read in the data and store in an array that has the frequency and char data
    int datasize = 26; //26 possible chars restriction 
    int a[datasize];
    //initilize all values as 0
    for(int i = 0; i <= datasize-1; i++){
        a[i] = 0;
        //cout<<i<<a[i]<<endl;
    }
    //read in data and store in position
    char data;
    ifstream fin;
    fin.open(fn.c_str());
    assert (fin.is_open());

    while (true){

        fin>>data;
        if (fin.eof() || !fin.good()){
        break;
        }
        //bool Success;
        //cout<<"got data"<<endl;
        a[data-'A'] = a[data-'A']+1;
    
    }
    Heap myheap; 
    for(int i = 0; i <= datasize-1; i++){
        //cout<<i<<" "<<a[i]<<endl;//check pos
        huffmannode *temp;
        temp = new huffmannode;
        if(a[i]>0){
            temp->left = NULL;
            temp->right = NULL;
            temp->frequency = a[i];
            temp->symbol = i+65;
            temp->nodetype = leaf;
            cout<<temp->symbol<<","<<temp->frequency<<endl;//check 

            //insert the created node into the heap
            myheap.heapInsert(temp); 
        }

    }
    myheap.heapDisplay();
    huffmannode *p;
    p = new huffmannode;
    huffmannode *q;
    q = new huffmannode;
    int n = myheap.heapSize();
    //remove and insert until only 1 left
    
    for(int i = 1; i<=n-1;i++){
        p = myheap.heapDelete();
        q = myheap.heapDelete();
        huffmannode *r;
        r = new huffmannode;
        r->left = p;
        r->right = q;
        r->frequency = p->frequency + q->frequency;
        r->nodetype = nonleaf;
        //insert r back in
        myheap.heapInsert(r);
    }
    //remove the final node 
    huffmannode *finaltree;
    finaltree = new huffmannode;
    //get the last item remaining which would be the final tree
    finaltree = myheap.heapDelete();
    //set to final tree 
    finalhuffmantree = finaltree;
//call displayCode

}//end of function constructor

huffman::~huffman()
{

//work in reverse to destroy
//put everything back in the heap one level at a time and destroy each internal node


cout<<"Destructor executing"<<endl;  
}


void huffman::inOrder(string s,huffmannode *t)
{
	//display the huffmancode for the characters
	
}
//list operations
void huffman::displayCode() 
{
string s;
 
inOrder(s,finalhuffmantree);
}
  