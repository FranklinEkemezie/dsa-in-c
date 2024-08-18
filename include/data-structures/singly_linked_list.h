#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

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

typedef struct Node
{
  int data;               // The data
  struct Node *next;      // The next node
}
Node;


typedef struct LinkedListSingle
{
  struct Node *head;      // The head node
  struct Node *tail;      // The tail node
}
LinkedListSingle;


/**
 * Initialise a singly linked list data structure
 * Similar to calling the constructor of a class in OOP context
 */
LinkedListSingle initSinglyLinkedList();


/**
 * Create a node for a singly linked list
 * @param data The data that the node stores
 * @param next The next node
 * @return     Returns the node created
 */
Node *createNodeLL_(int data, Node *next);


/**
 * Append a value at the end of the singly linked list
 * Takes constant or O(1) time
 * @param ll_   The linked list
 * @param value The value to append 
 */
void ll_append(LinkedListSingle *ll_, int value);


/**
 * Checks whether the singly list contains a given item
 */
int ll_contains(LinkedListSingle ll_, int value);


/**
 * Get the value at a particular index.
 * 
 * Takes linear or O(n) time
 * @param ll_   The singly linked list
 * @param index The index of the value to find
 * @return      The value at the given index
 * @throw Fails if the given index is not within range
 */
int ll_get_at_index(LinkedListSingle ll_, int index);


/**
 * Checks whether is with in the range of the singly linked list
 * Allowed index range is: -n <= i < n
 * @return Returns TRUE (1) if index is within range; otherwise FALSE (0)
 */
int ll_index_in_range(LinkedListSingle ll_, int index);


/**
 * Insert an item at the given index in the singly linked list
 * 
 */
void ll_insert(LinkedListSingle *ll_, int value, int index);

/**
 * Check if the singly linked list is empty
 */
int ll_is_empty(LinkedListSingle ll_);


/**
 * List the elements of the singly linked list
 */
void ll_list(LinkedListSingle ll_);


/**
 * Prepend an item to the singly linked list.
 * Takes constant or O(1) time
 */
void ll_prepend(LinkedListSingle *ll_, int value);


/**
 * Remove the first occurrence of a value from the linked list
 */
void ll_remove(LinkedListSingle *ll_, int value);


/**
 * Remove the item at a given index
 */
void ll_remove_at_index(LinkedListSingle *ll_, int index);


/**
 * Search a given value and get the index
 * @param ll_   The singly linked list
 * @param value The value to search for
 * @return      Returns the index of first occurrence of the value if found.
 * @throw       Fails if the value is not found
 */
int ll_search(LinkedListSingle ll_, int value);


/**
 * The size of the singly linked list.
 * Takes linear or O(n) time
 */
int ll_size(LinkedListSingle ll_);

/**
 * The string representation of the singly linked list
 */
void ll_strrep(LinkedListSingle ll_);


#endif