#include <iostream>

using namespace std;

#include "product.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №9. GIT\n";
    cout << "Вариант №10. Каталог товаров\n";
    cout << "Автор: Савельев Илья\n\n";
    Product* products[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", products, size);
        for (int i = 0; i < size; i++)
        {
            cout << products[i]->price << " ";
            cout << products[i]->quantity << " ";
            cout << products[i]->category;
            cout << products[i]->name << " ";
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete products[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}