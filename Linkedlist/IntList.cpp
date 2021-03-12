
#include "IntList.h"
#include<iostream>
#include<string.h>
using namespace std;

void IntList::insertNode(int num){
  ListNode* currNode = head;
  ListNode* prevNode; 
  //Create the new node. 
  ListNode* newNode = new ListNode();
  newNode->next = nullptr; 
  newNode->value = num;

  if(head == nullptr){
    head = newNode; 
  }else if(head->value > num){
    //Insertion at the head  if the new node is smaller than the head->value. 
      newNode->next = head; 
      head = newNode; 
  }else { 
    //Insert any where else. 
    currNode = head; 
    while(currNode!= nullptr){
      if(currNode->value == num){
        return;
      }
      if(currNode->value > num){
        break;
      }
      prevNode = currNode; 
      currNode = currNode->next; 
    }
    //currNode is either a null pointer or at the position of insertion. 
    //Check if the value of the current is equal to the num
    if(currNode== nullptr){
      //Reached the end so insert the new node there. 
      prevNode->next = newNode; 
      return;
    }else{
    //currNode->value is greater than num. so Insert it btn curr and prev. 
      prevNode->next = newNode; 
      newNode->next = currNode; 
    }
  }
}

void IntList::deleteNode(int num){
  //Iterates the list and delete the node with the value of num
  ListNode* currPtr, *prevPtr;
  currPtr = head;
  prevPtr = head; 
  if(head == nullptr) return ;
  if(currPtr!=nullptr && currPtr->next == nullptr){
    //We have only one element
    if(currPtr->value != num) 
      return;
    else{
      delete currPtr;
      head = nullptr;
    }
    return;
  }
  while(currPtr->next != nullptr){
    if(currPtr->value == num){  //If the value matches, point to the pointer after.
      prevPtr->next = currPtr->next;
      delete currPtr;
      return;
    }
    prevPtr = currPtr;
    currPtr = currPtr->next;  //on to the next one.
  }
  if(currPtr->value == num){
    //The last element.
    prevPtr->next = nullptr; 
    delete currPtr;
  }
}

void IntList::print(){
  //Iterates through the linked-list and print each value. 
  ListNode* tmpPtr;
  tmpPtr = head;
  while(tmpPtr != nullptr){
    cout<< tmpPtr->value<<" ";
    tmpPtr = tmpPtr->next;
  }
  cout<<endl;
}

void IntList::reverse(){
  ListNode* prev=nullptr;
  ListNode* current= head; 
  ListNode* next = head->next;
  while( current != nullptr){
    next = current->next; 
    current->next = prev;
    prev = current; 
    current = next; 
  }
  head = prev;
}

void IntList::removeByPos(int pos){
  //Remove by position. uses 2 ptr, one for previous node and one for currentNode. 
  //Once the position is found, the previous node will point to the currentNode->next 
  //while the current node will be deleleted. 
  ListNode *currPtr, *prevPtr; 
  currPtr = head;
  if(head == nullptr){
    return;
  }else if (pos == 0 && head->next==nullptr){
    currPtr = head; 
    delete currPtr;
    head = nullptr;
  }else if(pos==0 && head->next != nullptr){
    currPtr = head;
    prevPtr = head->next;
    delete currPtr;   //Delete pos1
    head = prevPtr;   //Assign pos2 to head. 
  }
  else{
    prevPtr = head; 
    currPtr = head->next;
    int iter = 1;
    for( ; currPtr!=nullptr && iter!= pos; iter++){
      prevPtr= currPtr; 
      currPtr = currPtr->next; 
    }
    if(currPtr == nullptr || iter < pos){
      return ;
    }else{
      prevPtr->next = currPtr->next; 
      delete currPtr;
    }
  }
}

void IntList::destroy(){
  //Destroys the list using delete. Use 2 pointers one for the next node and another for the current node that will be deleted. 
  ListNode* currNode = head; 
  ListNode* nextNode = head;  //Initialize as head for now. 
  while(currNode != nullptr){
    nextNode = currNode->next;
    delete currNode; 
  }
}

//Destructor
IntList::~IntList(){
  destroy();
}

