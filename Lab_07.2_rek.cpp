#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int n, const int Low, const int High, int i, int j);
void Print(int** a, const int n, int i, int j);
void FindMaxAboveDiagonal(int** a, const int n, int& maxElement, int& maxRow, int& maxCol, int i, int j);
void FindMinBelowDiagonal(int** a, const int n, int& minElement, int& minRow, int& minCol, int i, int j);
void SwapMaxMin(int** a, int maxRow, int maxCol, int minRow, int minCol);
int CalculateSum(int maxElement, int minElement);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 0;
    int High = 10;
    int n;
    cout << "n = "; cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High, 0, 0);
    cout << "Original matrix:" << endl;
    Print(a, n, 0, 0);

    int maxElement = a[0][1], maxRow = 0, maxCol = 1, minElement = a[1][0], minRow = 1, minCol = 0;
    FindMaxAboveDiagonal(a, n, maxElement, maxRow, maxCol, 0, 1);
    FindMinBelowDiagonal(a, n, minElement, minRow, minCol, 1, 0);

    cout << endl;
    cout << "Maximum element above diagonal: " << maxElement << endl;
    cout << "Minimum element below diagonal: " << minElement << endl;

    cout << endl;
    SwapMaxMin(a, maxRow, maxCol, minRow, minCol);
    cout << "Modified matrix:" << endl;
    Print(a, n, 0, 0);

    cout << endl;
    int sum = CalculateSum(maxElement, minElement);
    cout << "Sum of maximum and minimum elements: " << sum << endl;

    // Free memory
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}


void Create(int** a, const int n, const int Low, const int High, int i, int j)
{
    if (i >= n)
        return;

    if (j >= n) {
        Create(a, n, Low, High, i + 1, 0);
        return;
    }
    a[i][j] = Low + rand() % (High - Low + 1);
    Create(a, n, Low, High, i, j + 1);
}

void Print(int** a, const int n, int i, int j)
{
    if (i >= n)
        return;

    if (j >= n) {
        cout << endl;
        Print(a, n, i + 1, 0);
        return;
    }
    cout << setw(4) << a[i][j];
    Print(a, n, i, j + 1);
}

void FindMaxAboveDiagonal(int** a, const int n, int& maxElement, int& maxRow, int& maxCol, int i, int j)
{
    if (i >= n - 1)
        return;

    if (j < n) {
        if (a[i][j] > maxElement) {
            maxElement = a[i][j];
            maxRow = i;
            maxCol = j;
        }
        FindMaxAboveDiagonal(a, n, maxElement, maxRow, maxCol, i, j + 1);
    }
    else {
        FindMaxAboveDiagonal(a, n, maxElement, maxRow, maxCol, i + 1, i + 2);
    }
}



void FindMinBelowDiagonal(int** a, const int n, int& minElement, int& minRow, int& minCol, int i, int j)
{
    if (i >= n - 1) 
        return;

    if (j < i) {
        if (a[i][j] < minElement) {
            minElement = a[i][j];
            minRow = i;
            minCol = j;
        }
        FindMinBelowDiagonal(a, n, minElement, minRow, minCol, i, j + 1);
    }
    else {
        FindMinBelowDiagonal(a, n, minElement, minRow, minCol, i + 1, 0);
    }
}

void SwapMaxMin(int** a, int maxRow, int maxCol, int minRow, int minCol)
{
    int temp = a[maxRow][maxCol];
    a[maxRow][maxCol] = a[minRow][minCol];
    a[minRow][minCol] = temp;
}

int CalculateSum(int maxElement, int minElement)
{
    return maxElement + minElement;
}