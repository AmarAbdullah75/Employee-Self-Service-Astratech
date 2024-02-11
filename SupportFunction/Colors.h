#define WHITE_BACKGROUND (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE)
#define WHITE_TEXT_COLOR (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
#include <windows.h>
BOOL SetConsoleTextAttribute(
        HANDLE hConsoleOutput,
        WORD wAttributes
);

void color(WORD textColor, WORD bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor | bgColor);
}
