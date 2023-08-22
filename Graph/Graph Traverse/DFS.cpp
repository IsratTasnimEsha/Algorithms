// bismillahir rahmanir rahim

//dfs

#include <bits/stdc++.h>
using namespace std;

/*
6 5
1 2
1 3
3 4
3 5
5 6
*/

vector<list<int>> adj(100, list<int>(100));
vector<int> visited(100);

void DFS(int src)
{
    visited[src] = 1;
    cout << src << " ";

    for (auto i: adj[src])
        if (!visited[i] && i != 0)
            DFS(i);
}

int main()
{
    int edge=6, vertex=6, src=5;

    for (int i = 0; i < edge; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    DFS(src);

    for (int i = 1; i <= vertex; i++)
        if (visited[i] != 1)
            ;//cout << i << " ";
}