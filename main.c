#include <stdio.h>

#include "./include/data-structures/dynamic_array.h"

int main(int argc, char* argv[])
{
  // Create a new dynamic array
  DynamicArray d_Arr = init_dynamic_array();

  for (int i = 1; i < argc; i++)
  {
    append(&d_Arr, atoi(argv[i]));
  }

  // for (int i = 1; i < argc; i++)
  // {
  //   prepend(&d_Arr, atoi(argv[i]));
  // }

  // insert(&d_Arr, 63, 1-2);
  // insert(&d_Arr, 43, get_length(d_Arr) - 1);

  strrep(d_Arr);


  // int no = 11;
  // if (contains(d_Arr, no))
  // {
  //   printf("Found %i at index of: %i", no, search(d_Arr, 11));
  // }
  // else
  // {
  //   printf("Could not find %i in the array", no);
  // }


  // printf("The item @ index 4 is %i \n", get_at_index(d_Arr, -3));

  
  // printf("Length: %i \n", get_length(d_Arr));
  // printf("Capacity: %i \n", d_Arr.capacity);

  // append(&d_Arr, 3);

  // printf("The pointer stores the address: %p (%i) but it's address is: %p (%i) \n", d_Arr.data, d_Arr.data, &d_Arr.data, &d_Arr.data);
  // printf("What the pointer stores is: %p \n", *(&d_Arr.data));


  // append(&d_Arr, 6);

  // list(d_Arr);

  // printf("Length: %i \n", get_length(d_Arr));  
}