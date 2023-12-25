#include <iostream>

using namespace std;

#include "product.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������������ ������ �9. GIT\n";
    cout << "������� �10. ������� �������\n";
    cout << "�����: �������� ����\n\n";
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