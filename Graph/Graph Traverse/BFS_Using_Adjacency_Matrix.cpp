// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

/*
Undirected Graph
1 3
1 4
3 5
3 4
3 6
3 2
2 6
4 6
5 6
*/

int adj[7][7] = {0};
int main()
{
    int ver[7];
    for(int i=1; i<=6; i++) ver[i]=i;

    for (int i = 0; i < 9; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;
    }

    cout << "Adjacency Matrix" << endl;
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    
    list<int>bfs;
    vector<int>visited(7);

    int src=5;
    visited[src]=1;
    bfs.push_back(src);

    cout<<"BFS  ";
    while (!bfs.empty())
    {
        src=bfs.front();
        cout<<src<<" ";
        bfs.pop_front();

        for(int i=1; i<=6; i++)
        {
            if(adj[src][i]==1 && !visited[i])
            {
                visited[i]=1;
                bfs.push_back(i);
            }
        }
    }
}