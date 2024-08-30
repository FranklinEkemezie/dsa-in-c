#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H


/**
 * -------------------------------------------
 * DYNAMIC ARRAY data structure header file
 * 
 * Dynamic array as opposed to a static array is flexible
 * and can adjust internally to fit a given number of items.
 * Key operations:
 * -> insert  - append, prepend and insert at a given index
 * -> search  - if it contains a value; search and return the index
 * -> delete  - remove first, or last item, remove item of given index
 * -> sort    - implemented in the sorting libraries (https://www.me.com)   
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
 * Initialise a Dynamic Array.
 * Similar to calling the constructor of a class in OOP context
 * 
 * @return The dynamic array
 */
DynamicArray initDynamicArray();


/**
 * Free the dynamic array in memory
 */
void freeDynamicArray(DynamicArray *d_Arr);


/**
 * Adjust the dynamic array to fit more elements
 */
void d_Arr_adjust(DynamicArray *d_Arr);


/**
 * Append a value to the end of the dynamic array
 * Takes O(1) or constant time
 */
void d_Arr_append(DynamicArray *d_Arr, int value);


/**
 * Append an array of values successively to the start of a dynamic array
 * @param d_Arr     The dynamic array
 * @param values[]  The array of values
 * @param length    The length of array
 */
void d_Arr_append_values(DynamicArray *d_Arr, int values[], int length);


/**
 * Checks whether a dynamic array contains a value
 * @param d_Arr The dynamic array
 * @param value The value to check
 * @return Returns TRUE (1) if the item is found; otherwise return FALSE (0).
 */
int d_Arr_contains(DynamicArray d_Arr, int value);

/**
 * Get the value at a given index.
 * Takes O(1) or constant time.
 * 
 * For an array of 'n' items, the index that can be used 
 * is from -n to n - 1 and -ve indexes are counted backwards

 * @return The index at the specified index; NULL if not found
 */
int d_Arr_get_at_index(DynamicArray d_Arr, int index);


/**
 * Get the length of the dynamic array
 * Takes O(1) or constant time.
 * 
 * @return The length of the dynamic array
 */
int d_Arr_get_length(DynamicArray d_Arr);


/**
 * Checks whether the index is within the range of the dynamic array
 * @param d_Arr The dynamic array
 * @param index The index
 * 
 * @return Returns TRUE (1) if the index is within range, FALSE (0) otherwise
 */
int d_Arr_index_in_range(DynamicArray d_Arr, int index);


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
void d_Arr_insert(DynamicArray *d_Arr, int value, int index);


/**
 * Checks whether the dynamic array is empty
 * @return Returns `1` if the dynamic array is empty; otherwise `0`.
 */
int d_Arr_is_empty(DynamicArray d_Arr);


/**
 * List the element of a dynamic array
 */
void d_Arr_list(DynamicArray d_Arr);


/**
 * Add a value to the start of a dynamic array
 * Takes O(n) or linear time.
 */
void d_Arr_prepend(DynamicArray *d_Arr, int value);


/**
 * Add an array of values successively to the a dynamic array
 * @param d_Arr     The dynamic array
 * @param values[]  The array of values
 * @param length    The length of array
 */
void d_Arr_prepend_values(DynamicArray *d_Arr, int values[], int length);


/**
 * Search for a value in the dynamic array and return the
 * index of the first occurrence
 * Takes O(n) or linear time.
 * 
 * @return The index of the search value if found.
 * @throw Fails if value is not found in the dynamic array.
 */
int d_Arr_search(DynamicArray d_Arr, int value);


/**
 * Get the string representation of the dynamic array
 */
void d_Arr_strrep(DynamicArray d_Arr);

/**
 * Remove the item from the array
 * @param d_Arr The dynamic array
 * @param value The value 
 * @throw Fails if the value to remove is not in the array
 */
void d_Arr_remove(DynamicArray *d_Arr, int value);


/**
 * Remove an item at the specified index
 * @param d_Arr The dynamic array
 * @param index The index of the value to remove
 * @throw Fails if the index is out of range.
 */
void d_Arr_remove_at_index(DynamicArray *d_Arr, int index);


/**
 * Replace the specified value with a new value
 * @param d_Arr     The dynamic array
 * @param index     The value to replace
 * @param new_value The new value
 */
void d_Arr_replace(DynamicArray *d_Arr, int value, int new_value);


/**
 * Replace the value at a given index
 * @param d_Arr     The dynamic array
 * @param index     The index of the value to replace
 * @param new_value The new value
 */
void d_Arr_replace_at_index(DynamicArray *d_Arr, int index, int new_value);

#endif