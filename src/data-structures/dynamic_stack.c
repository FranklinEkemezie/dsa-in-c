#include <stdio.h>
#include <stdlib.h>

#include "../../include/data-structures/dynamic_array.h"
#include "../../include/data-structures/dynamic_stack.h"


DynamicStack initDynamicStack()
{
    DynamicStack *d_Stack = malloc(sizeof(DynamicStack));
    DynamicArray d_Arr = initDynamicArray();

    d_Stack->data = &d_Arr;

    return *d_Stack;
}




