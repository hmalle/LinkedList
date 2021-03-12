
#include <string>
#include <iostream>
#include "IntList.h"
using namespace std;

int main(){
  /// Create an instance of IntList.
  IntList myList;
  cout << "**********************************************************************************\n";
  cout << "Testing the insertNode function, nodes inserted in this order: 12, 4, 3, 5, 77, 13\n";
  cout << "**********************************************************************************\n";
  /// Build a list.Will test the program with : sorted list 3,4,5,12,13,77
  myList.insertNode(12);
  myList.insertNode(4);
  myList.insertNode(3);   // beginning
  myList.insertNode(5);   //middle
  myList.insertNode(77);  //end
  myList.insertNode(13);

  /// Display the nodes.
  cout << "Here are the values in myList:\n";
  myList.print();
  cout << "********************************************\n";
  cout << "Testing the removeByPos function\n";
  cout << "********************************************\n";
  /// Remove node at position 0( beginning position ).
  cout << "Removing node at position 0 which is the first node, 3 should be removed...\n";
  myList.removeByPos(0);
  myList.print();

  /// Remove node at position 4 ( end position).List now 4,5,12,13,77
  cout << "Removing node at position 4 which is the last node, 77 should be removed...\n";
  myList.removeByPos(4);
  myList.print();

  /// Remove node at position 2 (middle position). List now 4,5,12,13
  cout << "Removing node at position 2 which is a middle node, 12 should be removed...\n";
  myList.removeByPos(2);
  myList.print();

  /// Try a position that is too big.List should remain the same
  cout << "Removing node 99, a position that is too big.List should remain the same...\n";
  myList.removeByPos(99);
  myList.print();

  cout << "\n\nAdding back the deleted nodes so we can rest the deleteNode function... \n\n";
  myList.insertNode(12);
  myList.insertNode(3);
  myList.insertNode(77);
  myList.print();

  /// delete node.
  cout << "\n\n Testing the deleteNode function\n\n";
  cout << "Removing number 5, the first node, 5 should be removed...\n";
  myList.deleteNode(5);
  myList.print();

  cout << "Removing number 77 which is at the end, 77 should be removed...\n";
  myList.deleteNode(77);
  myList.print();


  cout << "Removing number 12 which is in the middle of the list, 12 should be removed...\n";
  myList.deleteNode(12);
  myList.print();

  cout << "Removing number 100 which is not in the list, list should remain the same...\n";
  myList.deleteNode(100);
  myList.print();

  cout << "\n\nAdding back the deleted nodes \n";
  myList.insertNode(12);
  myList.insertNode(5);
  myList.insertNode(77);
  myList.print();

  cout << "********************************************\n";
  cout << "Testing the reverse function\n";
  cout << "********************************************\n";
  myList.reverse();
  myList.print();

  return 0;
}

