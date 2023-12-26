#include "pch.h"
#include "CppUnitTest.h"

#include "../main-project/product.h"
#include "../main-project/processing.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
    TEST_CLASS(unittestproject)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            Product products[3];
            products[0].price = 5.0;
            products[0].quantity = 1;
            strncpy_s(products[0].category, "Category1", MAX_STRING_SIZE - 1);
            strncpy_s(products[0].name, "Product1", MAX_STRING_SIZE - 1);

            products[1].price = 7.0;
            products[1].quantity = 1;
            strncpy_s(products[1].category, "Category2", MAX_STRING_SIZE - 1);
            strncpy_s(products[1].name, "Product2", MAX_STRING_SIZE - 1);

            products[2].price = 4.0;
            products[2].quantity = 1;
            strncpy_s(products[2].category, "Category1", MAX_STRING_SIZE - 1);
            strncpy_s(products[2].name, "Product3", MAX_STRING_SIZE - 1);

            double totalCost = calculateTotalCost(products, 3, "Category1");
            Assert::AreEqual(9.0, totalCost);
        }

        TEST_METHOD(TestMethod2)
        {
            Product products[3];
            products[0].price = 15.0;
            products[0].quantity = 1;
            strncpy_s(products[0].category, "Category1", MAX_STRING_SIZE - 1);
            strncpy_s(products[0].name, "Product4", MAX_STRING_SIZE - 1);

            products[1].price = 19.0;
            products[1].quantity = 1;
            strncpy_s(products[1].category, "Category2", MAX_STRING_SIZE - 1);
            strncpy_s(products[1].name, "Product5", MAX_STRING_SIZE - 1);

            products[2].price = 14.0;
            products[2].quantity = 1;
            strncpy_s(products[2].category, "Category1", MAX_STRING_SIZE - 1);
            strncpy_s(products[2].name, "Product6", MAX_STRING_SIZE - 1);

            double totalCost = calculateTotalCost(products, 3, "Category1");
            Assert::AreEqual(29.0, totalCost);
        }

        // Add more test cases as needed
    };
}
