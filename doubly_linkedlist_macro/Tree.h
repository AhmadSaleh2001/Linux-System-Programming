typedef struct treeNode
{
  void *data;
  struct treeNode *left;
  struct treeNode *right;
} TreeNode;

typedef struct bst
{
  TreeNode *root;

  int (*compareFn)(void *data1, void *data2);
  void (*printFn)(void *data);
} BST;

BST *getBST();
TreeNode *createNode(void *data);
TreeNode *addToBSTRec(BST *t, TreeNode *node, void *data);

void registerCompareFunction(BST *t, int (*compareFn)(void *data1, void *data2));
void registerPrintFunction(BST *t, void (*printFn)(void *data));
void addToBST(BST *t, void *data);
void preorder(BST *t);
void preorder2(BST *t, TreeNode *node);