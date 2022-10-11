//tree file include stack stuff




#include<cassert>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;


struct treenode;//in implementation file

class binarytree
{
  public:
  binarytree();
  
  ~binarytree();
  //list operations
  void additem(int item, bool& Success);
  void deleteitem(int& item, bool& Success);
  void displayall();//function used for testing
  int treeheight();
  int treeelements();
  void displaylevel(int level);
  //void pop(int& removeditem, int& removedindex, bool& Success);
  //void display();
  void inorderdisplay();
  void preorderdisplay();
  void postorderdisplay();
 

  private:
  //array
  //height
  //numele
  //size 100
  //
  //node *top;
  int size = 100;
  int height = 0;
  int numberofelements = 0;

  int *treearray;


};