#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include "dynamic_array.h"

/**
 * -------------------------------------
 * STACK data structure
 * Stack is a linear data structure that follows the
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
 * Initialise a Dynamic Stzck data structure.
 * Similar to calling the constructor of a class in OOP
 */
DynamicStack initDynamicStack();


/**
 * Free a Dynamic Stack in memory
 */
void freeDynamicStack(DynamicStack *d_Stack);


/**
 * Get the length of the dynamic stack
 */
int d_Stack_get_length(DynamicStack d_Stack);


/**
 * Check whether or not a dynamic stack is empty
 */
int d_Stack_is_empty(DynamicStack d_Stack);


/**
 * List the elements of a dynamic stack
 */
void d_Stack_list(DynamicStack d_Stack);


/**
 * Get the element at the top of the dynamic stack without removing it
 */
int d_Stack_peep(DynamicStack d_Stack);


/**
 * Add an element to the top of the dynamic stack
 */
void d_Stack_push(DynamicStack *d_Stack, int value);


/**
 * Remove the element at the top of the dynamic stack and return it
 */
int d_Stack_pop(DynamicStack *d_Stack);


/**
 * The string representation of a dynamic stack
 */
void d_Stack_strrep(DynamicStack d_Stack);


#endif