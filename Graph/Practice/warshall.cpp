// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

/*
1 2 5
1 1 7
2 1 7
2 4 2
3 2 3
4 3 1
4 1 4
*/

int g[100][100];
int p[100][100];
int main()
{
    int e=7, v=4, s=5;

    for(int i=1; i<=v; i++)
        for(int j=1; j<=v; j++) g[i][j]=9999;

    for (int i = 1; i <= e; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2>>wt;
        g[v1][v2]=wt;
        //g[v2][v1]=wt;
    }

    for(int k=1; k<=v; k++)
        for(int i=1; i<=v; i++)
            for(int j=1; j<=v; j++)
            {
                g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
                p[i][j]=k;  
            }

    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++) cout<<g[i][j]<<" ";
        cout<<endl;
    }        
}