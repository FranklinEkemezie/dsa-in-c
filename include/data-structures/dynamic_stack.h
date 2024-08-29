#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include "dynamic_array.h"

/**
 * -------------------------------------
 * STACK data structure
 * DynamicStack is a linear data structure that follows the
 * LIFO (Last-In-First-Out) principle.
 * That is, only insertion and deletion operation is allowed
 * from one end of the stack, i.e. the top
 * Implementation of a stack can be:
 * - Static - using the usual array type with fixed size
 * - Dynamic - implemented using either a dynamic array implemented before or a linked list
 * It can also be implemented using memory which is:
 * - Contiguous - using an array
 * - Non-contiguous - using a linked list.
 * 
 * In this example, we are implementing:
 * - static and non-contiguous data type - using linked list
 * - dynamic and contiguous data type - using dynamic array
 */

/**
 * Dynamic and Contiguous stack
 */
typedef struct DynamicStack
{
    // Memory address of the dynamic array
    DynamicArray *data;
}
DynamicStack;


/**
 * Initialise a Dynamic DynamicStack data structure.
 * Similar to calling the constructor of a class in OOP
 */
DynamicStack initDynamicStack();


/**
 * Free a Dynamic DynamicStack in memory
 */
void freeDynamicStack(DynamicStack *d_Stack);


/**
 * Get the length of the dynamic stack
 */
int d_Stack_get_length(DynamicStack s);

/**
 * Get the size of the dynamic stack
 */
int d_Stack_get_size(DynamicStack s);


/**
 * Check whether or not a dynamic stack is empty
 */
int d_Stack_is_empty(DynamicStack s);


/**
 * Check whether dynamic stack is full
 */
int d_Stack_is_full(DynamicStack s);



/**
 * List the elements of a dynamic stack
 */
void d_Stack_list(DynamicStack s);


/**
 * Add an element to the top of the dynamic stack
 */

void d_Stack_push(DynamicStack *s, int value);


/**
 * Remove the element at the top of the dynamic stack
 */
void d_Stack_pop(DynamicStack *s);



#endif