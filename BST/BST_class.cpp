#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;


/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/

class BST {
   BinaryTreeNode<int>* root;

   bool search(BinaryTreeNode<int>* node,int data){
       if(node==NULL) return false;

       if(node->data==data){
           return true;
       }else if(data<node->data){
           return search(node->left,data);
       }else{
           return search(node->right,data);
       }
   }

    BinaryTreeNode<int>* remove(BinaryTreeNode<int>* node, int data){
        if(node==NULL){
            return NULL;
        } 
        
        if(node->data<data){
                node->right = remove(node->right, data);
                return node;
        }else if(node->data>data){
                node->left = remove(node->left, data);
                return node;
        }else{
            if(node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }
            else if(node->left==NULL){
                BinaryTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if(node->right==NULL){
                BinaryTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }else{
                BinaryTreeNode<int>* minNode = node->right;
                while(minNode->left!=NULL) {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = remove(node->right,rightMin);
                return node;
            }
        }
    }

    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node,int data){
      if(node==NULL){
        BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
        return newNode;
      }

      if(data>node->data){
        node->right = insert(node->right,data);
      }else{
        node->left = insert(node->left,data);
      }
      return node;
    }

    void print(BinaryTreeNode<int>* node){
        if(node==NULL){
            return;
        }
        cout << node->data << ":";
        if(node->left!=NULL){
            cout << "L:" << node->left->data << ",";
        }
        if(node->right!=NULL){
            cout << "R:" << node->right->data;
        }
        cout << endl;
        print(node->left);
        print(node->right);
    }

   public:
    BST() { 
        root=NULL;
    }
    ~BST(){
        delete root;
    }
	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        root = remove(root,data);
    }

    void print() { 
        print(root);
    }

    void insert(int data) { 
        root = insert(root,data);
    }

    bool search(int data) {
		return search(root,data);
    }
};