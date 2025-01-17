#include<bits/stdc++.h>
using namespace std;
#include "Node.cpp"

Node* insertNode(Node*head, int i, int data){
  Node* newNode = new Node(data);
  Node*temp=head;
  int cnt=0;
  if(i==0){
    newNode->next=head;
    head = newNode;
    return head;
  }
  while(temp!=NULL && cnt<i-1){
    temp=temp->next;
    cnt++;
  }
  if(temp!=NULL){
    newNode->next = temp->next;
    temp->next=newNode;
  }
  return head;
}

Node* takeinput(){
  int data;
  cin>>data;

  Node* head=NULL;
  while(data!=-1){
    Node* newNode = new Node(data);
  
    if(head==NULL){
      head = newNode;
    }else{
      Node*temp=head;
      while(temp->next!=NULL){
        temp=temp->next;
      }
      temp->next=newNode;
    }
    cin>>data;
  }
  return head;
}

void print(Node*head){
  Node*temp=head;
  while(temp!=NULL){
    cout << temp->data << " ";
    temp=temp->next;
  }
  cout << endl;
}

int main(){
  Node *head = takeinput();
  print(head);
  int data,pos;cin>>data>>pos;
  head = insertNode(head,pos,data);
  print(head);

}