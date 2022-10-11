


#include "listc.h"
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
  if(current != NULL){
    insertElement(current->item);
    current = current->next;
    while (current != l1.head){
      insertElement(current->item);
      current = current->next;
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
    //initial print to start
    if (temp != NULL){
      cout<< temp->item<<endl;
      temp = temp->next;
    }
    //loop through until temp is head, print each time
    while (temp != head){
      cout<< temp->item<<endl;
      temp = temp->next;
    }
  
  }




  int list::findElement(int element) const
  {

    node *current;
    if(head == NULL){
      //item not in list so return 0
      return 0;
    }else{
      int pos = 0;
      current = head;

  ///initial case to check head position
      pos = pos + 1;
      if(current->item == element){
        return pos;
      }else if(current->item > element){
        return 0;
      }else{
        current = current->next;
      }

      //loop through until at head again
      while(current != head){
        pos = pos + 1;
        if(current->item == element){
          return pos;
        }else if(current->item > element){
          return 0;
        }else{
          current = current->next;
        }
      }
    }
    return 0;




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
    node *temp, *current;
    temp = new node;
    temp->item = element;
    current = head;

    //empty
    if(numberofelements == 0){
      temp->next = temp;
      head = temp;
      numberofelements = numberofelements + 1;
    }else if(current->item >= element){
      
      
      temp->next = head;
      //pos 1 move to end to set next to new head
      while(current->next != head){
        current = current->next;
      }
      current->next = temp;
      head = temp;

      numberofelements = numberofelements + 1;

    }else{
        //not pos 1, move to pos and insert 
      while(current->next != head && current->next->item < element){
        current = current->next;
      }
      temp->next = current->next;
      current->next = temp;
      numberofelements = numberofelements + 1;


    }





  }//end of insert function



  bool list::deleteElement(int element){
    //empty list

    node *current, *prev;
    current = head;

    if(current == NULL){
      return false;
    }



    

    if(current->next == head){
      //ony one item
      if(current->item == element){
        //remove
        head = NULL;
        numberofelements = numberofelements - 1;
        return true;
      }else{
        //not in list
        return false;
      }



    }else if(current->item == element){
      //in head
      node *temp;
      temp = current;
      temp = temp->next;
      while(temp->next != head){
        temp = temp->next;
      }
      temp->next = head->next;
      head = head->next;
      numberofelements = numberofelements - 1;
      return true;
    }else{

      prev = current;
      current = current->next;

      while(current != head){

        if(current->item == element){
          //remove
          numberofelements = numberofelements - 1;
          prev->next = current->next;
          delete current;
          return true;
        }
        //move to next node if not current
        prev = current;
        current = current->next;

      }


    }

    //if made this far the item was not successfully removed so return false
    return false;
  }//end of delete function






  int list::numberOfElements() const{
    //retun number elements variable
   return(numberofelements);
  }
