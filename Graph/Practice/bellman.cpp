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
int src_ind[100];
int e=8, v=5, s=2, src[100], dest[100], wt[100], dist[100];

int main()
{
    for (int i = 1; i <= e; i++)
        cin>>src[i]>>dest[i]>>wt[i];

    for(int i=1; i<=v; i++) dist[i]=9999;
    dist[s]=0;

    for(int i=1; i<=v-1; i++)
        for(int j=1; j<=e; j++)
        {
            if(dist[dest[j]]> dist[src[j]]+wt[j])
            {
                dist[dest[j]]=min(dist[dest[j]], dist[src[j]]+wt[j]);
                src_ind[dest[j]]=src[j];
            }
        }

   
    for(int i=1; i<=v; i++)
    {
        cout<<i<<" ";
        if(dist[i]!=9999)
        {
            int j=i;
            while(j!=s)
            {
                cout<<src_ind[j]<<" ";
                j=src_ind[j];
            }
        }
        else cout<<0<<" ";
        cout<<endl;
    }
    

    //for(int i=1; i<=v; i++) cout<<i<<" "<<dist[i]<<endl;        
}