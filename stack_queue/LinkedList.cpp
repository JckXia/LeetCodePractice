#include <iostream>
using namespace std;

class Node{
public:
  Node(int data):data{data}{
    next=nullptr;
  }

   int data;
    Node *next;
};

int main(){
  Node * linkedList=new Node(4);
 linkedList->next=new Node(5);
   linkedList->next->next=new Node(10);

   return 0;
}
