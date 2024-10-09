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
 * Operations performed on a tree data structure include: insertion, deletion, trasversal,
 * searching, rotation, finding the min./max. value, finding the height or depth of 
 * the tree, finding the ancestors or descendants of a tree node, checking for balance,
 * merging tree and so on. We will however, take up some of the common ones for now.
 * We shall implement the various types of tree trasversal (i.e. going through the
 * items/nodes of a tree one at a time):
 * -> Breadth First Search (BFS) - (Sideways trasveral) Nodes on the same level are 
 * visited first before going to the next level in the tree.
 * -> Depth First Search (DFS) - (Downwards trasversal) Trasveral moves down the tree
 * all the way to the leaf nodes (last nodes with no child nodes), taking one branch
 * after the other which can be done in three ways: pre-order, in-order and post-order.
 * 
 */


/**
 * Tree Node structure
 */
typedef struct Tr_Node
{
    int data;               // data
    struct Tr_Node *left;    // memory address of the left child node
    struct Tr_Node *right;   // memory address of the right child node
}
Tr_Node;



/**
 * Tree structure 
 */
typedef struct Tree
{
    Tr_Node *root;           // root node
}
Tree;


/**
 * Initialise a Tree data structure
 * Similar to calling the constructor of a class in OOP
 */
Tree createTree();


/**
 * Free a Tree in memory
 */
void freeTree(Tree *t);


/**
 * Create a node for a tree data structure
 */
Tr_Node *createTr_Node(int data, Tr_Node *left, Tr_Node *right);


/**
 * Get the minimum value in a tree
 */
int tree_get_min_val(Tree t);


/**
 * Get the depth of the tree
 */
int tree_get_node_depth(Tr_Node tr_n, int value);


/**
 * Insert a value
 */
void tree_insert(Tree *t, int value);


/**
 * Check if the tree is empty
 */
int tree_is_empty(Tree t);


/**
 * Print the elements of a tree using
 * Depth First Search (DFS) algorithm
 */
void tree_print_dfs(Tree t);


/**
 * Print the elements of a tree using 
 * Breadth First Search (BFS) algorithm
 */
void tree_print_bfs(Tree t);


/**
 * Remove an element from the tree
 */
void tree_remove(Tree t, int value);


#endif