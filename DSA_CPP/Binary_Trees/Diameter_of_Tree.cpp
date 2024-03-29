#include <iostream>
#include <queue>
#include "BTreeNode.h"
using namespace std;

BTreeNode<int> *takeInput()
{
  int rootData;
  cout << "Enter root data :" << endl;
  cin >> rootData;
  if (rootData == -1)
    return NULL;
  BTreeNode<int> *root = new BTreeNode<int>(rootData);
  queue<BTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);
  while (pendingNodes.size() != 0)
  {
    BTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    cout << "Enter left child of :" << front->data << endl;
    int leftChildData;
    cin >> leftChildData;
    if (leftChildData != -1)
    {
      BTreeNode<int> *child = new BTreeNode<int>(leftChildData);
      front->left = child;
      pendingNodes.push(child);
    }
    cout << "Enter right child of :" << front->data << endl;
    int rightChildData;
    cin >> rightChildData;
    if (rightChildData != -1)
    {
      BTreeNode<int> *child = new BTreeNode<int>(rightChildData);
      front->right = child;
      pendingNodes.push(child);
    }
  }
  return root;
}

void print(BTreeNode<int> *root)
{
  if (root == NULL)
    return;
  queue<BTreeNode<int> *> printNodes;
  printNodes.push(root);
  while (printNodes.size() != 0)
  {
    BTreeNode<int> *front = printNodes.front();
    printNodes.pop();
    cout << front->data << ":";
    if (front->left != NULL && front->right != NULL)
    {
      cout << "L:" << front->left->data << ",";
      printNodes.push(front->left);
      cout << "R:" << front->right->data << endl;
      printNodes.push(front->right);
    }
    else
    {
      if (front->left == NULL && front->right == NULL)
      {
        cout << "L:-1,";
        cout << "R:-1" << endl;
      }
      else if (front->left == NULL && front->right != NULL)
      {
        cout << "L:-1,";
        cout << "R:" << front->right->data << endl;
        printNodes.push(front->right);
      }
      else if (front->left != NULL && front->right == NULL)
      {
        cout << "L:" << front->left->data << ",";
        printNodes.push(front->left);
        cout << "R:-1" << endl;
      }
    }
  }
}

int height(BTreeNode<int> *root)
{
  if (root == NULL)
    return 0;
  return 1 + max(height(root->left), height(root->right));
}

int diameter(BTreeNode<int> *root)
{
  if (root == NULL)
    return 0;

  int option1 = height(root->left) + height(root->right);
  int option2 = diameter(root->left);
  int option3 = diameter(root->right);
  return max(option1, (option2, option3));
}

pair<int, int> heightDiameter(BTreeNode<int> *root)
{
  if (root == NULL)
  {
    pair<int, int> p;
    p.first = 0;
    p.second = 0;
    return p;
  }

  pair<int, int> leftAns = heightDiameter(root->left);
  pair<int, int> rightAns = heightDiameter(root->right);
  int ld = leftAns.second;
  int lh = leftAns.first;
  int rd = leftAns.second;
  int rh = leftAns.first;

  int height = 1 + max(lh, rh);
  int diameter = max(lh + rh, max(ld, rd));
  pair<int, int> p;
  p.first = height;
  p.second = diameter;
  return p;
}

int main()
{
  BTreeNode<int> *root = takeInput();
  pair<int, int> p = heightDiameter(root);
  cout << p.second << endl;
  delete root;
}