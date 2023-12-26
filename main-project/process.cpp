#include "processing.h"
#include <iostream>

double calculateTotalCost(const Product* products, int size, const char* category) {
    double totalCost = 0.0;
    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].category, category) == 0) {
            totalCost += products[i].price * products[i].quantity;
        }
    }
    return totalCost;
}