#include <iostream>

const int ROWS = 3;
const int COLS = 3;

void processArray(int (&arr)[ROWS][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int myArray[ROWS][COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    processArray(myArray, ROWS);

    return 0;
}
