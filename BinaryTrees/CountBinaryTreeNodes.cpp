#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
using namespace std;

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

void printTreeLevelWise(BinaryTreeNode<int> *root)
{
  if (root == NULL)
  {
    return;
  }
  queue<BinaryTreeNode<int> *> printNode;
  printNode.push(root);
  while (!printNode.empty())
  {
    BinaryTreeNode<int> *front = printNode.front();
    cout << front->data << ':';
    printNode.pop();
    if (front->left != NULL)
    {
      cout << 'L' << front->left->data << ',';
      printNode.push(front->left);
    }
    if (front->right != NULL)
    {
      cout << 'R' << front->right->data;
      printNode.push(front->right);
    }
    cout << endl;
  }
}

int numberOfNodes(BinaryTreeNode<int> *root)
{
  if (root == NULL)
  {
    return 0;
  }

  // return 1 + numberOfNodes(root->left) + numberOfNodes(root->right);
  int ans = 1;
  ans += numberOfNodes(root->left);
  ans += numberOfNodes(root->right);

  return ans;
}

int main()
{
  BinaryTreeNode<int> *root = takeInput();
  cout << endl
       << "NumberOfNodes" << numberOfNodes(root) << endl;
  printTreeLevelWise(root);
  delete root;
}