// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

/*
5 8
1 2 -1
1 3 4
2 3 3
2 4 2
2 5 2
4 3 5
4 2 1
5 4 -3
*/

int main()
{   
    int v, e, s = 6;
    cin >> v >> e;
    int dist[v + 2], src[e + v + 1], dest[e + v + 1], wt[e + v + 1];

    for (int i = 1; i <= e; i++)
        cin >> src[i] >> dest[i] >> wt[i];

    for (int i = 1; i <= v; i++)
    {
        src[e + i] = v + 1;
        dest[e + i] = i;
        wt[e + i] = 0;
    }

    e = e + v;
    v++;

    //Bellmanford Algorithm

    for (int i = 1; i <= v; i++)
        dist[i] = INT_MAX;
    dist[s] = 0;

    for (int i = 1; i <= v - 1; i++)
        for (int j = 1; j <= e; j++)
            if (dist[src[j]] != INT_MAX && dist[src[j]] + wt[j] < dist[dest[j]])
            {
                dist[dest[j]] = dist[src[j]] + wt[j];
            }

    for (int i = 1; i <= e; i++)
        if (dist[src[i]] != INT_MAX && dist[src[i]] + wt[i] < dist[dest[i]])
        {
            cout << "Negative weight cycle" << endl;
            return 0;
        }

    v--;
    e = e - v;

    int h[v + 1];
    for (int i = 1; i <= v; i++)
        h[i] = dist[i], cout << h[i] << endl;

    for (int i = 1; i <= e; i++)
        wt[i] = wt[i] + h[src[i]] - h[dest[i]];

    for (int k = 1; k <= v; k++)
    {
        //Dijkstra Algorithm

        cout << "From node " << k << " to all nodes: " << endl;
        s = k;
        int g[v + 1][v + 1];

        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                g[i][j] = INT_MAX;

        for (int i = 1; i <= e; i++)
            g[src[i]][dest[i]] = wt[i];

        bool visited[v + 1];

        for (int i = 1; i <= v; i++)
            visited[i] = false, dist[i] = INT_MAX;
        dist[s] = 0;

        int src_ind[v + 1];
        src_ind[s] = 0;

        for (int i = 1; i <= v - 1; i++)
        {
            int min_value = INT_MAX, min_ind;
            for (int j = 1; j <= v; j++)
                if (dist[j] <= min_value && !visited[j])
                    min_value = dist[j], min_ind = j;

            visited[min_ind] = true;

            for (int j = 1; j <= v; j++)
                if (g[min_ind][j] != INT_MAX && !visited[j] && dist[min_ind] != INT_MAX && dist[j] > dist[min_ind] + g[min_ind][j])
                {
                    dist[j] = dist[min_ind] + g[min_ind][j];
                    src_ind[j] = min_ind;
                }
        }

        map<int, vector<int>> path;
        path[s].push_back(s);

        for (int i = 1; i <= v; i++)
        {
            if (dist[i] != INT_MAX)
            {
                int j = i;
                while (j != s)
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
            cout << c << "\t" << dist[c] + h[c] - h[k] << "\t";

            for (int j = i.second.size() - 1; j >= 0; j--)
                cout << i.second[j] << " ";

            if (c != s && dist[c] != INT_MAX)
                cout << i.first;
            cout << endl;
        }
    }
}