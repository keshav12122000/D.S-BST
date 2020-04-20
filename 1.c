#include <stdio.h>
#include<stdlib.h>
//for bool expression
#include<stdbool.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Returns true if binary tree
with root as root is height-balanced */
/* returns maximum of two integers */
int max(int a, int b)
{
    return (a >= b) ? a : b;
}

/* The function Compute the "height"
of a tree. Height is the number of
nodes along the longest path from
the root node down to the farthest leaf node.*/
int height(struct node* node)
{
    /* base case tree is empty */
    if (node == NULL)
        return 0;

    /* If tree is not empty then
    height = 1 + max of left
        height and right heights */
    return 1 + max(height(node->left),
                   height(node->right));
}

bool Balanced(struct node* root)
{
    int z;
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */

    /* If tree is empty then return true */
    if (root == NULL)
        return 1;

    /* Get the height of left and right sub trees */
    lh = height(root->left);
    rh = height(root->right);

    if ((lh - rh) <= 1 && Balanced(root->left) && Balanced(root->right))
        return 1;
z=lh-rh;
printf("BALANCED FACTOR IS : %d\n",z);
    /* If we reach here then
    tree is not height-balanced */
    return 0;
}


struct node* newNode(int data)
{
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

// Driver code
int main()
{
    //making a tree
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);

   if (Balanced(root))
        printf("Tree is balanced");
    else
        printf("Tree is not balanced");
    return 0;
}









