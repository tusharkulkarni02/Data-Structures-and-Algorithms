#include<bits/stdc++.h>
using namespace std;
#include"BinaryTreeNode.h"

bool search(BinaryTreeNode<int> * root,int x){
  if(root==NULL){
    return false;
  }
  if(root->left==nullptr && root->right==nullptr && root->data!=x){
    return false;
  }
  if(root->data==x){
    return true;
  }else if(root->data<x){
    return search(root->right,x);
  }else{
    return search(root->left,x);
  }
  return true;
}