#include<iostream>
using namespace std;
#include"Node.cpp"


void print(Node*head){
  Node*temp=head;
  while(temp!=NULL){
    cout << temp->data << " ";
    temp=temp->next;
  }
  cout << endl;
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

Node* deleteNode(Node* head, int i){
  Node* temp = head;
  if(i==0){
    head = head->next;
    delete temp;
    return head;
  }else{
    int cnt = 0;
    while(temp!=NULL && cnt<i-1 ){
      temp=temp->next;
      cnt++;
    }
    if(temp!=NULL){
      Node* a = temp->next;
      Node* b = a->next;
      temp->next=b;
      delete a;
    }
  }
  return head;
}

int main(){
   Node* head = takeinput();
   print(head);
   int pos;cin>>pos;
   head = deleteNode(head,pos);
   print(head);
}