#include <stdio.h>
#include <stdlib.h>

#include "../../include/data-structures/singly_linked_list.h"


LinkedListSingle initSinglyLinkedList()
{
  LinkedListSingle ll_;

  Node *end_node = malloc(sizeof(Node));
  end_node = NULL;
  

  ll_.head = ll_.tail = end_node;

  return ll_;
}


Node *createNodeLL_(int data, Node *next)
{
  Node *n = malloc(sizeof(Node));

  n->data = data;
  n->next = next;

  return n;
}


void ll_append(LinkedListSingle *ll_, int value)
{
  // Create node to hold data
  Node *n = malloc(sizeof(Node));
  n->data = value;
  n->next = NULL;       // next node is NULL, since we are appending

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


int ll_contains(LinkedListSingle ll_, int value)
{
  Node *curr = ll_.head;
  while (curr != NULL)
  {
    if (curr->data == value) return 1;
    curr = curr->next;
  }

  return 0;
}


int ll_get_at_index(LinkedListSingle ll_, int index)
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
  Node *curr = ll_.head;      // current node: starting from the head
  while (curr != NULL)
  {
    if(counter == index) return curr->data;

    curr = curr->next;
    counter++;
  }
}


int ll_index_in_range(LinkedListSingle ll_, int index)
{
  return index >= 0 - ll_size(ll_) && index < ll_size(ll_);
}


void ll_insert(LinkedListSingle *ll_, int value, int index)
{
  if (index == 0) return ll_prepend(ll_, value);

  int ll_len = ll_size(*ll_);   // the length of the linked list
  if (index == ll_len) return ll_append(ll_, value);
  if(index < 0 || index > ll_len)
  {
    fprintf(stderr, "Index out o range: Cannot insert at index %i", index);
    exit(EXIT_FAILURE);
  }

  // Trasverse to the node at one index less than where we want to insert
  int counter = 0;
  Node *curr = ll_->head;
  while(counter < index - 1)
  {
    curr = curr->next;
    counter++;
  }

  // Create the node to insert
  Node *n = createNodeLL_(value, curr->next);

  curr->next = n;
}


int ll_is_empty(LinkedListSingle ll_)
{
  return ll_.head == NULL || ll_.tail == NULL;
}


void ll_list(LinkedListSingle ll_)
{
  if(ll_is_empty(ll_))
  {
    printf("[Head/Tail: <Node> NULL]\n");
  }
  else if (ll_size(ll_) == 1)
  {
    printf("[Head/Tail: %i]\n", ll_.head->data);
  }
  else
  {
    int index = 0;
    int size = ll_size(ll_);
    Node *curr = ll_.head;
    while (curr != NULL)
    {
      if (index == 0)
      {
        printf("[Head: %i] ", curr->data);
        printf("=> ");
      }
      else if (index == size - 1) 
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


void ll_prepend(LinkedListSingle *ll_, int value)
{
  // Create node to store data
  Node *n = malloc(sizeof(Node));
  n->data = value;
  n->next = NULL;

  if (ll_is_empty(*ll_))
  {
    ll_->head = ll_->tail = n;
  }

  n->next = ll_->head;
  ll_->head = n;
}


void ll_remove(LinkedListSingle *ll_, int value)
{
  if(!ll_contains(*ll_, value))
  {
    fprintf(stderr, "Could not remove item. Value %i not found", value);
    exit(EXIT_FAILURE);
  }

  ll_remove_at_index(ll_, ll_search(*ll_, value));
}


void ll_remove_at_index(LinkedListSingle *ll_, int index)
{
  // Check if index is within range
  if (!ll_index_in_range(*ll_, index))
  {
    fprintf(stderr, "Index out of range: Could not remove item at index %i", index);
    exit(EXIT_FAILURE);
  }

  // Trasverse to the node at one index less than where we want to remove
  int counter = 0;
  Node *curr = ll_->head;
  while (counter < index - 1)
  {
    curr = curr->next;
    counter++;
  }

  // Get the node to delete
  Node *node_to_remove = curr->next;

  curr->next = node_to_remove->next;

  free(node_to_remove);
}


int ll_search(LinkedListSingle ll_, int value)
{
  // Trasverse through the nodes one after the other
  int counter = 0;
  Node *curr = ll_.head;
  while (curr != NULL)
  {
    if (curr->data == value) return counter;

    curr = curr->next;
    counter++;
  }

  fprintf(stderr, "Value %i not found", value);
  exit(EXIT_FAILURE);
}


int ll_size(LinkedListSingle ll_)
{
  if (ll_is_empty(ll_)) return 0;

  int size = 0;

  Node *curr = ll_.head;
  while (curr != NULL)
  {
    size++;
    curr = curr->next;
  }

  return size;
}


void ll_strrep(LinkedListSingle ll_)
{
  printf("<LinkedListSingle>[%i] ", ll_size(ll_));
  ll_list(ll_);
}


