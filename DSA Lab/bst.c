#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} BST_NODE;

int compare(int a, int b)
{
    int flag;
    if (a < b)
    {
        flag = -1;
    }
    else if (a > b)
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }

    return flag;
}

BST_NODE *create_node(int data)
{
    BST_NODE *newNode;

    newNode = (BST_NODE *)malloc(sizeof(BST_NODE));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

BST_NODE *insert_node(BST_NODE *root, int data)
{
    if (root == NULL)
    {
        return create_node(data);
    }

    if (data < root->data)
    {
        root->left = insert_node(root->left, data);
    }

    else if (data > root->data)
    {
        root->right = insert_node(root->right, data);
    }

    return root;
}

void inorder_traversal(BST_NODE *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);

        inorder_traversal(root->right);
    }
}

void preorder_traversal(BST_NODE *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);

        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

int main()
{
    int n, i, data;
    BST_NODE *root;

    root = NULL;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &data);
        root = insert_node(root, data);
    }

    inorder_traversal(root);
    printf("\n");

    preorder_traversal(root);
    printf("\n");

    return 0;
}