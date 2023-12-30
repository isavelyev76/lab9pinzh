#ifndef SORTIROVKA_H
#define SORTIROVKA_H

#include "product.h"

// Merge Sort
void merge(Product* arr[], int left, int mid, int right, int sortingCriteria);
void mergeSort(Product* arr[], int left, int right, int sortingCriteria);

// Selection Sort
void selectionSort(Product* arr[], int size, int sortingCriteria);

#endif