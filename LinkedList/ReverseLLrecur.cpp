#include<iostream>
#include"Node.cpp"

using namespace std;

class Pair{
  public:
  Node* head;
  Node* tail;
};

Pair reverse(Node* head){
  if(head==NULL || head->next==NULL){
    Pair ans;
    ans.head=head;
    ans.tail=head;
    return ans;
  }

  Pair smallout = reverse(head->next);
  smallout.tail->next=head;
  head->next=NULL;

  Pair ans;
  ans.head=smallout.head;
  ans.tail=head;

  return ans;
}

Node* reverseRecursive(Node*head){
  return reverse(head).head;
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
  Node* head = takeInput();
  print(head);
  head = reverseRecursive(head);
  print(head);
}