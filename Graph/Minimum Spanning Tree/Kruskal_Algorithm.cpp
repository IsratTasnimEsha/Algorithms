// Bismillahir Rahmanir Rahim

//kruskal

#include <bits/stdc++.h>
using namespace std;

/*
10 16
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

int findParent(int v, int *parent)
{
    if (parent[v] == v)
        return v;
    findParent(parent[v], parent);
}

int main()
{
    int v, e;
    cin >> v >> e;
    multimap<int, pair<int, int>> g;

    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g.insert(make_pair(w, make_pair(x, y)));
    }
    
    cout << "MST: " << endl;

    int parent[v];
    for (int i = 1; i <= v; i++)
        parent[i] = i;

    int cnt = 0;
    for (auto i : g)
    {

        int x = findParent(i.second.first, parent);
        int y = findParent(i.second.second, parent);

        if (x != y)
        {
            cout << i.second.first << " " << i.second.second << " " << i.first << endl;
            cnt++;
            parent[x] = y;
        }

        if (cnt == v - 1)
            break;
    }
}