


#include<cassert>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct node
{
  int item;
  node *next;
};
class list
{
  public:
  list();
  list(string file);
  list(const list &l1);
  
  ~list();
  //list operations
  void displayList() const;
  int findElement(int element) const;
  void insertElement(int element);
  void fileInsert(string file);
  bool deleteElement(int element);
 
  int numberOfElements() const;

  private:
  node *head;
  int numberofelements;


};