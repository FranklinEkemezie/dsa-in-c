#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

/**
 * ----------------------------------------
 * DOUBLY LINKED LIST data structure:
 * 
 * Linked list is a linear data structure that includes a series
 * of connected nodes.
 * The node stores the data and the address of the next node.
 * However, in memory, these data are not stored in continguous memory
 * Singly linked list allow traversal in only one direction usually in the
 * forward direction.
 * Doubly linked list allow traversal in both (forward 
 * and backward) directions
 * 
 * 
 */

typedef struct _Node_
{
  int data;                 // The data
  struct _Node_ *next;      // The next node
  struct _Node_ *prev;      // The previous node
}
Node;

typedef struct _LinkedList_
{
  struct Node *head;      // The node at the head
  struct Node *tail;      // The node at the tail
}
__LinkedList;


#endif