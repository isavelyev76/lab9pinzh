#include "filter.h"
#include <cstring>
#include <iostream>

Product** filter(Product* array[], int size, bool (*check)(Product* element), int& result_size)
{
    Product** result = new Product * [size];
    result_size = 0;

    for (int i = 0; i < size; i++)
    {
        if (check(array[i]))
        {
            result[result_size++] = array[i];
        }
    }

    return result;
}

bool check_product_first(Product* element)
{
    return strcmp(element->category, "Промтовары") == 0;
}

bool check_product_second(Product* element)
{
    return element->price > 100;
}