#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.2_rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72rek
{
	TEST_CLASS(UnitTest72rek)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            srand((unsigned)time(NULL));
            int Low = 0;
            int High = 10;
            int n = 3;
           

            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            Create(a, n, Low, High, 0, 0);

            int maxElement = a[0][1], maxRow = 0, maxCol = 1, minElement = a[1][0], minRow = 1, minCol = 0;
            FindMaxAboveDiagonal(a, n, maxElement, maxRow, maxCol, 0, 1);

            Assert::AreEqual(maxElement, 9);
		}
	};
}
