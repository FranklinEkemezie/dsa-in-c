#include <stdio.h>
#include <stdlib.h>

#include "../../include/data-structures/dynamic_array.h"
#include "../../include/data-structures/set.h"

Set initSet()
{
  Set set;

  // The dynamic array somewhere else in memory
  DynamicArray d_Arr = initDynamicArray();

  set.d_arr = &d_Arr;

  return set;
}