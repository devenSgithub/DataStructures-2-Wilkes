
#include<cassert>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct gennode{
    int item;
    gennode *firstchild;
    gennode *siblinglist;
    gennode *prevsibling;
    gennode *parent;
};
class generaltree
{
  public:
  generaltree();
  //list(string file);
  //list(const list &l1);
  
 // ~list();
  //list operations
  //void displayList() const;
  //int findElement(int element) const;
  //void insertElement(int element);
  bool displayleft();
  bool displayright();
  bool displayall();
  bool displayparent();
  bool treeinsert();
  bool displaychildren();
  bool elementexist(int num);
  gennode* treefind( int finditem);
 
  //int numberOfElements() const;

  private:
  gennode *root;
  //int numberofelements;


};