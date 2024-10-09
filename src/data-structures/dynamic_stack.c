#include <stdio.h>
#include <stdlib.h>

#include "../../include/data-structures/dynamic_stack.h"


DynamicStack createDynamicStack()
{
    DynamicStack *d_Stack = malloc(sizeof(DynamicStack));

    DynamicArray *d_Arr = malloc(sizeof(DynamicArray));
    *d_Arr = createDynamicArray();

    d_Stack->data = d_Arr;

    return *d_Stack;
}


void freeDynamicStack(DynamicStack *d_Stack)
{
    while (d_Stack_is_empty(*d_Stack))
    {
        d_Stack_pop(d_Stack);
    }

    // Free the dynamic array
    free(d_Stack->data);

    // Free the dynamic stack itself
    free(d_Stack);
}


int d_Stack_get_length(DynamicStack d_Stack)
{
    return d_Arr_get_length(*d_Stack.data);
}


int d_Stack_is_empty(DynamicStack d_Stack)
{
    return d_Stack_get_length(d_Stack) == 0;
}


void d_Stack_list(DynamicStack d_Stack)
{
    int len = d_Stack_get_length(d_Stack);

    printf("[<?= =?>| ");

    // Print the element of the dynamic stack
    for (int i = 0; i < len; i++)
    {
        printf("%i", d_Arr_get_at_index(*d_Stack.data, i));
        if (i != len - 1) printf(", ");
    }

    printf("]\n");
}


int d_Stack_peep(DynamicStack d_Stack)
{
    if (!d_Stack_is_empty(d_Stack)) return d_Stack.data->data[0];

    fprintf(stderr, "Dynamic stack is empty");
    exit(EXIT_FAILURE);
}


void d_Stack_push(DynamicStack *d_Stack, int value)
{
    d_Arr_prepend(d_Stack->data, value);
}


int d_Stack_pop(DynamicStack *d_Stack)
{
    if (d_Stack_is_empty(*d_Stack))
    {
        fprintf(stderr, "Nothing to pop. Dynamic stack is empty");
        exit(EXIT_FAILURE);
    }

    int item_to_pop = d_Stack->data->data[0];

    d_Arr_remove_at_index(d_Stack->data, 0);

    return item_to_pop;
}


void d_Stack_strrep(DynamicStack d_Stack)
{
    printf("<Stack>[%i] ", d_Stack_get_length(d_Stack));
    d_Stack_list(d_Stack);
}