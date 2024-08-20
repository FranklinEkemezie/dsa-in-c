#include <stdio.h>
#include <stdlib.h>

#include "../../include/data-structures/doubly_linked_list.h"


_LinkedList_ init_LinkedList_()
{
  _LinkedList_ _ll_;

  _Node_ *end_node = malloc(sizeof(_Node_));
  end_node = NULL;

  _ll_.head = _ll_.tail = end_node;

  return _ll_;
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