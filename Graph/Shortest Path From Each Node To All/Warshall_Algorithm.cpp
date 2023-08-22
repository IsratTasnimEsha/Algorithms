// bismillahir rahmanir rahim

//warshall

#include <bits/stdc++.h>
using namespace std;

/*
1 2 5
1 1 7
2 1 7
2 4 2
3 2 3
4 3 1
4 1 4
*/

int main()
{
    int v = 4, e = 7;
    int g[v + 1][v + 1];
    string p[v + 1][v + 1];

    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            p[i][j] = "", g[i][j] = INT_MAX;

    for (int i = 1; i <= e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g[x][y] = w;
        p[x][y] += x + '0';
        p[x][y] += '-';
        p[x][y] += y + '0';
    }

    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                if (g[i][k] != INT_MAX && g[k][j] != INT_MAX && g[i][k] + g[k][j] < g[i][j])
                {
                    g[i][j] = g[i][k] + g[k][j];

                    string s;
                    for (int l = 1; l < p[k][j].size(); l++)
                        s += p[k][j][l];
                    p[i][j] = p[i][k] + s;
                }

    cout << endl
         << "Shortest Path:" << endl;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
            cout << g[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    cout << endl
         << "Path:" << endl;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
            cout << p[i][j] << "\t\t";
        cout << endl;
    }
    cout << endl;
}