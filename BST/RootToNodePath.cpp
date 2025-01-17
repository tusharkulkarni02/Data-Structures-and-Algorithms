#include<bits/stdc++.h>
using namespace std;

#include "BinaryTreeNode.h"

vector<int>* rootToNodePath(BinaryTreeNode<int>* root, int data){
  if(root==NULL){
    return NULL;
  }
  if(root->data==data){
    vector<int>* output = new vector<int>();
    output->push_back(root->data);
    return output;
  }

  vector<int>* leftOutput = rootToNodePath(root->left,data);
  if(leftOutput!=NULL){
    leftOutput->push_back(root->data);
    return leftOutput;
  }
  vector<int>* rightOutput = rootToNodePath(root->right,data);
  if(rightOutput!=NULL){
    rightOutput->push_back(root->data);
    return rightOutput;
  }
  return NULL;
}


BinaryTreeNode<int> *takeInput()
{
  int rootdata;
  cout << "Enter root data: ";
  cin >> rootdata;
  if (rootdata == -1)
  {
    return NULL;
  }
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
  queue<BinaryTreeNode<int> *> pendingNode;
  pendingNode.push(root);
  while (!pendingNode.empty())
  {
    BinaryTreeNode<int> *front = pendingNode.front();
    pendingNode.pop();
    int left;
    cout << "Enter left child of " << front->data << ": ";
    cin >> left;
    if (left != -1)
    {
      BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(left);
      pendingNode.push(leftChild);
      front->left = leftChild;
    }
    int right;
    cout << "Enter right child of " << front->data << ": ";
    cin >> right;
    if (right != -1)
    {
      BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(right);
      pendingNode.push(rightChild);
      front->right = rightChild;
    }
  }
  return root;
}

int main(){
  BinaryTreeNode<int>* root = takeInput();
  vector<int>* output = rootToNodePath(root,8);
  for(int i=0;i<output->size();i++){
    cout << output->at(i) << ' ';
  } 
  cout << endl;
  delete output;
  delete root;
}