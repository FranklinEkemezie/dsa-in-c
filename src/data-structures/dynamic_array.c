#include <stdio.h>
#include <stdlib.h>

#include "../../include/data-structures/dynamic_array.h"


/**
 * The initial capacity of the dynamic array
 */
const int INITIAL_D_ARR_CAPACITY = 4;


DynamicArray initDynamicArray()
{
  DynamicArray *d_Arr = malloc(sizeof(DynamicArray));

  // An array of integer stored somewhere in memory
  int *data     = malloc(INITIAL_D_ARR_CAPACITY * sizeof(int));

  d_Arr->data     = data;
  d_Arr->capacity = 4;
  d_Arr->length   = 0;

  return *d_Arr;
}


void freeDynamicArray(DynamicArray *d_Arr)
{
  while (!d_Arr_is_empty(*d_Arr))
  {
    d_Arr_remove_at_index(d_Arr, 0);
  }

  // Free the 'data' variable
  free(d_Arr->data);

  // Free the dynamic array itself
  free(d_Arr);
}


void d_Arr_adjust(DynamicArray *d_Arr)
{
  int *updated_data = realloc(d_Arr->data, d_Arr->capacity * 2 * sizeof(int));
  if (updated_data == NULL)
  {
    fprintf(stderr, "Could not adjust dynamic array: Memory failed to be reallocated\n");
    exit(EXIT_FAILURE);
  }
  
  d_Arr->data = updated_data;
  d_Arr->capacity *= 2;
}


void d_Arr_append(DynamicArray *d_Arr, int value)
{
  // Check if max. capacity is reached
  if (d_Arr->length >= d_Arr->capacity)
    d_Arr_adjust(d_Arr);

  // Update the array
  d_Arr->data[d_Arr->length] = value;
  d_Arr->length++;
}


void d_Arr_append_values(DynamicArray *d_Arr, int values[], int length)
{
  for (int i = 0; i < length; i++)
  {
    d_Arr_append(d_Arr, values[i]);
  } 
}


int d_Arr_contains(DynamicArray d_Arr, int value)
{
  for (int i = 0; i < d_Arr.length; i++)
    if(d_Arr.data[i] == value) return 1;

  return 0;
}


int d_Arr_get_at_index(DynamicArray d_Arr, int index)
{
  if(d_Arr_index_in_range(d_Arr, index))
  {
    fprintf(stderr, "Indexing range is exceeded. The index %i cannot be retrieved\n", index);
    exit(EXIT_FAILURE);
  }

  if (index < 0) index += d_Arr.length;

  return d_Arr.data[index];
}


int d_Arr_get_length(DynamicArray d_Arr)
{
  return d_Arr.length;
}


int d_Arr_index_in_range(DynamicArray d_Arr, int index)
{
  return index >= (0 - d_Arr.length) || index < d_Arr.length;
}


void d_Arr_insert(DynamicArray *d_Arr, int value, int index)
{
  // Check if the index is within range
  if (d_Arr_index_in_range(*d_Arr, index))
  {
    fprintf(stderr, "Index out of range: Cannot insert at index at %i", index);
    exit(EXIT_FAILURE);
  }

  // For -ve index
  if(index < 0) index += d_Arr->length;

  // Check if array is at max. capacity
  if(d_Arr->length == d_Arr->capacity)
    d_Arr_adjust(d_Arr);

  // Shift the element one index forward until the required index
  int position = d_Arr->length;
  while (position >= index)
  {
    d_Arr->data[position + 1] = d_Arr->data[position];
    position--;
  }
  d_Arr->data[index] = value;

  d_Arr->length++;
  
}


int d_Arr_is_empty(DynamicArray d_Arr)
{
  return d_Arr.length == 0 ? 1 : 0;
}


void d_Arr_list(DynamicArray d_Arr)
{
  printf("[");
  for (int i = 0; i < d_Arr.length; i++)
  {
    printf("%i", d_Arr.data[i]);
    if (i != d_Arr.length - 1) printf(", ");
  }
  printf("]\n");
}


void d_Arr_prepend(DynamicArray *d_Arr, int value)
{
  // Check if max. capacity is reached
  if(d_Arr->length == d_Arr->capacity)
    d_Arr_adjust(d_Arr);

  // Shift the element by one index to the beginning of the array
  int current_index = d_Arr->length; // start at the last element
  while (current_index >= 0)
  {
    d_Arr->data[current_index + 1] = d_Arr->data[current_index];
    current_index--;
  }
  d_Arr->data[0] = value;

  d_Arr->length++;
}


void d_Arr_prepend_values(DynamicArray *d_Arr, int values[], int length)
{
  for (int i = 0; i < length; i++)
  {
    d_Arr_prepend(d_Arr, values[i]);
  }
}


int d_Arr_search(DynamicArray d_Arr, int value)
{
  for (int i = 0; i < d_Arr.length; i++)
    if (d_Arr.data[i] == value) return i;

  fprintf(stderr, "Value (%i) not found not found in array", value);
  exit(EXIT_FAILURE);
}


void d_Arr_strrep(DynamicArray d_Arr)
{
  printf("<DynamicArray>[%i] ", d_Arr_get_length(d_Arr));
  d_Arr_list(d_Arr);
}

void d_Arr_remove(DynamicArray *d_Arr, int value)
{
  if(!d_Arr_contains(*d_Arr, value))
  {
    fprintf(stderr, "Value %i to remove not found in the array", value);
    exit(EXIT_FAILURE);
  }
  d_Arr_remove_at_index(d_Arr, d_Arr_search(*d_Arr, value));
}


void d_Arr_remove_at_index(DynamicArray *d_Arr, int index)
{
  if(!d_Arr_index_in_range(*d_Arr, index))
  {
    fprintf(stderr, "Index of value (%i) to remove is out of range", index);
    exit(EXIT_FAILURE);  
  }

  // For -ve index
  if (index < 0) index += d_Arr->length;

  for (int i = index, len = d_Arr_get_length(*d_Arr); i < len; i++)
  {
    d_Arr->data[i] = d_Arr->data[i + 1];
  }

  // Decrease the legth
  d_Arr->length--;
}


void d_Arr_replace(DynamicArray *d_Arr, int value, int new_value)
{
  if(!d_Arr_contains(*d_Arr, value)) {
    fprintf(stderr, "Value %i not found in the array", value);
    exit(EXIT_FAILURE);
  }

  d_Arr_replace_at_index(d_Arr, d_Arr_search(*d_Arr, value), new_value);
}

void d_Arr_replace_at_index(DynamicArray *d_Arr, int index, int new_value)
{
  // Check if the index is within range
  if(d_Arr_index_in_range(*d_Arr, index))
  {
    fprintf(stderr, "Index out of range: Cannot insert at index at %i", index);
    exit(EXIT_FAILURE);
  }

  // For -ve index
  if (index < 0) index += d_Arr->length;

  // Replace element
  d_Arr->data[index] = new_value;
}