#ifndef PRODUCT_H
#define PRODUCT_H

#include "constants.h"

struct Product {
    double price;
    int quantity;
    char category[MAX_STRING_SIZE];
    char name[MAX_STRING_SIZE];
};

#endif