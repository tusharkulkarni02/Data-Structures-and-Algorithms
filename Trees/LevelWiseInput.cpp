#include <iostream>
#include "TreeNode.h"
#include <queue>

using namespace std;

TreeNode<int> *takleInputLevelWise()
{
  int rootData;
  cout << "Enter root data:";
  cin >> rootData;

  TreeNode<int> *root = new TreeNode<int>(rootData);

  queue<TreeNode<int> *> pendingNode;
  pendingNode.push(root);

  while (!pendingNode.empty())
  {
    TreeNode<int> *front = pendingNode.front();
    pendingNode.pop();
    int numchild;
    cout << "Enter No of children of " << front->data << endl;
    cin >> numchild;

    for (int i = 0; i < numchild; i++)
    {
      int childData;
      cout << "Enter " << i << "th child data: ";
      cin >> childData;

      TreeNode<int> *child = new TreeNode<int>(childData);
      front->children.push_back(child);
      pendingNode.push(child);
    }
  }
  return root;
}

void printTreeLevelWise(TreeNode<int> *root)
{
  if (root == NULL)
    return;

  queue<TreeNode<int> *> printNode;
  printNode.push(root);

  while (!printNode.empty())
  {
    TreeNode<int> *front = printNode.front();
    cout << front->data << ":";
    printNode.pop();
    int n = front->children.size();
    for (int i = 0; i < n; i++)
    {
      cout << front->children[i]->data << ',';
      printNode.push(front->children[i]);
    }
    cout << endl;
  }
}

int main()
{
  TreeNode<int> *root = takleInputLevelWise();
  printTreeLevelWise(root);
}