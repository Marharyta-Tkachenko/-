#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void FillMatrix(int** matrix, const int size, const int Low, const int High);
void PrintMatrix(int** matrix, const int size);
bool CheckifSymmetric(int** matrix, const int size);
void GetTransposedMatrix(int** matrix, int** transposedMatrix, const int size);

int main()
{
    srand((unsigned)time(NULL));
    const int Low = -41;
    const int High = 23;
    int size;
    int n;
    int m;

    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;

    if (n != m)
    {
        cout << "Matrix must be square" << endl;
        exit(1);
    }

    size = n;
    int** matrix = new int* [size];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[size];

    FillMatrix(matrix, size, Low, High);


    if (CheckifSymmetric(matrix, size))
        cout << "Your matrix is symmetric" << endl;

    else
        cout << "Your matrix isn't symmetric" << endl;

    PrintMatrix(matrix, size);


    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}

void FillMatrix(int** matrix, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int temp;
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> temp;

            matrix[i][j] = (temp > Low && temp < High) ? temp : Low; // если число не в диапазоне, тогда Low
        }
        cout << endl;
    }

}
void PrintMatrix(int** matrix, const int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << std::setw(4) << matrix[i][j];
        cout << endl;
    }
    cout << endl;

}

bool CheckifSymmetric(int** matrix, const int size)
{
    bool isEqual = true;

    // матрица будет симметричной, если совпадает с транспонированной
    int** transposedMatrix = new int* [size];
    for (int i = 0; i < size; i++)
        transposedMatrix[i] = new int[size];

    GetTransposedMatrix(matrix, transposedMatrix, size);


    for (int i = 0; i < size && isEqual; ++i)
    {
        for (int j = 0; j < size && isEqual; ++j)
        {
            if (matrix[i][j] != transposedMatrix[i][j])
            {
                // если есть хоть один елемент, который не совпадает с елементом транспонированной матрицы:
                //- матрица несимметричная. Цикл обрывается
                isEqual = false;
            }
        }
    }

    for (int i = 0; i < size; i++)
        delete[] transposedMatrix[i];

    return isEqual;
}


void GetTransposedMatrix(int** matrix, int** transposedMatrix, const int size)
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            transposedMatrix[j][i] = matrix[i][j];
}