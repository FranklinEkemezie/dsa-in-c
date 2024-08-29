#include <stdio.h>
#include <stdlib.h>

#include "../../include/data-structures/singly_linked_list.h"
#include "../../include/data-structures/stack.h"


Stack initStack(int size)
{
    Stack *stack = malloc(sizeof(Stack));

    LinkedList_ *data = malloc(sizeof(LinkedList_));
    *data = initLinkedList_();

    stack->data = data;
    stack->size = size;

    return *stack;
}


void freeStack(Stack *s)
{
    while (!stack_is_empty(*s))
    {
        stack_pop(s);
    }

    // Free the linked list 'data' variable
    free(s->data);

    // Free the stack itself
    free(s);
}


int stack_get_length(Stack s)
{
    return ll_size(*(s.data));
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
    return stack_get_length(s) == stack_get_size(s)  ? 1 : 0;
}


void stack_list(Stack s)
{
    printf("[<= =>| ");

    // Print the element of the stack
    int index = 0, len = stack_get_length(s);
    Node_ *curr = s.data->head;
    while (curr != NULL)
    {
        printf("%i", curr->data);
        if (index != len - 1) printf(", ");

        index++;
        curr = curr->next;
    }

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
    if (stack_is_empty(*s))
    {
        fprintf(stderr, "Nothing to pop. Stack is empty");
        exit(EXIT_FAILURE);
    }

    ll_remove_at_index(s->data, 0);
}