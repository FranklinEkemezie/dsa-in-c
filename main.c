#include <stdio.h>
#include <stdlib.h>

#include "include/data-structures/stack.h"
#include "include/data-structures/singly_linked_list.h"


int main(int argc, char *argv[])
{
  LinkedList_ ll_ = initLinkedList_();

  ll_append(&ll_, 3);
  ll_append(&ll_, -7);

  ll_strrep(ll_);
}