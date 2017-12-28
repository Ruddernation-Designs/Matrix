#include "TextControl.h"

void RemoveCursor() {
    
    /* Remove the cursor (does not work in full screen) */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursoInfo;
    CursoInfo.dwSize = 1;         /* The size of caret */
    CursoInfo.bVisible = false;   /* Caret is visible? */
    SetConsoleCursorInfo(hConsole, &CursoInfo);

    return;
}

void SetColor(const int foreground) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, foreground);

    return;
}

void PlaceCursor(const int x, const int y) {
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD PlaceCursorHere;
    PlaceCursorHere.X = x;
    PlaceCursorHere.Y = y;

    SetConsoleCursorPosition(hConsole, PlaceCursorHere);
    return;
}
