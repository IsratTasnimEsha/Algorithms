// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

#define n 4
int board[n][n];

bool safe(int row, int col)
{
    for (int i = 0; i <= col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; i < n && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool check(int col)
{
    if (col == n)
        return true;

    for (int i = 0; i < n; i++)
        if (safe(i, col))
        {
            board[i][col] = 1;

            if (check(col + 1))
                return true;
            else
                board[i][col] = 0;
        }

    return false;
}

int main()
{
    check(0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";

        cout << endl;
    }
}