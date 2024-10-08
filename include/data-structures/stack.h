#ifndef STACK_H
#define STACK_H

#include "singly_linked_list.h"

/**
 * -------------------------------------
 * STACK Data Structure
 * 
 * Stack is a linear data structure that follows the
 * LIFO (Last-In-First-Out) principle.
 * That is, only insertion and deletion operation is allowed
 * from one end of the stack, i.e. the top.
 * 
 * The size of a stack data structure can be:
 * - Static  - using the usual data array type with fixed size
 * - Dynamic - implemented using either a dynamic array 
 * (we've implemented before) or even a linked list
 * 
 * The structure of the memory allocation of a queue can be:
 * - Contiguous     - implemented using an array
 * - Non-contiguous - using a linked list.
 * 
 * In this example, we are implementing:
 * - Static and non-contiguous stack    - using a simply linked list
 * - Dynamic and contiguous stack       - using a dynamic array
 */


/**
 * Static and Non-contiguous stack
 */
typedef struct Stack
{
    // Memory address of the linked list storing
    // the data of the stack
    LinkedList_ *data;

    // Size of the stack
    int size;
}
Stack;


/**
 * Initialise a Stack data structure.
 * Similar to calling the constructor of a class in OOP
 */
Stack createStack(int size);


/**
 * Free a Stack memory after use
 * 
 */
void freeStack(Stack *s);


/**
 * Get the length of the stack
 */
int stack_get_length(Stack s);

/**
 * Get the size of the stack
 */
int stack_get_size(Stack s);


/**
 * Check whether or not a stack is empty
 */
int stack_is_empty(Stack s);


/**
 * Check whether stack is full
 */
int stack_is_full(Stack s);



/**
 * List the elements of a stack
 */
void stack_list(Stack s);


/**
 * Get the top element of the stack without removing
 */
int stack_peek(Stack s);


/**
 * Add an element to the top of the stack
 */

void stack_push(Stack *s, int value);


/**
 * Remove the element at the top of the stack and returns it
 */
int stack_pop(Stack *s);


/**
 * The string representation of a stack
 */
void stack_strrep(Stack s);



#endif