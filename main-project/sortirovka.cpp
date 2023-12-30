#include "sortirovka.h"

// Merge Sort
void merge(Product* arr[], int left, int mid, int right, int sortingCriteria)
{
    int* const n1 = new int(mid - left + 1);
    int* const n2 = new int(right - mid);

    // Create temporary arrays
    Product** const L = new Product * [(*n1)];
    Product** const R = new Product * [(*n2)];

    // Copy data to temporary arrays
    for (int i = 0; i < (*n1); i++)
        L[i] = arr[left + i];
    for (int j = 0; j < (*n2); j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays
    int i = 0;
    int j = 0;
    int k = left;

    while (i < (*n1) && j < (*n2))
    {
        if (sortingCriteria == 1)
        {
            // Sort by decreasing quantity
            if (L[i]->quantity >= R[j]->quantity)
                arr[k++] = L[i++];
            else
                arr[k++] = R[j++];
        }
        else if (sortingCriteria == 2)
        {
            // Sort by increasing category and decreasing price within the same category
            if (L[i]->category < R[j]->category)
                arr[k++] = L[i++];
            else if (L[i]->category > R[j]->category)
                arr[k++] = R[j++];
            else
            {
                if (L[i]->price >= R[j]->price)
                    arr[k++] = L[i++];
                else
                    arr[k++] = R[j++];
            }
        }
    }

    // Copy the remaining elements of L[]
    while (i < (*n1))
        arr[k++] = L[i++];

    // Copy the remaining elements of R[]
    while (j < (*n2))
        arr[k++] = R[j++];

    // Clean up dynamically allocated memory
    delete n1;
    delete n2;
    delete[] L;
    delete[] R;
}

void mergeSort(Product* arr[], int left, int right, int sortingCriteria)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid, sortingCriteria);
        mergeSort(arr, mid + 1, right, sortingCriteria);

        merge(arr, left, mid, right, sortingCriteria);
    }
}

// Selection Sort
void selectionSort(Product* arr[], int size, int sortingCriteria)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (sortingCriteria == 1)
            {
                // Sort by decreasing quantity
                if (arr[j]->quantity > arr[minIndex]->quantity)
                    minIndex = j;
            }
            else if (sortingCriteria == 2)
            {
                // Sort by increasing category and decreasing price within the same category
                if (arr[j]->category < arr[minIndex]->category)
                    minIndex = j;
                else if (arr[j]->category == arr[minIndex]->category)
                {
                    if (arr[j]->price > arr[minIndex]->price)
                        minIndex = j;
                }
            }
        }

        // Swap the found minimum element with the first element
        Product* temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}