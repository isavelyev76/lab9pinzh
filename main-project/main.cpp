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
    cout << "Автор: Савельев Илья\n";
    cout << "Группа: 23ПИнж\n\n";
    Product* products[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", products, size);
        cout << "***** Каталог товаров *****\n\n";
        for (int i = 0; i < size; i++)
        {
            //Вывод цены товара
            cout << "Цена........: ";
            cout << products[i]->price << " ";
            cout << '\n';

            //Вывод количества товара
            cout << "Количество........: ";
            cout << products[i]->quantity << " ";
            cout << '\n';

            //Вывод категории товара
            cout << "Категория........: ";
            cout << products[i]->category;
            cout << '\n';

            //Вывод названия товара
            cout << "Название........: ";
            cout << products[i]->name << " ";
            cout << '\n';
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

    cout << "Laboratory work #9. GIT\n";
    cout << "Variant #0. Catalog\n";
    cout << "Author: Ilya Savelyev\n";
    cout << "Group: 23PInzh1d\n";

    return 0;
}