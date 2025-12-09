#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>
void clear_screen_fast() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {0, 0};
    SetConsoleCursorPosition(h, pos);
}

int main() {
    system("color 4F");
    srand(time(0));

RESTART_GAME:
    PlaySound(TEXT("bg.wav"), NULL, SND_ASYNC | SND_LOOP);

    int x = 1;
    int step = 0;
    int obstaclePos = rand() % 3;

    int score = 0;
    int lives = 3;

    while (1) {
        if (_kbhit()) {
            char ch = getch();

            if (ch == 75 && x > 0)    x--;     // left
            if (ch == 77 && x < 2)    x++;
        }
        clear_screen_fast();

        printf("|--- GAME ---|\n");
        printf("Score: %d   Lives: %d\n\n", score, lives);
        for (int i = 0; i < 10; i++) {
            if (i == step) {
                if (obstaclePos == 0)
                    printf("| %c        |\n", 1);
                else if (obstaclePos == 1)
                    printf("|     %c    |\n", 1);
                else if (obstaclePos == 2)
                    printf("|        %c |\n", 1);
            } 
            else {
                printf("|           |\n");
            }
        }
        if (x == 0)
            printf("| %c         |\n", 6);
        else if (x == 1)
            printf("|     %c     |\n", 6);
        else if (x == 2)
            printf("|        %c  |\n", 6);
        if (step == 10 && x == obstaclePos) {

            lives--;
            PlaySound(NULL, NULL, 0);
            PlaySound(TEXT("impact.wav"), NULL, SND_ASYNC);
            Sleep(1000);

            if (lives == 0) {
                printf("\n\nGAME OVER!\n");
                printf("Final Score: %d\n", score);
                printf("\nPress R to Restart or Q to Quit.\n");
                while (1) {
                    char ch = getch();
                    if (ch == 'r' || ch == 'R') {
                        clear_screen_fast();
                        goto RESTART_GAME;
                    }
                    if (ch == 'q' || ch == 'Q') {
                        return 0;
                    }
                }
            }
            step = 0;
            obstaclePos = rand() % 3;
        }

        Sleep(120);
        step++;
        if (step > 10){
            score++;
            step = 0;
            obstaclePos = rand() % 3;
        }
    }

    return 0;
}
