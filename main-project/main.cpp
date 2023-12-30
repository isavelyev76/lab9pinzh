#include <iostream>

using namespace std;

#include "product.h"
#include "file_reader.h"
#include "constants.h"
#include "sortirovka.h"
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
        cout << "***** Каталог товаров *****\n\n";
        for (int i = 0; i < size; i++)
        {
            // Вывод цены товара
            cout << "Цена........: ";
            cout << products[i]->price << " ";
            cout << '\n';

            // Вывод количества товара
            cout << "Количество........: ";
            cout << products[i]->quantity << " ";
            cout << '\n';

            // Вывод категории товара
            cout << "Категория........: ";
            cout << products[i]->category;
            cout << '\n';

            // Вывод названия товара
            cout << "Название........: ";
            cout << products[i]->name << " ";
            cout << '\n';
            cout << '\n';
        }

        // Вывод всех товаров в категории "Промтовары"
        cout << "***** Товары в категории \"Промтовары\" *****\n\n";
        for (int i = 0; i < size; i++)
        {
            if (strcmp(products[i]->category, "Промтовары") == 0)
            {
                cout << "Название........: ";
                cout << products[i]->name << " ";
                cout << '\n';
                cout << "Цена........: ";
                cout << products[i]->price << " ";
                cout << '\n';
                cout << '\n';
            }
        }

        // Вывод всех товаров со стоимостью выше 100 рублей
        cout << "***** Товары со стоимостью выше 100 рублей *****\n\n";
        for (int i = 0; i < size; i++)
        {
            if (products[i]->price > 100)
            {
                cout << "Название........: ";
                cout << products[i]->name << " ";
                cout << '\n';
                cout << "Цена........: ";
                cout << products[i]->price << " ";
                cout << '\n';
                cout << '\n';
            }
        }

        int sortingMethod;
        cout << "Выберите метод сортировки:\n";
        cout << "1. Сортировка слиянием (Merge Sort)\n";
        cout << "2. Сортировка выбором (Selection Sort)\n";
        cout << "Ваш выбор: ";
        cin >> sortingMethod;

        int sortingCriteria;
        cout << "Выберите критерий сортировки:\n";
        cout << "1. По убыванию количества товара на складе\n";
        cout << "2. По возрастанию категории товара, а в рамках одной категории по убыванию стоимости\n";
        cout << "Ваш выбор: ";
        cin >> sortingCriteria;

        cout << "***** Отсортированный каталог товаров *****\n\n";

        switch (sortingMethod)
        {
        case 1:
            mergeSort(products, 0, size - 1, sortingCriteria);
            break;
        case 2:
            selectionSort(products, size, sortingCriteria);
            break;
        default:
            cout << "Некорректный выбор метода сортировки.\n";
            return 1;
        }

        for (int i = 0; i < size; i++)
        {
            // Вывод цены товара
            cout << "Цена........: ";
            cout << products[i]->price << " ";
            cout << '\n';

            // Вывод количества товара
            cout << "Количество........: ";
            cout << products[i]->quantity << " ";
            cout << '\n';

            // Вывод категории товара
            cout << "Категория........: ";
            cout << products[i]->category;
            cout << '\n';

            // Вывод названия товара
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

    return 0;
}