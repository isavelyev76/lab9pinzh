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
    cout << "�����: �������� ����\n";
    cout << "������: 23����\n\n";
    Product* products[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", products, size);
        cout << "***** ������� ������� *****\n\n";
        for (int i = 0; i < size; i++)
        {
            //����� ���� ������
            cout << "����........: ";
            cout << products[i]->price << " ";
            cout << '\n';

            //����� ���������� ������
            cout << "����������........: ";
            cout << products[i]->quantity << " ";
            cout << '\n';

            //����� ��������� ������
            cout << "���������........: ";
            cout << products[i]->category;
            cout << '\n';

            //����� �������� ������
            cout << "��������........: ";
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