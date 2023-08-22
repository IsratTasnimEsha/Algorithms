// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

/*
4 5
0 1 4
0 2 5
0 3 3
1 3 2
2 3 1
*/

int minKey(int *key, bool *visited, int V)
{
    int minn = INT_MIN, min_ind = 0;

    for (int i = 0; i < V; i++)
        if (visited[i] == false && key[i] > minn)
            minn = key[i], min_ind = i;

    return min_ind;
}
int main()
{
    int V, E;
    cin >> V >> E;
    int graph[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    
    for (int i = 0; i < E; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x][y] = w;
        graph[y][x] = w;
    }
    
    int parent[V], key[V];
    bool visited[V];
    
    for (int i = 0; i < V; i++)
        key[i] = INT_MIN, visited[i] = false;
    key[0] = 0;

    parent[0] = -1;
    for (int i = 0; i < V - 1; i++)
    {
        int u = minKey(key, visited, V);
        visited[u] = true;
        for (int v = 0; v < V; v++)
            if (visited[v] == false && graph[u][v] != 0 && graph[u][v] > key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }
        
    cout << "MST:" << endl;
    for (int i = 1; i < V; i++)
        cout << parent[i] << " " << i << " " << graph[i][parent[i]] << endl;
}