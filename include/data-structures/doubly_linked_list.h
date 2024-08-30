#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

/**
 * -------------------------------
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
 */

typedef struct _Node_
{
  int data;                 // The data
  struct _Node_ *prev;      // The previous node
  struct _Node_ *next;      // The next node
}
_Node_;


typedef struct _LinkedList_
{
  _Node_ *head;             // The head node
  _Node_ *tail;             // The tail node
}
_LinkedList_;


/**
 * Initialise a doubly linked list data structure
 * Similar to calling the constructor of a class in OOP context
 */
_LinkedList_ create_LinkedList_();


/**
 * Free the doubly linked list
 */
void free_LinkedList_(_LinkedList_ *_ll_);


/**
 * Create a node for a doubly linked list
 * @param data The data that the node stores
 * @param next The next node
 * @return     Returns the node created
 */
_Node_ *create_Node_(int data, _Node_ *prev, _Node_ *next);


/**
 * Append a value at the end of the doubly linked list
 * Takes constant or O(1) time
 * @param _ll_  The linked list
 * @param value The value to append 
 */
void _ll_append(_LinkedList_ *_ll_, int value);


/**
 * Checks whether the doubly list contains a given item
 */
int _ll_contains(_LinkedList_ _ll_, int value);


/**
 * Get the value at a particular index.
 * 
 * Takes linear or O(n) time
 * @param _ll_  The doubly linked list
 * @param index The index of the value to find
 * @return      The value at the given index
 * @throw       Fails if the given index is not within range
 */
int _ll_get_at_index(_LinkedList_ _ll_, int index);


/**
 * Checks whether is with in the range of the doubly linked list
 * Allowed index range is: -n <= i < n
 * @return Returns TRUE (1) if index is within range; otherwise FALSE (0)
 */
int _ll_index_in_range(_LinkedList_ _ll_, int index);


/**
 * Insert an item at the given index in the doubly linked list
 * 
 */
void _ll_insert(_LinkedList_ *_ll_, int value, int index);

/**
 * Check if the doubly linked list is empty
 */
int _ll_is_empty(_LinkedList_ _ll_);


/**
 * List the elements of the doubly linked list
 */
void _ll_list(_LinkedList_ _ll_);


/**
 * Prepend an item to the doubly linked list.
 * Takes constant or O(1) time
 */
void _ll_prepend(_LinkedList_ *_ll_, int value);


/**
 * Remove the first occurrence of a value from the doubly linked list
 */
void _ll_remove(_LinkedList_ *_ll_, int value);


/**
 * Remove the item at a given index
 */
void _ll_remove_at_index(_LinkedList_ *_ll_, int index);


/**
 * Search a given value and get the index
 * @param _ll_  The doubly linked list
 * @param value The value to search for
 * @return      Returns the index of first occurrence of the value if found.
 * @throw       Fails if the value is not found
 */
int _ll_search(_LinkedList_ _ll_, int value);


/**
 * The size of the doubly linked list.
 * Takes linear or O(n) time
 */
int _ll_size(_LinkedList_ _ll_);

/**
 * The string representation of the doubly linked list
 */
void _ll_strrep(_LinkedList_ _ll_);


#endif