 #include<cassert>
#include<iostream>
#include<string>
#include<fstream>
#include "PQHeap.h"
using namespace std;

class huffman
{
  public:
  
  huffman(string fn);
  ~huffman();
  // operations
  void displayCode(); 
 
  

  private:
 
  void inOrder(string s,huffmannode *t) ;
  
  huffmannode * finalhuffmantree;
  


};