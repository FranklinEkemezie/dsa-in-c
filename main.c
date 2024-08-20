#include <stdio.h>
#include <stdlib.h>

// #include "./include/data-structures/dynamic_array.h"
// #include "./include/data-structures/set.h"
// #include "./include/data-structures/singly_linked_list.h"
#include "./include/data-structures/doubly_linked_list.h"

int main(int argc, char *argv[])
{
  _LinkedList_ _ll_ = init_LinkedList_();

  _ll_append(&_ll_, 3);
  _ll_append(&_ll_, 8);
  _ll_append(&_ll_, 6);
  _ll_append(&_ll_, 2);

  _ll_list(_ll_);
  

  // LinkedList_ ll_ = initLinkedList_();

  // ll_append(&ll_, 5);
  // // ll_prepend(&ll_, 0);
  // ll_append(&ll_, 4);
  // ll_append(&ll_, 6);
  // ll_append(&ll_, 9);

  // printf("Afert appending: ");
  // ll_strrep(ll_);

  // ll_insert(&ll_, 1, 0);
  // ll_insert(&ll_, 8, 4);

  // printf("After inserting: ");
  // ll_strrep(ll_);

  // ll_remove(&ll_, 4);
  // ll_remove_at_index(&ll_, 3);

  // printf("After removing: ");
  // ll_strrep(ll_);

}