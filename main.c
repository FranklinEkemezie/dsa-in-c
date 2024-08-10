#include <stdio.h>
#include <stdlib.h>

#include "./include/data-structures/dynamic_array.h"
#include "./include/data-structures/set.h"

int main(int argc, char* argv[])
{
  // // Create a new dynamic array
  // DynamicArray d_Arr = initDynamicArray();

  // for (int i = 1; i < argc; i++)
  //

  // d_Arr_strrep(d_Arr);

  // Create a new set
  Set set = initSet();

  // for (int i = 1; i < argc; i++)
  //   set_insert(&set, atoi(argv[i]));

  // set.d_arr->data[0] = 3;
  // set.d_arr->length = 1;


  // set_insert(&set, 3);
  // set_insert(&set, 11);
  // set_insert(&set, 5);
  // set_insert(&set, 9);
  // set_insert(&set, 13);

  // d_Arr_strrep(*(set.d_arr));

  set_strrep(set);


  // printf("Address of dynamic array: %p\n", set.d_arr);
  // printf("Address of set: %p\n", &set);

  // printf("Size of set is: %i\n", set.d_arr->data[0]);

  // set_list(set);


  
}