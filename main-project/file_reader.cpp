#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

void read(const char* file_name, Product* array[], int& size)
{
	std::ifstream file(file_name);
	if (file.is_open())
	{
		size = 0;

		while (!file.eof())
		{
			Product* item = new Product;
			file >> item->price;
			file >> item->quantity;
			file >> item->category;
			file.getline(item->name, MAX_STRING_SIZE);
			array[size++] = item;
		}
		file.close();
	}
	else
	{
		throw "  ";
	}
}