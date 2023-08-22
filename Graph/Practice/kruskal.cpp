// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

/*
2 10 10
3 5 2
6 7 3
6 9 5
3 6 1
4 8 5
7 9 3
7 10 4
4 10 6
5 7 2
8 10 2
9 10 3
2 3 4
2 4 4
1 2 4
1 4 1
*/

int findP(int *p, int v)
{
    if(v==p[v]) return v;
    findP(p, p[v]);
}

int main()
{
    int v=10, e=16;
    multimap<int, pair<int, int>>g;
    for(int i=1; i<=e; i++)
    {
        int x, y, w;
        cin>>x>>y>>w;
        g.insert(make_pair(w, make_pair(x, y)));
    }
    cout<<endl;
    int p[100], c=0;
    for(int i=1; i<=v; i++) p[i]=i;
    for(auto i:g)
    {
        int x=findP(p, i.second.first);
        int y=findP(p, i.second.second);

        if(x!=y)
        {
            cout<<i.second.first<<" "<<i.second.second<<" "<<i.first<<endl;
            c++;
            p[x]=y;
        }

        if(c==v-1) break;
    }
}