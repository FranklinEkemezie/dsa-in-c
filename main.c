#include <stdio.h>
#include <stdlib.h>

#include "include/data-structures/stack.h"
#include "include/data-structures/singly_linked_list.h"


int main()
{
  Stack s = initStack(4);

  stack_pop(&s);
  // stack_push(&s, 5);
  // stack_push(&s, -3);
  // stack_push(&s, 7);
  // stack_push(&s, 0);


  stack_list(s);
}