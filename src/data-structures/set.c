#include <stdio.h>
#include <stdlib.h>

#include "../../include/data-structures/dynamic_array.h"
#include "../../include/data-structures/set.h"


Set initSet()
{
  Set *set = malloc(sizeof(Set));

  // The dynamic array somewhere else in memory
  DynamicArray *d_Arr = malloc(sizeof(DynamicArray));
  *d_Arr = initDynamicArray();

  set->d_arr = d_Arr;

  return *set;
}


void freeSet(Set *set)
{
  while (!set_is_empty(*set))
  {
    d_Arr_remove_at_index(set->d_arr, 0);
  }

  // Free the dynamic array
  free(set->d_arr);

  // Free the set itself
  free(set);
}


void set_adjust(Set *set)
{
  int *new_data = realloc(set->d_arr->data, 2 * set->d_arr->capacity * sizeof(int));
  if (new_data == NULL)
  {
    fprintf(stderr, "Failed to adjust set: Memory failed to be reallocated\n");
  }

  set->d_arr->data = new_data;
  set->d_arr->capacity *= 2;
}

int set_contains(Set set, int value)
{
  return d_Arr_contains(*set.d_arr, value);
}


int set_get_size(Set set)
{
  return d_Arr_get_length(*set.d_arr);
}


void set_insert(Set *set, int value)
{
  if(!set_contains(*set, value))
    d_Arr_append(set->d_arr, value);
}


void set_insert_values(Set *set, int values[], int length)
{
  for (int i = 0; i < length; i++)
    set_insert(set, values[i]);
}


int set_is_empty(Set set)
{
  return set_get_size(set) == 0 ? 1 : 0;
}


void set_list(Set set)
{
  printf("{");
  for (int i = 0; i < set_get_size(set); i++)
  {
    printf("%i", set.d_arr->data[i]);
    if (i != set.d_arr->length - 1) printf(", ");
  }
  printf("}\n");
}


void set_strrep(Set set)
{
  printf("<Set>[%i] ", set_get_size(set));
  set_list(set);
}

void set_remove(Set *set, int value)
{
  if(set_contains(*set, value))
  {
    d_Arr_remove(set->d_arr, value);
  }
  else
  {
    fprintf(stderr, "Value %i not found in set", value);
    exit(EXIT_FAILURE);
  }
}