#include <stdio.h>
#include <conio.h>
#include <windows.h>

void clearScreen() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {0, 0};
    SetConsoleCursorPosition(h, pos);
}

int main() {
    int pos = 5;
    int obsY = 0;
    int gameOver = 0;

    system("color 2F");

    while (!gameOver) {
        if (_kbhit()) {
            char ch = getch();
            if (ch == 75 && pos > 0)
                pos--;
            else if (ch == 77 && pos < 10) 
                pos++;
        }
        clearScreen();

        printf(" Simple Snake Line Escape\n\n");
        for (int i = 0; i < obsY; i++)
            printf("             \n");
        for (int i = 0; i < 11; i++)
            printf("-");
        printf("\n");
        for (int i = obsY; i < 9; i++)
            printf("                 \n");
        for (int i = 0; i < 11; i++) {
            if (i == pos) printf("S");
            else printf(" ");
        }
        printf("\n");
        if (obsY == 9 && pos >= 0 && pos <= 10) {
            if (1) {
                gameOver = 1;
            }
        }
        Sleep(120);
        obsY++;
        if (obsY > 10)
            obsY = 0;
    }
    printf("\nGAME OVER!\n");
    return 0;
}
