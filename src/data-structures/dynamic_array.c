#include <stdio.h>
#include <stdlib.h>

#include "../../include/data-structures/dynamic_array.h"


/**
 * The initial capacity of the array
 */
const int INTIAL_ARR_CAPACITY = 4;


DynamicArray initDynamicArray()
{
  DynamicArray d_Arr;

  // An array of integer stored somewhere in memory
  int *data = malloc(INTIAL_ARR_CAPACITY * sizeof(int));

  d_Arr.data = data;
  d_Arr.capacity = INTIAL_ARR_CAPACITY;
  d_Arr.length = 0;

  return d_Arr;
}


void d_Arr_adjust(DynamicArray *d_Arr)
{
  int *new_data = realloc(d_Arr->data, d_Arr->capacity * 2 * sizeof(int));
  if (new_data == NULL)
  {
    fprintf(stderr, "Could not adjust dynamic array: Memory failed to be reallocated\n");
    exit(EXIT_FAILURE);
  }

  d_Arr->data = new_data;
  d_Arr->capacity *= 2;
}


void d_Arr_append(DynamicArray *d_Arr, int value)
{
  // Check if max. capacity is reached
  if (d_Arr->length == d_Arr->capacity)
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
    if(d_Arr.data[i] == i) return 1;

  return 0;
}


int d_Arr_get_at_index(DynamicArray d_Arr, int index)
{
  if(index < (0 - d_Arr.length) || index > d_Arr.length - 1)
  {
    fprintf(stderr, "Indexing range is exceeded. The index %i cannot be retrieved\n", index);
    exit(EXIT_FAILURE);
  }

  if(index < 0) index += d_Arr.length;

  return d_Arr.data[index];
}


int d_Arr_get_length(DynamicArray d_Arr)
{
  return d_Arr.length;
}


void d_Arr_insert(DynamicArray *d_Arr, int value, int index)
{
  // Check if the index is within range
  if(index < (0 - d_Arr->length) || index > d_Arr->length)
  {
    fprintf(stderr, "Index out range: Cannot insert at index at %i", index);
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


void d_Arr_list(DynamicArray d_Arr)
{
  printf("[");
  for (int i = 0; i < d_Arr.length; i++)
  {
    printf("%i", d_Arr.data[i]);
    if (i != d_Arr.length - 1) printf(", ", d_Arr.data[i]);
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


  fprintf(stderr, "Value not found");
  exit(EXIT_FAILURE);
}


void d_Arr_strrep(DynamicArray d_Arr)
{
  printf("<DynamicArray>[%i] ", d_Arr_get_length(d_Arr));
  d_Arr_list(d_Arr);
}