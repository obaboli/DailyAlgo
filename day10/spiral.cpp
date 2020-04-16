/*
    print 2D array in a Spiral
*/
#include <iostream>

template <size_t rows, size_t cols>
void print2D(int (&arr)[rows][cols])
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

template <size_t rows, size_t cols>
void printSpiral(int (&arr)[rows][cols])
{

    // weird edge case to handle one center value in spiral
    if (rows == 1 && cols == 1) {
        std::cout << arr[0][0] << "\n";
        return;
    }

    const size_t min = std::min(rows, cols);

    size_t low = 0;
    // black magic to figure out how many spiral iterations to get to center
    size_t high = min / 2 + min % 2;

    const size_t colsEnd = cols - 1;
    const size_t rowsEnd = rows - 1;
    while (low < high) {
        for (size_t i = low; i < colsEnd - low; i++) {
            std::cout << arr[low][i] << " ";
        }

        for (size_t i = low; i < rowsEnd - low; i++) {
            std::cout << arr[i][colsEnd - low] << " ";
        }

        for (int i = colsEnd - low; i > low; i--) {
            std::cout << arr[rowsEnd - low][i] << " ";
        }

        for (int i = rowsEnd - low; i > low; i--) {
            std::cout << arr[i][low] << " ";
        }

        low++;
    }

    // weird edge case to handle that last digit in the center of a spiral
    // really should improve on this convoluted mess
    const size_t backLow = low - 1;
    if (backLow == colsEnd - backLow && backLow == rowsEnd - backLow) {
        std::cout << arr[backLow][backLow] << " ";
    }
    std::cout << "\n";
}

int main()
{

    int myArray[][4] = { { 1, 2, 3, 4 }, { 12, 13, 14, 5 }, { 11, 16, 15, 6 }, { 10, 9, 8, 7 } };
    int myArray2[][4] = { { 1, 2, 3, 4 }, { 8, 7, 6, 5 } };
    int myArray3[][1] = { { 1 }, { 2 } };
    int myArray4[][1] = { { 1 } };
    int myArray5[][5] = { { 1, 2, 3, 4, 5 }, { 16, 17, 18, 19, 6 }, { 15, 24, 25, 20, 7 }, { 14, 23, 22, 21, 8 }, { 13, 12, 11, 10, 9 } };
    int myArray6[][5] = { { 1, 2, 3, 4, 5 }, { 14, 15, 16, 17, 6 }, { 13, 20, 19, 18, 7 }, { 12, 11, 10, 9, 8 } };
    int myArray7[][4] = { { 1, 2, 3, 4 }, { 14, 15, 16, 5 }, { 13, 20, 17, 6 }, { 12, 19, 18, 7 }, { 11, 10, 9, 8 } };

    printSpiral(myArray);
    printSpiral(myArray2);
    printSpiral(myArray3);
    printSpiral(myArray4);
    printSpiral(myArray5);
    printSpiral(myArray6);
    printSpiral(myArray7);

    return 0;
}
