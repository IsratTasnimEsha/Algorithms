// bismillahir rahmanir rahim

//bfs

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dl double
#define st string
#define ch char

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

int main()
{
    map<int, vector<int>> adj;

    for (int i = 0; i < 9; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    
    cout << "Adjacency List" << endl;
    for (auto i : adj)
    {
        cout << i.first << "--> ";
        for (auto j : i.second)
            cout << j << " ";
        cout << endl;
    }

    list<int>bfs;
    vector<int>visited(7);
    
    int src=5;
    visited[src]=1;
    bfs.push_back(src);

    cout<<"BFS  ";
    while(!bfs.empty())
    {
        src=bfs.front();
        cout<<src<<" ";
        bfs.pop_front();
        
        for(auto i:adj[src])
        {
            if(!visited[i])
            {
                visited[i]=1;
                bfs.push_back(i);
            }
        }
    }
}