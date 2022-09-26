
#include <iostream>
using namespace std;

template <class T> class collection{
  public:
   
   //default and file constructor
    collection();
    collection(string file);
    //display collections
    void Display();
    //add to collection
    void Insert(T NewItem, bool& Success);
    //overload operators
    collection <T> & operator=(const collection<T>& Rhs);
    bool operator==(const collection<T>& col1);
    
  
  private:
    // defaults to a max size of 20 as per the specification requirment
    T array[20];
    //starts as 0 adds as items are added to the collection + used as check to prevent over 20
    int numOfValues = 0;
   
};

#include "collection.cpp"
