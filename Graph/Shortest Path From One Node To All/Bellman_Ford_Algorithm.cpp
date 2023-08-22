// bismillahir rahmanir rahim

//bellman

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
    int v, e, s = 2;
    cin>>v>>e;
    int dist[v + 1], src[e + 1], dest[e + 1], wt[e + 1];

    for (int i = 1; i <= e; i++)
        cin >> src[i] >> dest[i] >> wt[i];

    for (int i = 1; i <= v; i++)
        dist[i] = INT_MAX;
    dist[s] = 0;
    cout << endl;

    int src_ind[v + 1];
    for (int i = 1; i <= v; i++)
        src_ind[dest[i]] = src[i];
    src_ind[s] = 0;

    for (int i = 1; i <= v - 1; i++)
        for (int j = 1; j <= e; j++)
            if (dist[src[j]] != INT_MAX && dist[src[j]] + wt[j] < dist[dest[j]])
            {
                dist[dest[j]] = dist[src[j]] + wt[j];
                src_ind[dest[j]] = src[j];
            }

    for (int i = 1; i <= e; i++)
        if (dist[src[i]] != INT_MAX && dist[src[i]] + wt[i] < dist[dest[i]])
        {
            cout << "Negative weight cycle" << endl;
            return 0;
        }

    // for (int i = 1; i <= v; i++)
    // cout << src_ind[i] << " " << i << endl;

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
        cout << c << "\t" << dist[c] << "\t";

        for (int j = i.second.size() - 1; j >= 0; j--)
            cout << i.second[j] << " ";

        if (c != s && dist[c] != INT_MAX)
            cout << i.first;
        cout << endl;
    }
}