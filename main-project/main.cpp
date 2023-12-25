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

        cout << "***** Меню *****" << endl;
        cout << "1. Вывести по убыванию количества товара на складе:" << endl;
        cout << "2. Вывести по возрастанию категории товара, а в рамках одной категории по убыванию стоимости:" << endl;
        cout << "3. Выход" << endl;

        int choice;
        bool exitMenu = false;

        while (!exitMenu)
        {
            cout << "Выберите пункт меню: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                cout << "***** По убыванию количества товара на складе: *****\n\n";
                selectionSortByQuantityDesc(products, size);
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
            }
            break;

            case 2:
            {
                cout << "***** По возрастанию категории товара, а в рамках одной категории по убыванию стоимости: *****\n\n";
                sortByCategoryAndCost(products, size);
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
            }
            break;

            case 3:
                exitMenu = true;
                break;

            default:
                cout << "Некорректный выбор. Повторите попытку." << endl;
                break;
            }
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