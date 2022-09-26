


#include "list.h"
list::list()
{
 head=NULL;
 numberofelements = 0;
}


list::list(string file)
{
  head=NULL;
  numberofelements = 0;

  int data;
  ifstream fin;
  fin.open(file.c_str());
  assert (fin.is_open());

  while (true){

    fin>>data;
    if (fin.eof() || !fin.good()){
      break;
    }
    //bool Success;
    insertElement(data);
    
  }


}


list::list(const list &l1){
  head=NULL;
  numberofelements = 0;

  node *current;
  current = l1.head;
  while (current != NULL){
    insertElement(current->item);
    current = current->next;
  }

/*
  while(l1 != NULL){
    insertElement(l1.item);
    l1=l1.next;
  }
*/

}


list::list(const list &l1, const list &l2){

  head=NULL;
  numberofelements = 0;

  //intersection list constructor 
// in both list put in new list.
  node *current1, *current2;
  current1 = l1.head;
  current2 = l2.head;

  while(current1 != NULL && current2 != NULL){
    if (current1->item == current2->item){
      insertElement(current1->item);
      current1 = current1->next;
      current2 = current2->next;

    }else if(current1->item > current2->item){
      current2 = current2->next;
      
    }else{
      current1 = current1->next;
    }
  
  
  
  }


}










list::~list()
{
  while (numberofelements>0)
  {
    deleteElement(head->item); //delete next element
    //cout<<"clearing"<<endl;
  }
}




  //list operations
  void list::displayList() const
  {
    node *temp;
    temp = new node;
    temp = head;
    //loop through until next item is null, start at head, print each time
    while (temp != NULL){
      cout<< temp->item<<endl;
      temp = temp->next;
    }
  
  }




  int list::findElement(int element) const
  {
    
    node *current;
    //empty list 
    if(head == NULL){
      //item not in list so return 0
      return 0;
    }else{
      int position = 0;
      current = head;
      //if list is not empty, loop through until the item is found. inc position by one for the return value.
      while(current != NULL){
        position = position + 1;
        if(current->item == element){
          return position;
          break;
        }else{
          current = current->next;
        }
      }
    }
    //if loop exited item not in list so return 0

    return 0;
  }





void list::fileInsert(string file){



  int data;
  ifstream fin;
  fin.open(file.c_str());
  assert (fin.is_open());

  while (true){

    fin>>data;
    if (fin.eof()){
      break;
    }
    //bool Success;
    insertElement(data);
    
  }







}
















//insert into a ordered list cases: empty;first;middle;last
  void list::insertElement(int element)
  {
    node *temp, *current, *prev;
    temp = new node;
    temp->item = element;
    current = head;
    prev = NULL;
    //empty case / element in pos 1 head case
    if(numberofelements == 0 || head->item >= element){

      temp->next = head;
      head = temp;
      numberofelements = numberofelements + 1;

    }else{
      //list not empty find the position and insert item
            //current starts at head
      while(current != NULL){
        
        
        if(current->item < element){
          //go until current item is larger then the element
          prev = current;
          current = current->next;
        }else{
          //once get larger val go back to current and insert
          current = prev;
          temp->next = current->next;
          current->next = temp;
          numberofelements = numberofelements + 1;
          break;
        }


      }
      //no larger insert at end of list
      if(current == NULL){
        prev->next = temp;
        temp->next = NULL;
        numberofelements = numberofelements + 1;

      }
      


    }


  }//end of insert function



//only deletes the first occurance of a value entered
//to change to all occurances loop the list and remove each time value is seen until current is null
//delete an element cases: empty;inlisthead;inlistnothead;notinlist
  bool list::deleteElement(int element){

    node *current, *prev;
    
    //prev = head;
    current = head;
    while(current != NULL){
      if(current->item == element){
        break;
      }else{
        prev = current;
        current = current->next;
      }
    }


    //if the list is empty loop ends and will go to this check or
    // if the item was found or not found 
    if(current == NULL){
      //not in the list or list was empty 
      //done: return false 
      return false;
    }else{

      //the item was found and can be removed
      //decrease the item count
      numberofelements = numberofelements - 1;

      //if head change head to next del current
      if(current == head){
        head = head->next;
        delete current;
      }else{//not the head, current is set to next(using prev) and delete current
        prev->next = current->next;
        delete current;
      }
    }
    
    //if made this far the item was successfully removed so return true
    return true;
  }//end of delete function






  int list::numberOfElements() const{
    //retun number elements variable
   return(numberofelements);
  }