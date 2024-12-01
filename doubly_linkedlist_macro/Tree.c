#include <stdlib.h>
#include <stdio.h>
#include "Tree.h"

BST *getBST()
{
  BST *t = calloc(1, sizeof(BST));
  return t;
}

void registerCompareFunction(BST *t, int (*compareFn)(void *data1, void *data2))
{
  t->compareFn = compareFn;
}

void registerPrintFunction(BST *t, void (*printFn)(void *data))
{
  t->printFn = printFn;
}

TreeNode *createNode(void *data)
{
  TreeNode *newNode = malloc(sizeof(TreeNode));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void addToBST(BST *t, void *data)
{
  t->root = addToBSTRec(t, t->root, data);
}

TreeNode *addToBSTRec(BST *t, TreeNode *node, void *data)
{
  if (node == NULL)
  {
    TreeNode *newNode = calloc(1, sizeof(TreeNode));
    newNode->data = data;
    return newNode;
  }
  else if (t->compareFn(node->data, data) > 0)
  {
    node->right = addToBSTRec(t, node->right, data);
  }
  else
  {
    node->left = addToBSTRec(t, node->left, data);
  }
  return node;
}

void preorder(BST *t)
{
  preorder2(t, t->root);
}
void preorder2(BST *t, TreeNode *node)
{
  if (node == NULL)
    return;
  t->printFn(node->data);
  preorder2(t, node->left);
  preorder2(t, node->right);
}