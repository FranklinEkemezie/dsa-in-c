#include <stdio.h>
#include <stdlib.h>

#include "include/data-structures/stack.h"
#include "include/data-structures/dynamic_stack.h"


int main()
{
  DynamicStack d_S = initDynamicStack();

  d_Stack_push(&d_S, 6);
  d_Stack_push(&d_S, 2);
  d_Stack_push(&d_S, 0);
  d_Stack_push(&d_S, 4);
  d_Stack_push(&d_S, -3);
  d_Stack_push(&d_S, 2);
  d_Stack_push(&d_S, 9);

  d_Stack_list(d_S);


  printf("d_S capacity is: %i; and Length: %i\n", d_S.data->capacity, d_S.data->length);


  // d_Stack_push(&d_S, 1);
}
