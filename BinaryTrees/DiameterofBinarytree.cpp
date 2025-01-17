#include <bits/stdc++.h>
#include "BinaryTreeNode.h"

using namespace std;

Pair<int, int> DiameterOfBinaryTree(BinaryTreeNode<int> *root)
{
  if (root == nullptr)
  {
    return {0, 0};
  }

  pair<int, int> leftAns = DiameterOfBinaryTree(root->left);
  pair<int, int> rightAns = DiameterOfBinaryTree(root->right);
  int lh = leftAns.first;
  int ld = leftAns.second;
  int rh = rightAns.first;
  int rd = rightAns.second;

  int height = 1 + max(lh, rh);
  int diameter = max(lh + rh, max(rd, lh));
  pair<int,int> p;
  p.first = height;
  p.second = diameter;

  return p;
}