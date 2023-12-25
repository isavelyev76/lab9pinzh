#include <iostream>
#include <algorithm>
#include "sortirovka.h"

// Функция сортировки по убыванию количества товара на складе
void selectionSortByQuantityDesc(Product* products[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (products[j]->quantity > products[maxIndex]->quantity)
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            std::swap(products[i], products[maxIndex]);
        }
    }
}

// Функция сортировки по возрастанию категории товара, а в рамках одной категории по убыванию стоимости
void sortByCategoryAndCost(Product* products[], int size)
{
    std::sort(products, products + size, [](Product* a, Product* b) {
        if (strcmp(a->category, b->category) == 0)
        {
            return a->price > b->price;
        }
        else
        {
            return strcmp(a->category, b->category) < 0;
        }
        });
}