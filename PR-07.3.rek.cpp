#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Input(int** a, const int rowCount, const int colCount, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
bool Part1_Count(int** a, const int rowCount, const int colCount, int& count, int j);
void Part2_SaddlePoint(int** a, const int rowCount, const int colCount, int n, int k);
bool IsMaxInRowN(int** a, const int n, const int k, const int colCount, int j);
bool IsMinInColK(int** a, const int n, const int k, const int rowCount, int i);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 15;
    int rowCount, colCount;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Input(a, rowCount, colCount, 0, 0);
    Print(a, rowCount, colCount, 0, 0);

    int count = 0;
    if (Part1_Count(a, rowCount, colCount, count, 0))
        cout << "Number of columns with at least one zero element: " << count << endl;
    else
        cout << "There are no zero elements in any column." << endl;

    cout << endl;
    Part2_SaddlePoint(a, rowCount, colCount, 0, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

bool Part1_Count(int** a, const int rowCount, const int colCount, int& count, int j)
{
    if (j == colCount)
        return count > 0;

    for (int i = 0; i < rowCount; i++)
    {
        if (a[i][j] == 0)
        {
            count++;
            break;
        }
    }

    return Part1_Count(a, rowCount, colCount, count, j + 1);
}

void Part2_SaddlePoint(int** a, const int rowCount, const int colCount, int n, int k)
{
    if (n == rowCount)
        return;

    if (k == colCount)
    {
        Part2_SaddlePoint(a, rowCount, colCount, n + 1, 0);
        return;
    }

    if (IsMaxInRowN(a, n, k, colCount, 0) && IsMinInColK(a, n, k, rowCount, 0))
        cout << "Saddle point at row " << n << " and column " << k << endl;

    Part2_SaddlePoint(a, rowCount, colCount, n, k + 1);
}

bool IsMaxInRowN(int** a, const int n, const int k, const int colCount, int j)
{
    if (j == colCount)
        return true;

    return (a[n][j] <= a[n][k]) && IsMaxInRowN(a, n, k, colCount, j + 1);
}

bool IsMinInColK(int** a, const int n, const int k, const int rowCount, int i)
{
    if (i == rowCount)
        return true;

    return (a[i][k] >= a[n][k]) && IsMinInColK(a, n, k, rowCount, i + 1);
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    if (i == rowCount)
        return;

    if (j == colCount)
    {
        Create(a, rowCount, colCount, Low, High, i + 1, 0);
        return;
    }

    a[i][j] = Low + rand() % (High - Low + 1);

    Create(a, rowCount, colCount, Low, High, i, j + 1);
}

void Input(int** a, const int rowCount, const int colCount, int i, int j)
{
    if (i == rowCount)
        return;

    if (j == colCount)
    {
        Input(a, rowCount, colCount, i + 1, 0);
        return;
    }

    cout << "a[" << i << "][" << j << "] = ";
    cin >> a[i][j];

    Input(a, rowCount, colCount, i, j + 1);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
    if (i == rowCount)
        return;

    if (j == colCount)
    {
        cout << endl;
        Print(a, rowCount, colCount, i + 1, 0);
        return;
    }

    cout << setw(4) << a[i][j];
    Print(a, rowCount, colCount, i, j + 1);
}