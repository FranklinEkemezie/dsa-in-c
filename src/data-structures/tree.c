#include <stdio.h>
#include <stdlib.h>

#include "../../include/data-structures/tree.h"


Tree createTree()
{
    Tree *t = malloc(sizeof(Tree));

    Tr_Node *tr_n = NULL;

    t->root = tr_n;

    return *t;
}


void freeTree(Tree *t)
{

}


Tr_Node *createTr_Node(int data, Tr_Node *left, Tr_Node *right)
{
    Tr_Node *tr_n = malloc(sizeof(Tr_Node));

    tr_n->data = data;
    tr_n->left = left;
    tr_n->right = right;

    return tr_n;
}


int tree_get_min_val(Tree t)
{
    if (tree_is_empty(t))
    {
        fprintf(stderr, "Tree is empty");
        exit(EXIT_FAILURE);
    }

    Tree t_ = createTree();     // next tree
    t_.root = t.root->left;     // with the smaller child as the root

    // Check from here if the current tree root has a smaller next child:
    // If it does have, move on to it, else the current node is the smallest

    return tree_is_empty(t_) ? t.root->data : tree_get_min_val(t_);
}


int tree_get_node_depth(Tr_Node tr_n, int value)
{

}


void tree_insert(Tree *t, int value)
{
    // The node holding the value to insert
    Tr_Node *tr_n_ = createTr_Node(value, NULL, NULL);

    if (tree_is_empty(*t))
    {
        t->root = tr_n_;
        return;
    }

    // Traverse through the 'appropriate' child nodes of the tree
    // until you reach a leaf node or an incomplete node.
    // By 'appropriate', larger values go the right, smaller ones
    // go to the left.
    // The parent node of the current node is kept track of.
    Tr_Node *parent = t->root, *curr = t->root;
    while (curr != NULL)
    {
        if (value == curr->data)
        {
            fprintf(stderr, "Tree insertion failed: Value must be unique");
            exit(EXIT_FAILURE);
        }
        parent = curr;
        curr = value > curr->data ? curr->right : curr->left;
    }

    if (value > parent->data)
        parent->right = tr_n_;
    else
        parent->left = tr_n_;

    return;
}


int tree_is_empty(Tree t)
{
    return t.root == NULL;
}


void tree_print_dfs(Tree t)
{
    if (tree_is_empty(t)) return;

    printf("%i\n", t.root->data);

    // Recursively reduce the tree
    Tree t_ = createTree();

    // Go to the left branch
    t_.root = t.root->left;
    tree_print_dfs(t_);

    // Go to the right branch
    t_.root = t.root->right;
    tree_print_dfs(t_);
}


void tree_print_bfs(Tree t)
{
    // 1. Start at the root node and add it to a queue

    // 2. While queue is not empty, dequeue a node and visit it

    // 3. Enqueue all of its children (if any) into the queue

    // 4. Repeat steps 2 and 3 until the queue is empty

}


void tree_remove(Tree t, int value)
{
    Tr_Node *curr = t.root, *parent = t.root;

    while (curr != NULL)
    {
        parent = curr;
        curr = value > curr->data ? curr->right : curr->left;
    }

    if (value > parent->data)
    {
        parent->right = curr->left;
    }
}