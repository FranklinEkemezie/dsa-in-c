#include <stdio.h>
#include <stdlib.h>

#include "../../include/data-structures/doubly_linked_list.h"

_LinkedList_ init_LinkedList_()
{
  _LinkedList_ *_ll_ = malloc(sizeof(_LinkedList_));

  _ll_->head = _ll_->tail = NULL;

  return *_ll_;
}


void free_LinkedList_(_LinkedList_ *_ll_)
{
  while (_ll_is_empty(*_ll_))
  {
    _ll_remove_at_index(_ll_, 0);
  }

  // Free the linked list memory
  free(_ll_);
}


_Node_ *create_Node_(int data, _Node_ *prev, _Node_ *next)
{
  _Node_ *n = malloc(sizeof(_Node_));

  n->data = data;
  n->prev = prev;
  n->next = next;

  return n;
}


void _ll_append(_LinkedList_ *_ll_, int value)
{
  // Create node to hold data
  _Node_ *n = create_Node_(value, NULL, NULL);

  if(_ll_is_empty(*_ll_))
  {
    _ll_->head = _ll_->tail = n;
  }
  else
  {
    n->prev           = _ll_->tail;
    _ll_->tail->next  = n;
    _ll_->tail        = _ll_->tail->next;
  }
}


int _ll_contains(_LinkedList_ _ll_, int value)
{
  // Trasverse through the array and check
  _Node_ *curr = _ll_.head;
  while (curr != NULL)
  {
    if (curr->data == value) return 1;
    curr = curr->next;
  }

  return 0;
}


int _ll_get_at_index(_LinkedList_ _ll_, int index)
{
  // Check if the index is within range
  if (!_ll_index_in_range(_ll_, index))  
  {
    fprintf(stderr, "Index out of range: Could not get item at index %i", index);
    exit(EXIT_FAILURE);
  }

  // For -ve index
  if (index < 0) index += _ll_size(_ll_);

  int counter = 0;
  _Node_ *curr = _ll_.head;     // current node: starting from the 'head'
  while (curr != NULL)
  {
    if (counter == index) return curr->data;

    curr = curr->next;
    counter++;
  }

  return -1;
}


int _ll_index_in_range(_LinkedList_ _ll_, int index)
{
  int _ll_len = _ll_size(_ll_);
  return index >= 0 - _ll_len && index < _ll_len;
}


void _ll_insert(_LinkedList_ *_ll_, int value, int index)
{
  if (index == 0) return _ll_prepend(_ll_, value);

  int _ll_len = _ll_size(*_ll_);    // the length of the doubly linked list
  if (index == _ll_len) return _ll_append(_ll_, value);
  if (index < 0 || index > _ll_len)
  {
    fprintf(stderr, "Index out of range: Cannot insert at index %i", index);
    exit(EXIT_FAILURE);
  }

  // Trasverse to the node at one index less than where we want to insert
  int counter = 0;
  _Node_ *curr = _ll_->head;
  while (counter < index - 1)
  {
    curr = curr->next;
    counter++;
  }

  // Create the node to insert
  _Node_ *n = create_Node_(value, curr->prev, curr->next);

  curr->next = n;
}


int _ll_is_empty(_LinkedList_ _ll_)
{
  return _ll_.head == NULL && _ll_.tail == NULL;
}


void _ll_list(_LinkedList_ _ll_)
{
  int _ll_len = _ll_size(_ll_);

  if (_ll_is_empty(_ll_))
  {
    printf("[Head/Tail: <Node> NULL]\n");
  }
  else if (_ll_len == 1)
  {
    printf("[Head/Tail: %i]\n", _ll_.head->data);
  }
  else
  {
    int index = 0;
    _Node_ *curr = _ll_.head;
    while (curr != NULL)
    {
      if (index == 0)
      {
        printf("[Head: %i] ", curr->data);
        printf("<=> ");
      }
      else if (index == _ll_len - 1)
      {
        printf("[Tail: %i]\n", curr->data);
      }
      else
      {
        printf("[%i] ", curr->data);
        printf("<=> ");
      }

      curr = curr->next;
      index++;
    }
  }
}


void _ll_prepend(_LinkedList_ *_ll_, int value)
{
  // Create node to store data
  _Node_ *n = malloc(sizeof(_Node_));
  n->data = value;
  n->next = NULL;

  if (_ll_is_empty(*_ll_))
  {
    _ll_->head = _ll_->tail = n;
  }

  n->next = _ll_->head;
  _ll_->head = n;
}


void _ll_remove(_LinkedList_ *_ll_, int value)
{
  if (!_ll_contains(*_ll_, value))
  {
    fprintf(stderr, "Could not remove item, Value %i not found", value);
    exit(EXIT_FAILURE);
  }

  _ll_remove_at_index(_ll_, _ll_search(*_ll_, value));
}


void _ll_remove_at_index(_LinkedList_ *_ll_, int index)
{
  // Check if index is within range
  if (!_ll_index_in_range(*_ll_, index))  
  {
    fprintf(stderr, "Index out of range: Could not remove item at index %i", index);
    exit(EXIT_FAILURE);
  }

  // Trasverse to the node at one index less than where we want to remove
  int counter = 0;
  _Node_ *curr = _ll_->head;
  while (counter < index - 1)
  {
    curr = curr->next;
    counter++;
  }

  // Get the node to delete
  _Node_ *node_to_remove = curr->next;

  curr->next = node_to_remove->next;

  free(node_to_remove);
}


int _ll_search(_LinkedList_ _ll_, int value)
{
  // Trasverse through the nodes one after the other
  int counter = 0;
  _Node_ *curr = _ll_.head;
  while (curr != NULL)
  {
    if (curr->data == value) return counter;

    curr = curr->next;
    counter++;
  }

  fprintf(stderr, "Value %i not found", value);
  exit(EXIT_FAILURE);
}


int _ll_size(_LinkedList_ _ll_)
{
  if (_ll_is_empty(_ll_)) return 0;

  int size = 0;

  _Node_ *curr = _ll_.head;
  while (curr != NULL)
  {
    size++;
    curr = curr->next;
  }

  return size;
}


void _ll_strrep(_LinkedList_ _ll_)
{
  printf("<_LinkedList_>[%i] ", _ll_size(_ll_));
  _ll_list(_ll_);
}
