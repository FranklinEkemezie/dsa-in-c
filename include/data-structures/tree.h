#ifndef TREE_H
#define TREE_H



/**
 * ------------------------------------------------------------------
 * TREE data structure
 * A tree is a non-linear abstract data type with a hierarchy-based
 * structure. It consists of nodes like those in linked list
 * (where the data is stored) that are connected via links. The single
 * elements (or nodes) can have multiple 'next' elements/nodes, allowing
 * the data structure to branch out in various directions.
 * The most common tree data structure is the binary tree.
 * - Binary Tree: In this, each node has up to two children: the left and
 * right nodes. Other more complex tree type like: Binary Search Tree (BST)
 * and AVL tree follow similar structure.
 * 
 * In this implementation, we will focus on Binary Search Trees (BST)
 * - Binary Search Trees (BST) is a form of the binary tree where every node's 
 * left child has a lower value, and every node's right child has higher value.
 * This allows for faster search, delete and insert operation without the need to
 * shift values in memory.
 * We shall implement the various types of tree trasversal (i.e. going through the
 * items/nodes of a tree one at a time):
 * -> Breadth First Search (BFS) - (Sideways trasveral) Nodes on the same level are 
 * visited first before going to the next level in the tree.
 * -> Depth First Search (DFS) - (Downwards trasversal) Trasveral moves down the tree
 * all the way to the leaf nodes (last nodes with no child nodes), taking one branch
 * after the other which can be done in three ways: pre-order, in-order and post-order
 * 
 */


/**
 * Tree Node structure
 */
typedef struct T_Node
{
    int data;               // data
    struct T_Node *left;    // memory address of the left child node
    struct T_Node *right;   // memory address of the right child node
}
T_Node;



/**
 * Tree structure 
 */
typedef struct Tree
{
    T_Node *root;           // root node
}
Tree;




#endif