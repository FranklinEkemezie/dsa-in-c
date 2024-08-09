#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * -------------------------------------------
 * Dynamic array data structure header file
 * -------------------------------------------
 */


typedef struct DynamicArray
{
  int *data;      // memory address of the array containing the data
  int capacity;   // the current capacity of the array
  int length;     // the length of the dynamic array
}
DynamicArray;


/**
 * Adjust the dynamic array to fit more elements
 */
void adjust(DynamicArray *d_Arr);


/**
 * Append a value to the end of the dynamic array
 * Takes O(1) or constant time
 */
void append(DynamicArray *d_Arr, int value);


/**
 * Checks whether a dynamic array contains a value
 * @param d_Arr The dynamic array
 * @param value The value to check
 * @return Returns TRUE (1) if the item is found; otherwise return FALSE (0).
 */
int contains(DynamicArray d_Arr, int value);

/**
 * Get the value at a given index.
 * @return The index at the specified index; NULL if not found
 */
int get_at_index(DynamicArray d_Arr, int index);


/**
 * Get the length of the dynamic array
 * Takes O(1) or constant time.
 * 
 * For an array of 'n' items, the index that can be used 
 * is from -n to n - 1 and -ve indexes are counted backwards
 * @return The length of the dynamic array
 */
int get_length(DynamicArray d_Arr);


/**
 * Initialise a dynamic array
 * @return The dynamic array
 */
DynamicArray dynamicArray();


/**
 * Insert a value at the specified index.
 * For an n-sized array, the index must be within the range of
 * -n to n. Inserting at `n` is same as appending.
 * Inserting at a -ve index, say `-k`, it is the same as inserting at
 * `-k + n`
 * 
 * @param d_Arr The dynamic array
 * @param value The value to insert
 * @param index The index to insert the item
 */
void insert(DynamicArray *d_Arr, int value, int index);

/**
 * List the element of a dynamic array
 */
void list(DynamicArray d_Arr);


/**
 * Add a value to the start of a dynamic array
 * Takes O(n) or linear time.
 */
void prepend(DynamicArray *d_Arr, int value);


/**
 * Search for a value in the dynamic array.
 * Takes O(n) or linear time.
 * 
 */
int search(DynamicArray d_Arr, int value);


/**
 * Sort the element in the array in ascending order
 */
int sort_linear(DynamicArray d_Arr);

/**
 * Sort the element in the array in descending order
 */
int sort_linear_r(DynamicArray d_Arr);


/**
 * Get the string representation of an array
 */
void strrep(DynamicArray d_Arr);


#endif