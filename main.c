#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

char grid[9] = 
{
    '1', '2', '3', 
    '4', '5', '6', 
    '7', '8', '9',
};
char markers[2] = { 'X', 'O' };
enum turn { p1 = 0, p2 = 1, start = -1 };
int placed = 0;

void board();
bool draw();
bool win();

int main()
{
    enum turn turn = start;
    bool running = true;
    do
    {
        bool valid = false;
        int square = -1;
        turn = turn == start ? p1 : turn == p1 ? p2 : p1;
        do
        {
            board();
            printf("\nPlayer %d's turn. Pick a square: ", ((int) turn) + 1);
            scanf("%d", &square);
            if (square <= 9 && square >= 1)
            {
                placed++;
                valid = true;
            }
        } while (!valid);

        grid[square - 1] = markers[(int) turn];
        board();
        if (win() == true)
        {
            printf("\nPlayer %d wins!\n", ((int) turn) + 1);
            running = false;
        }
        else if (draw() == true)
        {
            printf("\nDraw!\n");
            running = false;
        }

    } while (running);
    
    return 0;
}

void board()
{
    system("cls");
    printf("Tic Tac Toe\n\n");
    printf("Player 1 [X] - Player 2 [O]\n\n");
    printf(" %c | %c | %c \n", grid[0], grid[1], grid[2]);
    printf("___________\n");
    printf(" %c | %c | %c \n", grid[3], grid[4], grid[5]);
    printf("___________\n");
    printf(" %c | %c | %c \n", grid[6], grid[7], grid[8]);
}

bool draw()
{
    return placed == 9;
}

bool win()
{
    return 
        (grid[0] == grid[1] && grid[1] == grid[2]) ||
        (grid[3] == grid[4] && grid[4] == grid[5]) || 
        (grid[6] == grid[7] && grid[7] == grid[8]) || 
        (grid[0] == grid[3] && grid[3] == grid[6]) || 
        (grid[1] == grid[4] && grid[4] == grid[7]) || 
        (grid[2] == grid[5] && grid[5] == grid[8]) || 
        (grid[6] == grid[4] && grid[4] == grid[2]) || 
        (grid[8] == grid[4] && grid[4] == grid[0]);
}