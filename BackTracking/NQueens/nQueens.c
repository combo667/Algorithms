#include <stdio.h>
#include <stdlib.h>
#define max 20

void print_Solution(int);
void N_Queen(int, int);
int Can_be_placed(int, int, int);
void print_MATRIX(int);

int Solution[max] = {0};

int main(int argc, char const *argv[])
{

    auto int chess_board_size = 0;
    printf("Input the chess board Size!\n");
    scanf("%d", &chess_board_size);

    (chess_board_size == 2 || chess_board_size == 3) ? printf("No Solution Available!\n") : N_Queen(1, chess_board_size);

    return 0;
}

int Can_be_placed(int Queen, int col, int size)
{
    int i;
    for (i = 1; i <= Queen - 1; i++)
    {
        if (Solution[i] == col || (abs(Solution[i] - col) == abs(i - Queen)))
            return 0;
    }

    return 1;
}

void print_Solution(int size)
{
    static int solution = 1;
    printf("\n\nSOLUTION %d IS:\n", solution++);
    printf("The %d tuple solution is :  ", size);
    printf("( ");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", Solution[i]);
    }
    printf(" )");
    printf("\n\n");
}

void N_Queen(int Queen, int chess_board_size)
{
    int i;

    for (i = 1; i <= chess_board_size; i++)
    {
        if (Can_be_placed(Queen, i, chess_board_size))
        {
            Solution[Queen] = i;
            if (Queen == chess_board_size)
            {
                print_Solution(chess_board_size);
                print_MATRIX(chess_board_size);
            }
            else
                N_Queen(Queen + 1, chess_board_size);
        }
    }
}

void print_MATRIX(int size)
{
    auto int row = 0, col = 0;

    for (col = 1; col <= size; col++)
    {
        printf("\t%d", col);
    }

    for (row = 1; row <= size; row++)
    {
        printf("\n\n%d", row);

        for (col = 1; col <= size; col++)
        {
            Solution[row] == col ? printf("\tQ") : printf("\t_");
        }
    }
}
