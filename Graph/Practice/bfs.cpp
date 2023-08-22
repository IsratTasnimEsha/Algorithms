// bismillahir rahmanir rahim

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

int g[100][100];
int main()
{
    int v=6, e=9, src=5;

    for(int i=1; i<=e; i++)
    {
        int x, y;
        cin>>x>>y;
        g[x][y]=1;
        g[y][x]=1;
    }
    bool visited[100];
    for(int i=1; i<=v; i++) visited[i]=false;
    
    list<int>que;
    que.push_back(src);
    visited[src]=true;

    while(!que.empty())
    {
        int u=que.front();
        cout<<u<<" ";
        que.pop_front();

        for(int i=1; i<=v; i++)
        {
            if(g[u][i]!=0 && !visited[i])
            {
                que.push_back(i);
                visited[i]=true;
            }
        }
    }
    for(auto i: que) cout<<i<<" ";
}