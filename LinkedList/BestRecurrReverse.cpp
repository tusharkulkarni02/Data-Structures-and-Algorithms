#include<iostream>
#include"Node.cpp"
using namespace std;

Node* reverse(Node*head){
  if(head==NULL || head->next==NULL){
    return head;
  }

  Node* smallout=reverse(head->next);

  Node*tail=head->next;
  tail->next=head;
  head->next=NULL;

  return smallout;
}



Node* takeInput(){
  int data;cin>>data;
  Node* head=NULL,*tail=NULL;
  while(data != -1){
    Node* newNode= new Node(data);
    if(head==NULL){
      head=newNode;
      tail=newNode;
    }else{
      tail->next=newNode;
      tail=newNode;
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
  Node* head=takeInput();
  print(head);
  head=reverse(head);
  print(head);
}