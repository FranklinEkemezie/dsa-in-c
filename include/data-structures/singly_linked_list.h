#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "doubly_linked_list.h"

/**
 * -------------------------------
 * SINGLY LINKED LIST data structure:
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
 */

typedef struct Node_
{
  int data;                // data
  struct Node_ *next;      // pointer to the next node
}
Node_;


typedef struct LinkedList_
{
  Node_ *head;      // The head node
  Node_ *tail;      // The tail node
}
LinkedList_;


/**
 * Initialise a singly linked list data structure
 * Similar to calling the constructor of a class in OOP context
 */
LinkedList_ initLinkedList_();


/**
 * Create a node for a singly linked list
 * @param data The data that the node stores
 * @param next The next node
 * @return     Returns the node created
 */
Node_ *createNode_(int data, Node_ *next);


/**
 * Append a value at the end of the singly linked list
 * Takes constant or O(1) time
 * @param ll_   The linked list
 * @param value The value to append 
 */
void ll_append(LinkedList_ *ll_, int value);


/**
 * Checks whether the singly list contains a given item
 */
int ll_contains(LinkedList_ ll_, int value);


/**
 * Get the value at a particular index.
 * 
 * Takes linear or O(n) time
 * @param ll_   The singly linked list
 * @param index The index of the value to find
 * @return      The value at the given index
 * @throw       Fails if the given index is not within range
 */
int ll_get_at_index(LinkedList_ ll_, int index);


/**
 * Checks whether is with in the range of the singly linked list
 * Allowed index range is: -n <= i < n
 * @return Returns TRUE (1) if index is within range; otherwise FALSE (0)
 */
int ll_index_in_range(LinkedList_ ll_, int index);


/**
 * Insert an item at the given index in the singly linked list
 * 
 */
void ll_insert(LinkedList_ *ll_, int value, int index);

/**
 * Check if the singly linked list is empty
 */
int ll_is_empty(LinkedList_ ll_);


/**
 * List the elements of the singly linked list
 */
void ll_list(LinkedList_ ll_);


/**
 * Prepend an item to the singly linked list.
 * Takes constant or O(1) time
 */
void ll_prepend(LinkedList_ *ll_, int value);


/**
 * Remove the first occurrence of a value from the linked list
 */
void ll_remove(LinkedList_ *ll_, int value);


/**
 * Remove the item at a given index
 */
void ll_remove_at_index(LinkedList_ *ll_, int index);


/**
 * Search a given value and get the index
 * @param ll_   The singly linked list
 * @param value The value to search for
 * @return      Returns the index of first occurrence of the value if found.
 * @throw       Fails if the value is not found
 */
int ll_search(LinkedList_ ll_, int value);


/**
 * The size of the singly linked list.
 * Takes linear or O(n) time
 */
int ll_size(LinkedList_ ll_);

/**
 * The string representation of the singly linked list
 */
void ll_strrep(LinkedList_ ll_);


#endif