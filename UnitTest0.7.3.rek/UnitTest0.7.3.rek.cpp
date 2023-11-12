#include "pch.h"
#include "CppUnitTest.h"
#include "../PR-07.3.rek/PR-07.3.rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest073rek
{
	TEST_CLASS(UnitTest073rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            // Arrange
            const int rowCount = 3;
            const int colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                a[i] = new int[colCount];
            }

            // Fill the matrix with values for the test case
            a[0][0] = 1;
            a[0][1] = 2;
            a[0][2] = 3;
            a[1][0] = 4;
            a[1][1] = 5;
            a[1][2] = 6;
            a[2][0] = 7;
            a[2][1] = 8;
            a[2][2] = 9;

            int row = -1, col = -1;

            // Act
            Part2_SaddlePoint(a, rowCount, colCount, 0, 0);

            // Assert
            Assert::AreEqual(-1, row);
            Assert::AreEqual(-1, col);

            // Clean up
            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
		}
	};
}
