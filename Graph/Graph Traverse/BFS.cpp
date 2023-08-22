// bismillahir rahmanir rahim

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

vector<vector<int>>adj(7, vector<int>(7));
//int adj[7][7];
int cnt[7];

int main()
{
    for (int i = 0; i < 9; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1][cnt[v1]++]=v2;
        adj[v2][cnt[v2]++]=v1;
    }
    
    cout << "Adjacency List" << endl;
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 0; j < 6; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    
    list<int>bfs;
    vector<int>visited(7);

    int src=5;
    visited[src]=1;
    bfs.push_back(src);

    cout<<"BFS:  ";
    while(!bfs.empty())
    {
        src=bfs.front();
        cout<<src<<" ";
        bfs.pop_front();

        for(auto i: adj[src])
        {
            if(!visited[i] && i!=0)
            {
                visited[i]=1;
                bfs.push_back(i);
            }
        }
    }
}