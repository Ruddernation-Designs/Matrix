#include <iostream>
#include <vector>

#include "Matrix.h"

int main() {

    RemoveCursor();

    // Set the console title and double the consoles height
    #if (_WIN32_WINNT == _WIN32_WINNT_WINXP)
        if (!SetConsoleTitle("Matrix - Win32 Console")) {
            std::cout << "SetConsoleTitle returned an error: " << GetLastError();
        }

        SMALL_RECT windowSize = { 0, 0, 79, 49 };
        if (!SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize)) {
            std::cout << "SetConsoleWindowInfo returned an error: " << GetLastError();
        }
    #else
        // Windows Vista/7 have disabled FULL SCREEN
        ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    #endif


    std::vector<Matrix>matrix;
/*
    matrix.push_back(Matrix(0, 0, 5, 15));
    matrix.push_back(Matrix(65, 0, 5, 15));
    matrix.push_back(Matrix(0, 0, 5, 15));
    matrix.push_back(Matrix(65, 0, 5, 15));

    matrix.push_back(Matrix(0, 0, 5, 15));  matrix.back().setErase(true);
    matrix.push_back(Matrix(65, 0, 5, 15)); matrix.back().setErase(true);
    matrix.push_back(Matrix(0, 0, 5, 15));  matrix.back().setErase(true);
    matrix.push_back(Matrix(65, 0, 5, 15)); matrix.back().setErase(true);
*/

    for (int y = 0; y < 15; y++) {
        matrix.push_back(Matrix());
    }

    for (int z = 0; z < 5; z++) {
        matrix.push_back(Matrix()); matrix.at(z).setErase(true);
    }

    while (1) {
        Sleep(1);

        for (int x = 0; x < matrix.size(); x++) {
            matrix.at(x).display();
        }
    }

    return 0;
}
