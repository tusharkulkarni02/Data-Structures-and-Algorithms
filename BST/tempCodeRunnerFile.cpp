#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;


class BST{
  private:
    BinaryTreeNode<int> *root;
    
    bool hasData(BinaryTreeNode<int> *node, int data){
      if(node==NULL){
        return false;
      }

      if(node->data==data){
        return true;
      }else if(data<node->data){
        return hasData(node->left,data);
      }else{
        return hasData(node->right,data);
      }
    }

    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node,int data){
      if(node==NULL){
        BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
        return newNode;
      }
      if(data==node->data){
        BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
        BinaryTreeNode<int>* temp = node->right;
        node->right = newNode;
        newNode->right = temp;
        return node;
      }

      if(data>node->data){
        node->right = insert(node->right,data);
      }else{
        node->left = insert(node->left,data);
      }
      return node;
    }

    void deleteNode(BinaryTreeNode<int>* node, int data){
      if(root==NULL) return;
      if(node->data==data){
          if(node->left==NULL && node->right==NULL){
          delete node;
          return;
        }
        if(node->left==NULL){
          node = node->right;
          return;
        }
        if(node->right==NULL){
          node=node->left;
          return;
        }
        int min = node->left->data;
        BinaryTreeNode<int>* temp = node;
        BinaryTreeNode<int>* minimum = node;
        while(temp->left!=NULL){
          if(temp->data<minimum->data){
            minimum = temp;
            min = temp->data;
          }
        }
        node->data = min;
        if(temp->right!=NULL){
          temp->data = temp->right->data;
          delete temp->right;
        }else{
          delete temp;
        }
        return;
      }else{
        if(data>node->data){
          deleteNode(node->right,data);
        }else{
          deleteNode(node->left,data);
        }
      }
      return;
    }
  public:
    BST(){
      root==NULL;
    }
    ~BST(){
      delete root;
    }
    BinaryTreeNode<int>* insert(int data){
      return insert(root,data);
    }

    void deleteNode(int data){
        deleteNode(root,data);
    } 

  
    bool hasData(int data){
      return hasData(root,data);
    }
};