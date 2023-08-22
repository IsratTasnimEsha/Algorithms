// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dl double
#define st string
#define ch char

ll node = 6, edge = 9;
ll graph[7][7];

/*
Undirected Graph
1 3 4
1 4 3
3 5 2
3 4 7
3 6 8
3 2 9
2 6 1
4 6 2
5 6 3
*/
int main()
{
    for (int i = 0; i < edge; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1][v2] = wt;
        graph[v2][v1] = wt;
    }

    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
}