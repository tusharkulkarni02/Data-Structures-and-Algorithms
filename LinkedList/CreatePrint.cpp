#include<bits/stdc++.h>
using namespace std;

class Node{

  public: 
  int data;     // contains data of current node;
  Node *next;   // this is pointer of (NODE) type coz it contains address of next node

  Node(int data){
    this->data=data;
    next=NULL;
  }

};

void print (Node *head){
  Node *temp=head;        // always create temp to not tamper with the head pointer's address

  while(temp!=NULL){
    cout << temp->data << " ";
    temp = temp->next;
  }

}
int main(){
  Node n1(10);
  Node *head = &n1;    // Always create head pointer after initialising the first node of the linkedlist
  Node n2(20);
  Node n3(30);
  Node n4(40);

  n1.next=&n2;
  n2.next=&n3;
  n3.next=&n4;

  print(head);
}