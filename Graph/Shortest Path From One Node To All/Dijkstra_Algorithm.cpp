// bismillahir rahmanir rahim

//dijkstra

#include <bits/stdc++.h>
using namespace std;

/*
1 2 50
1 3 45
1 4 10
2 4 15
2 3 10
3 5 30
4 5 15
5 2 20
5 3 35
*/

int main()
{
    int v = 6, e = 9;
    int g[v + 1][v + 1];

    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            g[i][j] = 0;

    for (int i = 1; i <= e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g[x][y] = w;
    }

    int src = 2;
    bool visited[v + 1];
    int dist[v + 1];

    for (int i = 1; i <= v; i++)
        visited[i] = false, dist[i] = INT_MAX;
    dist[src] = 0;

    int src_ind[v + 1];
    src_ind[src] = 0;

    for (int i = 1; i <= v - 1; i++)
    {
        int min_value = INT_MAX, min_ind;
        for (int j = 1; j <= v; j++)
            if (dist[j] <= min_value && !visited[j])
                min_value = dist[j], min_ind = j;

        visited[min_ind] = true;

        for (int j = 1; j <= v; j++)
            if (g[min_ind][j] && !visited[j] && dist[min_ind] != INT_MAX && dist[j] > dist[min_ind] + g[min_ind][j])
            {
                dist[j] = dist[min_ind] + g[min_ind][j];
                src_ind[j] = min_ind;
            }
    }

    map<int, vector<int>> path;
    path[src].push_back(src);

    for (int i = 1; i <= v; i++)
    {
        if (dist[i] != INT_MAX)
        {
            int j = i;
            while (j != src)
            {
                path[i].push_back(src_ind[j]);
                j = src_ind[j];
            }
        }
        else
            path[i].push_back(0);
    }

    int c = 0;
    for (auto i : path)
    {
        c++;
        cout << c << "\t" << dist[c] << "\t";

        for (int j = i.second.size() - 1; j >= 0; j--)
            cout << i.second[j] << " ";

        if (c != src && dist[c] != INT_MAX)
            cout << i.first;
        cout << endl;
    }
}