#include <stdio.h>
#include <stdlib.h>

#include "./include/data-structures/dynamic_array.h"
#include "./include/data-structures/set.h"

int main(int argc, char *argv[])
{

  // Create an array to hold parsed argument variables
  int arg_arr_len = argc - 1;
  int *arg_values = malloc(arg_arr_len * sizeof(int));

  for (int i = 0; i < argc; i++)
  {
    if(i = 0) continue;
    arg_values[i] = atoi(argv[i]);
  }
  


  Set set = initSet();

  set_insert(&set, 5);
  set_insert(&set, 0);

  set_insert_values(&set, arg_values, arg_arr_len);


  set_strrep(set);

}
