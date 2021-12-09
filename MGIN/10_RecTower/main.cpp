#include <QCoreApplication>
#include <iostream>

using namespace std;

#define MAXNUM 10

int stick[3][MAXNUM] = {{0}};

void init() {
    for (int y = 0; y < MAXNUM; y++)
    {
        stick[0][y] = y + 1;
    }
}

void show()
{
    for (int y = 0; y < MAXNUM; y++)
    {
        cout << " ";
        for (int s = 0; s <3 ; s++)
        {
            for (int i = 0; i < (MAXNUM - stick[s][y]); i++)
            {
                cout << " ";
            }
            for (int i = 0; i < (stick[s][y]); i++)
            {
                cout << "x";
            }

            cout << "|";

            for (int i = 0; i < (stick[s][y]); i++)
            {
                cout << "x";
            }
            for (int i = 0; i < (MAXNUM - stick[s][y]); i++)
            {
                cout << " ";
            }

            cout << " ";
        }
        cout << endl;
    }
    for ( int i  = 0; i < (MAXNUM*3*2+3+2); i++)
    {
        cout << "=";
    }
    cout << "\n" << endl;
}

void solve(int from, int to, int res, int num)
{
    if (num == 1) {
        show();
        // Find highest empty slot
        int i;
        for (i = 0; stick[from][i] == 0; i++);

        int pick = stick[from][i];
        stick[from][i] = 0;

        for (i = 0; (stick[to][i] == 0) && (i < MAXNUM); i++);
        i--;
        stick[to][i] = pick;
        return;
    }
    solve(from, res, to, num-1);
    solve(from, to, res, 1);
    solve(res, to, from, num-1);
}

int main(int argc, char *argv[])
{
    init();

    show();

    solve(0, 1, 2, MAXNUM);

    show();

    return 0;
}
