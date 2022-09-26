

#include <fstream>
#include <cassert>
#include <stddef.h>
#include <assert.h>

//default constructor for the object
template<class T>
collection<T>::collection(){
  //array = null;
  numOfValues=0;//max of 20

}

//File constructor for the object takes a file name
template <class T>
collection<T>::collection(string file){  
//opens a file reads the data and calles insert function to add the vales to the collection
  numOfValues=0;//max of 20

  T data;
  ifstream fin;
  fin.open(file.c_str());
  assert (fin.is_open());

  while (true){

    fin>>data;
    if (fin.eof()){
      break;
    }
    bool Success;
    Insert(data, Success);
    
  }

  
} 



template <class T>
void collection<T>::Insert(T NewItem, bool& Success){       
// adds values to the collection 
//checks if the max number of values has been reached if so adds nothing to the collection           
  if (numOfValues==20){

    Success=false;
  }else{
    //if not adds the value to the next open spot in the collection 
    Success=true;
    array[numOfValues]=NewItem;
    numOfValues++;
  }
} //end insert




template <class T>
void collection<T>::Display()
{
  for (int i=0;i<numOfValues;i++){
    //loops through the collection array and prints out the values one per line
    cout<<"Item "<<i+1<<" = "<<array[i]<<endl;
    
  }
}//end display

  
//
template <class T>
collection<T>& collection<T>::operator = (const collection <T>&Rhs){
  //check if the left is the right if so returns self 
  if (this == &Rhs){ 
    return *this;
  }else{
    //otherwise it should array data from the right into the left. 
    //delete [] array;
    //array = new T[20];
    for(int i = 0; i<=20; i++){
      array[i] = Rhs.array[i];
    }
    return *this;
  }

}//end op=



template <class T>
bool collection<T>::operator == (const collection <T> &col1){
  //checks if the number of values in the collection are the same if not returns false 
  //if(numOfValues != col1.numOfValues){
    //return false;
  //}
  //above not necessary since max array is alreay set to 20 so as long as items in the array are equal
  // the number of items will be accounted for in the loop below as well
  //if so, loops throught the array checking each data member against the other for similariy if not the same returns false
  for(int i = 0; i<numOfValues; i++){
    if(array[i] != col1.array[i]){
      return false;
    }
  }
  //if neither is false true is returned


}//end op==

