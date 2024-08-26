#include <stdio.h>
#include <stdlib.h>

#include "../../include/data-structures/singly_linked_list.h"
#include "../../include/data-structures/stack.h"


Stack initStack(int size)
{
    Stack stack;

    LinkedList_ data = initLinkedList_();

    stack.data = &data;
    stack.size = size;

    return stack;
}


int stack_get_length(Stack s)
{
    return ll_size(*s.data);
}


int stack_get_size(Stack s)
{
    return s.size;
}


int stack_is_empty(Stack s)
{
    return ll_is_empty(*(s.data));
}


int stack_is_full(Stack s)
{
    // printf("2nd: %p, %p\n", s.data->head, s.data->tail);
    return (int) stack_get_length(s) == stack_get_size(s);
}


void stack_list(Stack s)
{
    /**
     * [<= =>| 2, 3, 4]
     * [=>| 4, -1, 0, 3 |=>]
     * 
     */
    printf("[<= =>| ");
    ll_list(*s.data);
    printf("]");
}


void stack_push(Stack *s, int value)
{
    if (stack_is_full(*s))
    {
        fprintf(stderr, "Stack is full");
        exit(EXIT_FAILURE);
    }

    ll_prepend(s->data, value);
}


void stack_pop(Stack *s)
{
    ll_remove_at_index(s->data, 0);
}