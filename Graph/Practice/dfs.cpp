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
bool visited[100]={false, false, false, false, false, false};
int v, e, src;

void dfs(int s)
{
    cout<<s<<" ";
    visited[s]=true;
    for(int i=1; i<=v; i++)
        if(g[s][i] && !visited[i])
            dfs(i);
}

int main()
{
    v=6, e=9, src=5;
    for(int i=1; i<=e; i++)
    {
        int x, y;
        cin>>x>>y;
        g[x][y]=1;
        g[y][x]=1;
    }
    
    int src=2;
    dfs(src);
}