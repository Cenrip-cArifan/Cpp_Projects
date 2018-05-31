#include "Storage.h"
#include <cstdlib>

using namespace std;

Storage::Storage(){

  m_head = NULL;
  m_tail = NULL;
}

Storage::Storage(string fileName){

  /*  ifstream fileIn(fileName.c_str());
  string rank, year, name, type;
  Node *newList = m_head;
  while(getline(fileIn, rank, '\t')){
    getline(fileIn, name, '\t');
    getline(fileIn, year, '\t');
    getline(fileIn, type);
    
    newList->data = Media(atoi(rank.c_str()), name, atoi(year.c_str()), type);
        
    newList->next = NULL;
  }
  fileIn.close();
  */

}


Storage::~Storage(){

  /*  Node *ptrDel = m_head;
  Node *temp;
  while(ptrDel != NULL){
    temp = ptrDel;
    ptrDel = ptrDel->next;
    delete temp;
    temp = NULL;
  }

  m_tail = m_head = NULL;
  */
}

void Storage::sortByRank(){

  Node *first, *second;
  Media tempMedia;

  for(first = m_head; first != NULL; first = first->next){
    for(second = first->next; second != NULL; second = second->next){
      if(first->data.getRank() > second->data.getRank()){
	tempMedia = first->data;
	first->data = second->data;
	second->data = tempMedia;
      }
    }
  }
}

void Storage::insertEnd(Media myMedia){

  Node *temp = new Node;
  temp->data = myMedia;
  temp->next = NULL;

  if(m_head == NULL){
    m_head = temp;
    m_tail = temp;
  }
  else{
    m_head = m_tail;
    while(m_tail->next){
      m_tail = m_tail->next;
    }
    m_tail->next = temp;
  }  
}


bool Storage::checkName(string name){

  if(m_head == NULL && m_tail == NULL){
    return false;
  }

  Node *currList;
  for(currList = m_head; currList != NULL; currList = currList->next){
    if(currList->data.getName().compare(name)==0){
      return true;
    }
  }
  return false;
}

void Storage::removeByName(string name){

  checkName(name);
  Node *prev = NULL;
  Node *curr = m_head;
  
  while(curr != NULL && curr->data.getName().compare(name) != 0){
    prev = curr;
    curr = curr->next;
  }
  //remove the node (3 cases to check for)
  //case1: curr is the head
  //case2: curr is the tail
  //else case3: curr is in the middle somewhere
  if(curr == m_head && prev == NULL){
    m_head = curr->next;
    curr->next = NULL;
  }
  else{ 
    if(curr == m_tail){
      m_tail = prev;
    }  
    prev->next = curr->next; //previous link is linked to the next link after
                             //current link to delete current node
    curr->next = NULL;
  }
  delete curr;
  curr = NULL;
}


void Storage::printStorage(bool isNumbered){

  Node *currList;
  isNumbered = false;
  if(m_head == NULL){
    cout << "List is empty" << endl;
  }
  else{
    for(currList = m_head; currList != NULL; currList = currList->next){
      while(!isNumbered){
	cout << currList->data.getName() << endl;
	currList = currList->next;
      }
    }
  }
}

void Storage::printByMedia(string type){

  Node *currList = m_head;
  

  if(m_head == NULL){
   
    cout << "List empty\n";
  }
  cout << "What type of media of the media?" << endl
       << "BLURAY, DVD, PS4, XBOX" << endl;
  cin >> type;

  cout << "Rank\t" << "Name" << endl;

  for(currList; currList != NULL; currList = currList->next){
    if(currList->data.getType().compare(type) == 0){
      cout << currList->data.getRank() << '\t'
	   << currList->data.getName() << endl;
	}
    else if(currList->data.getType().compare(type) == 0){
      
      cout << currList->data.getRank() << '\t'
	   << currList->data.getName() << endl;
    }
    else if(currList->data.getType().compare(type)){
      
      cout << currList->data.getRank() << '\t'
	   << currList->data.getName() << endl;
    }
    else{
      
      cout << currList->data.getRank() << '\t'
	   << currList->data.getName() << endl;
    }
  }
}



void Storage::printByRank(){

  Node *currList;
  bool isEmpty = false;

  if(m_head == NULL && m_tail == NULL){
    isEmpty = true;
  }
  else{
    cout << "Rank\t" << "Name" << endl;
    for(currList = m_head; currList != NULL; currList = currList->next){
      if(currList->data.getRank() < currList->next->data.getRank()){
	  cout << currList->data.getRank() << '\t'
	       << currList->data.getName() << endl;
      }
      else{
	cout << currList->next->data.getRank() << '\t'
	     << currList->next->data.getName() << endl;
      }
    }
    isEmpty = false;
  }
}
	
