#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(int data){
    this->data=data;
    next=NULL;
  }
};

void length(Node*head){
  int cnt=0;
  Node *temp=head;
  while(temp!=NULL){
    temp =temp->next;
    cnt++;
  }
  cout << cnt << endl;
}

Node * takeInput(){
  int data;
  cin>>data;

  Node*head=NULL,*tail=NULL;
  while(data!=-1){
    Node *newNode= new Node(data);
    if(head==NULL){
      head=newNode;
      tail=newNode;
    }
    else{
      tail->next=newNode;
      tail=tail->next;
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




int main(){
  cout << "Enter LL : ";
  Node* head = takeInput();
  cout <<"entered ll and its length:";
  print(head);
  length(head);

  int n;
  cout << "enter No. of elements to be inserted:"; 
  cin>>n;

  for(int i=0;i<n;i++){
    cout << "enter element no." << i << ":"; 
    int data;cin>>data;
    cout << "Enter the posititon of the element:";
    int pos;cin>>pos;
    
    head=insertNode(head,pos,data);
    
  }

  cout << "New LL and its length:";
  print(head);
  length(head);

}

