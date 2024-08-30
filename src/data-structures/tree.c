#include <stdio.h>
#include <stdlib.h>

#include "../../include/data-structures/tree.h"


Tree createTree()
{
    Tree *t = malloc(sizeof(Tree));

    t->root = NULL;

    return *t;
}


void freeTree(Tree *t)
{

}


T_Node *createT_Node(int data, T_Node *left, T_Node *right)
{
    T_Node *t_n = malloc(sizeof(T_Node));

    t_n->data = data;
    t_n->left = left;
    t_n->right = right;

    return t_n;
}


