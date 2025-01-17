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

void printInOrder(TreeNode<int> *root)
{
  if (root == NULL)
    return;

  cout << root->data << " ";
  for (int i = 0; i < root->children.size(); i++)
  {
    printInOrder(root->children[i]);
  }
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

void printPostOrder(TreeNode<int> *root)
{
  if (root == NULL)
    return;
  for (int i = 0; i < root->children.size(); i++)
  {
    printPostOrder(root->children[i]);
  }
  cout << root->data << " ";
}

bool isPresent(TreeNode<int> *root, int x)
{
  if (root == NULL)
    return 0;
  if (root->data == x)
  {
    return 1;
  }
  for (int i = 0; i < root->children.size(); i++)
  {
    return isPresent(root->children[i], x);
  }
}

int main()
{
  TreeNode<int> *root = takleInputLevelWise();
  cout << "InOrder Traversal:\n";
  printInOrder(root);
  cout << '\n';
  cout << "LevelOrder Traversal:\n";
  printTreeLevelWise(root);
  cout << "PostOrder Traversal:\n";
  printPostOrder(root);
  cout << "\nenter no you want to find in tree:";
  int n;
  cin >> n;
  if (isPresent(root, n))
  {
    cout << n << " is present";
  }
  else
  {
    cout << n << " is not present";
  }
}