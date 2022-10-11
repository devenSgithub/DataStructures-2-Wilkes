


#include<cassert>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct node
{
  int treeitem;
  int treeindex;
  node *next;
};
class stack
{
  public:
  stack();
  
  ~stack();
  //list operations
  void push(int item, int index, bool& Success);
  void pop(int& removeditem, int& removedindex, bool& Success);
  void display();
 

  private:
  node *top;
  int numberofelements;


};