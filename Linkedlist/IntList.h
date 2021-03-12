
#ifndef INTLIST_H
#define INTLIST_H

struct ListNode{
  int value;
  struct ListNode* next;
};

class IntList{
  private:
    ListNode* head; //List head pointer

  public:
    //Constructor
    IntList(){
      head = nullptr;
    }
    //Destructor
    ~IntList();

    void insertNode(int);
    void deleteNode(int);
    void print();
    void reverse();
    void removeByPos(int);
    void destroy();
};

#endif

