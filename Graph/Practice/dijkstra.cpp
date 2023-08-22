// Bismillahir Rahmanir Rahiim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
    bool visited[v+1];
    int dist[v+1];
    for(int i=1; i<=v; i++) visited[i]=false, dist[i]=INT_MAX;
    int s=2;
    dist[s]=0;
    int src_ind[v+1];
    for(int i=1; i<=v-1; i++)
    {
        int min_ind, minn=INT_MAX;
        for(int j=1; j<=v; j++)
            if(!visited[j] && dist[j]<=minn) minn=dist[j], min_ind=j;
        
        visited[min_ind]=true;
        
        for(int j=1; j<=v; j++)
        {
            if(!visited[j] && g[min_ind][j] && dist[min_ind]!=INT_MAX && dist[j]>dist[min_ind]+g[min_ind][j]) 
            {
                dist[j]=dist[min_ind]+g[min_ind][j];
                src_ind[j]=min_ind;
            }          
        }
    }
    for(int i=1; i<=v; i++)
    {
        if(dist[i]!=INT_MAX)
        {
            int j=i;
            while (j!=s)
            {
                cout<<src_ind[j];
                j=src_ind[j];
            }
        }
        else cout<<0;
        cout<<endl;
    }
}