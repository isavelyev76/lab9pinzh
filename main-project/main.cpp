#include <iostream>

using namespace std;

#include "product.h"
#include "file_reader.h"
#include "constants.h"
#include "sortirovka.h"
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
        cout << "***** ������� ������� *****\n\n";
        for (int i = 0; i < size; i++)
        {
            // ����� ���� ������
            cout << "����........: ";
            cout << products[i]->price << " ";
            cout << '\n';

            // ����� ���������� ������
            cout << "����������........: ";
            cout << products[i]->quantity << " ";
            cout << '\n';

            // ����� ��������� ������
            cout << "���������........: ";
            cout << products[i]->category;
            cout << '\n';

            // ����� �������� ������
            cout << "��������........: ";
            cout << products[i]->name << " ";
            cout << '\n';
            cout << '\n';
        }

        // ����� ���� ������� � ��������� "����������"
        cout << "***** ������ � ��������� \"����������\" *****\n\n";
        for (int i = 0; i < size; i++)
        {
            if (strcmp(products[i]->category, "����������") == 0)
            {
                cout << "��������........: ";
                cout << products[i]->name << " ";
                cout << '\n';
                cout << "����........: ";
                cout << products[i]->price << " ";
                cout << '\n';
                cout << '\n';
            }
        }

        // ����� ���� ������� �� ���������� ���� 100 ������
        cout << "***** ������ �� ���������� ���� 100 ������ *****\n\n";
        for (int i = 0; i < size; i++)
        {
            if (products[i]->price > 100)
            {
                cout << "��������........: ";
                cout << products[i]->name << " ";
                cout << '\n';
                cout << "����........: ";
                cout << products[i]->price << " ";
                cout << '\n';
                cout << '\n';
            }
        }

        int sortingMethod;
        cout << "�������� ����� ����������:\n";
        cout << "1. ���������� �������� (Merge Sort)\n";
        cout << "2. ���������� ������� (Selection Sort)\n";
        cout << "��� �����: ";
        cin >> sortingMethod;

        int sortingCriteria;
        cout << "�������� �������� ����������:\n";
        cout << "1. �� �������� ���������� ������ �� ������\n";
        cout << "2. �� ����������� ��������� ������, � � ������ ����� ��������� �� �������� ���������\n";
        cout << "��� �����: ";
        cin >> sortingCriteria;

        cout << "***** ��������������� ������� ������� *****\n\n";

        switch (sortingMethod)
        {
        case 1:
            mergeSort(products, 0, size - 1, sortingCriteria);
            break;
        case 2:
            selectionSort(products, size, sortingCriteria);
            break;
        default:
            cout << "������������ ����� ������ ����������.\n";
            return 1;
        }

        for (int i = 0; i < size; i++)
        {
            // ����� ���� ������
            cout << "����........: ";
            cout << products[i]->price << " ";
            cout << '\n';

            // ����� ���������� ������
            cout << "����������........: ";
            cout << products[i]->quantity << " ";
            cout << '\n';

            // ����� ��������� ������
            cout << "���������........: ";
            cout << products[i]->category;
            cout << '\n';

            // ����� �������� ������
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

    return 0;
}