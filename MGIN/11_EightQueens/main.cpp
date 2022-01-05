#include <QCoreApplication>
#include <iostream>

using namespace std;

#define DIM 8

void show(int board[DIM][DIM])
{
    for (int y = 0; y < DIM; y++)
    {
        for (int x = 0; x < DIM; x++)
        {
            // Cell is empty
            if (board[y][x] == 0)
            {
                cout << " . ";
            }
            else
            {
                cout << " " << board[y][x] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// check is given y,x is valid queen placement
bool isValid(int board[DIM][DIM], int y, int x)
{
    // check horizontal
    for (int i = 0; i < DIM; i++)
    {
        if (board[y][i] != 0)
        {
            return false;
        }
    }
    // check vertical
    for (int i = 0; i < DIM; i++)
    {
        if (board[i][x] != 0)
        {
            return false;
        }
    }
    // check diagonally right down
    for (int i = 0; (y + i) < DIM && (x + 1) < DIM; i++)
    {
        if (board[y + i][x + i] != 0)
        {
            return false;
        }
    }
    // check diagonally right up
    for (int i = 0; (y - i) >= 0 && (x + 1) < DIM; i++)
    {
        if (board[y - i][x + i] != 0)
        {
            return false;
        }
    }
    // check diagonally left down
    for (int i = 0; (y + i) < DIM && (x - 1) >= 0; i++)
    {
        if (board[y + i][x - i] != 0)
        {
            return false;
        }
    }
    // check diagonally left up
    for (int i = 0; (y - i) >= 0 && (x - 1) >= 0; i++)
    {
        if (board[y - i][x - i] != 0)
        {
            return false;
        }
    }

    // Placement is valid
    return true;
}

// 1 = Solved
// 0 = Not possible
int solve(int board[DIM][DIM], int numQueen)
{
    show(board);
    if (numQueen > DIM)
    {
        return 1;
    }
    for (int y = 0; y < DIM; y++)
    {
        // (board, y, x)
        if (isValid(board, y, numQueen - 1))
        {
            // Placement is valid, place queen
            board[y][numQueen - 1] = numQueen;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int board[DIM][DIM] = {{0}};

    show(board);

    solve(board, 1);

    show(board);

    return 0;
}
