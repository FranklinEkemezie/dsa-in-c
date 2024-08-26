#include <stdio.h>
#include <stdlib.h>

#include "../../include/data-structures/singly_linked_list.h"


LinkedList_ initLinkedList_()
{
  LinkedList_ ll_;

  ll_.head = ll_.tail = NULL;

  return ll_;
}


Node_ *createNode_(int data, Node_ *next)
{
  Node_ *n = malloc(sizeof(Node_));

  n->data = data;
  n->next = next;

  return n;
}


void ll_append(LinkedList_ *ll_, int value)
{
  Node_ *n = createNode_(value, NULL);

  if (ll_is_empty(*ll_))
  {
    ll_->head = ll_->tail = n;
  }
  else
  {
    ll_->tail->next = n;
    ll_->tail = ll_->tail->next;
  }
}


int ll_contains(LinkedList_ ll_, int value)
{
  Node_ *curr = ll_.head;
  while (curr != NULL)
  {
    if (curr->data == value) return 1;
    curr = curr->next;
  }

  return 0;
}


int ll_get_at_index(LinkedList_ ll_, int index)
{
  // Check if index within range
  if (!ll_index_in_range(ll_, index))
  {
    fprintf(stderr, "Index out of range: Could not get item at index %i", index);
    exit(EXIT_FAILURE);
  }

  // For -ve index
  if(index < 0) index += ll_size(ll_);

  int counter = 0;
  Node_ *curr = ll_.head;      // current node: starting from the head
  while (curr != NULL)
  {
    if(counter == index) return curr->data;

    curr = curr->next;
    counter++;
  }
}


int ll_index_in_range(LinkedList_ ll_, int index)
{
  int ll_len = ll_size(ll_);
  return index >= 0 - ll_len && index < ll_len;
}


void ll_insert(LinkedList_ *ll_, int value, int index)
{
  if (index == 0) return ll_prepend(ll_, value);

  int ll_len = ll_size(*ll_);   // the length of the linked list
  if (index == ll_len) return ll_append(ll_, value);
  if(index < 0 || index > ll_len)
  {
    fprintf(stderr, "Index out of range: Cannot insert at index %i", index);
    exit(EXIT_FAILURE);
  }

  // Trasverse to the node at one index less than where we want to insert
  int counter = 0;
  Node_ *curr = ll_->head;
  while(counter < index - 1)
  {
    curr = curr->next;
    counter++;
  }

  // Create the node to insert
  Node_ *n = createNode_(value, curr->next);

  curr->next = n;
}


int ll_is_empty(LinkedList_ ll_)
{
  return ll_.head == NULL && ll_.tail == NULL;
}


void ll_list(LinkedList_ ll_)
{
  int ll_len = ll_size(ll_);

  if(ll_is_empty(ll_))
  {
    printf("[Head/Tail: <Node> NULL]\n");
  }
  else if (ll_len == 1)
  {
    printf("[Head/Tail: %i]\n", ll_.head->data);
  }
  else
  {
    int index = 0;
    Node_ *curr = ll_.head;
    while (curr != NULL)
    {
      if (index == 0)
      {
        printf("[Head: %i] ", curr->data);
        printf("=> ");
      }
      else if (index == ll_len - 1) 
      {
        printf("[Tail: %i]\n", curr->data);
      }
      else {
        printf("[%i] ", curr->data);
        printf("=> ");
      }

      curr = curr->next;
      index++;
    }
  }
}


void ll_prepend(LinkedList_ *ll_, int value)
{
  // Create node to store data
  Node_ *n = createNode_(value, NULL);

  if (ll_is_empty(*ll_))
  {
    ll_->head = ll_->tail = n;
  }

  n->next = ll_->head;
  ll_->head = n;
}


void ll_remove(LinkedList_ *ll_, int value)
{
  if(!ll_contains(*ll_, value))
  {
    fprintf(stderr, "Could not remove item. Value %i not found", value);
    exit(EXIT_FAILURE);
  }

  ll_remove_at_index(ll_, ll_search(*ll_, value));
}


void ll_remove_at_index(LinkedList_ *ll_, int index)
{
  // Check if index is within range
  if (!ll_index_in_range(*ll_, index))
  {
    fprintf(stderr, "Index out of range: Could not remove item at index %i", index);
    exit(EXIT_FAILURE);
  }

  // Trasverse to the node at one index less than where we want to remove
  int counter = 0;
  Node_ *curr = ll_->head;
  while (counter < index - 1)
  {
    curr = curr->next;
    counter++;
  }

  // Get the node to delete
  Node_ *node_to_remove = curr->next;

  curr->next = node_to_remove->next;

  free(node_to_remove);
}


int ll_search(LinkedList_ ll_, int value)
{
  // Trasverse through the nodes one after the other
  int counter = 0;
  Node_ *curr = ll_.head;
  while (curr != NULL)
  {
    if (curr->data == value) return counter;

    curr = curr->next;
    counter++;
  }

  fprintf(stderr, "Value %i not found", value);
  exit(EXIT_FAILURE);
}


int ll_size(LinkedList_ ll_)
{
  if (ll_is_empty(ll_)) return 0;

  int size = 0;

  Node_ *curr = ll_.head;
  while (curr != NULL)
  {
    size++;
    curr = curr->next;
  }

  return size;
}


void ll_strrep(LinkedList_ ll_)
{
  printf("<LinkedList_>[%i] ", ll_size(ll_));
  ll_list(ll_);
}
