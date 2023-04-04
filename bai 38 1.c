#include <stdio.h>
#include <stdlib.h>

struct Tnode
{
    int id;
    struct Tnode *left;
    struct Tnode *right;
};
typedef struct Tnode treeNode;

treeNode *makeTreeNode(int x, treeNode *parent)
{
    treeNode *temp = (treeNode *)malloc(sizeof(treeNode));
    temp->id = x;
    temp->left = NULL;
    temp->right = NULL;
    if (parent != NULL)
    {
        if (parent->left == NULL)
        {
            parent->left = temp;
        }
        else if (parent->right == NULL)
        {
            parent->right = temp;
        }
        else
        {
            printf("node with label %i can't have any more child", parent->id);
        }
    }
    return temp;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int Depth(treeNode *root)
{
    if (root != NULL)
    {
        return max(Depth(root->left), Depth(root->right)) + 1;
    }
    return 0;
}

int countNode(treeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL || root->right == NULL)
        return 1;
    int count = 0;
    count += countNode(root->left);
    count += countNode(root->right);
    return count;
}

int PreOrder(treeNode *node)
{
    if (node == NULL)
        return 0;
    printf("%i ", node->id);
    PreOrder(node->left);
    PreOrder(node->right);
}

int inOrder(treeNode *node)
{
    if (node == NULL)
        return 0;
    inOrder(node->left);
    printf("%i ", node->id);
    inOrder(node->right);
}

int postOrder(treeNode *node)
{
    if (node == NULL)
        return 0;
    postOrder(node->left);
    postOrder(node->right);
    printf("%i ", node->id);
}

int height(treeNode *root)
{
    if (root != NULL)
    {

        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }
    return 0;
}

int FindLayer(treeNode *root, int layer, int ogHeight, int space)
{
    if (root != NULL)
    {
        if (ogHeight - height(root) == layer)
        {
            printf("%i", root->id);
            for (int i = 0; i < space; i++)
            {
                printf(" ");
            }
            return 0;
        }
        else
        {
            FindLayer(root->left, layer, ogHeight, space);
            FindLayer(root->right, layer, ogHeight, space);
        }
    }
}

int main()
{
    treeNode *root = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node1 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node2 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node3 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node4 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node5 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node6 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node7 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node8 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node9 = (treeNode *)malloc(sizeof(treeNode));
    treeNode *node10 = (treeNode *)malloc(sizeof(treeNode));

    root->id = 0;  // a
    node1->id = 1; // b
    node2->id = 2; // c
    node3->id = 3; // d
    node4->id = 4; // e
    node5->id = 5; // f

    root->right = node2;
    root->left = node1;

    node1->right = node4;
    node1->left = node3;

    node2->left = node5;
    node2->right = NULL;

    node3->right = NULL;
    node3->left = NULL;

    node4->right = NULL;
    node4->left = NULL;

    node5->left = NULL;
    node5->right = NULL;

    int prevSpace = 120;
    int space = height(root) * 2;
    for (int i = 0; i < height(root); i++)
    {
        prevSpace -= i;
        for (int e = 0; e < prevSpace; e++)
        {
            printf(" ");
        }
        FindLayer(root, i, height(root), space);
        space-=2;
        printf("\n");
    }

    printf("%i", countNode(root));
}
