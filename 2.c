//PROGRAM TO RECONSTRUCT BST AFTER ROTATION SINCE ORIGINAL ONE IS UNBALANCED
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}

// A utility function to get the height of the tree
int height(struct Node *x1)
{
    if (x1 == NULL)
        return 0;
    return x1->height;
}

//to make a new node in order to make left,right keys
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}

// right rotate subtree rooted with y
struct Node *rotateright(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    //  rotation
    x->right = y;
    y->left = T2;

    // updating value of heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

// left rotate subtree rooted with x
struct Node *rotateleft(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // rotation
    y->left = x;
    x->right = T2;

    //  Update value of heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int BALANCED(struct Node *x1)
{
    if (x1 == NULL)
        return 0;
    return height(x1->left) - height(x1->right);//height of left subtree-height of right subtree
}

// Recursive function to insert a node in the subtree
struct Node* insert(struct Node* node, int key)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else {
            if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    }
    /* 2. Update height*/
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor  */
    int balance = BALANCED(node);

    // If this node becomes unbalanced,

    /*
    4 cases arises
*/
    // LL CASE
    if (balance > 1 && key < node->left->key)

        return rotateright(node);

    // LR CASE
    if (balance > 1 && key > node->left->key)
    {
        node->left =  rotateleft(node->left);
        return rotateright(node);
    }

    //RR CASE
    if (balance < -1 && key > node->right->key)
        return rotateleft(node);

    // RL CASE
    if (balance < -1 && key < node->right->key)
    {
        node->right = rotateright(node->right);
        return rotateleft(node);

    }
    return node;
}

// function to print pre-order traversal of the tree.
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);

    }
}
int main()
{
  struct Node *root = NULL;

  /* Construction of tree*/
  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 3);
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 6);

  printf("RECONSTRUCTION OF BST AFTER ROTATON IS : \n");
  preOrder(root);
  return 0;
}

