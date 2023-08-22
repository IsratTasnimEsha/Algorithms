// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s = 0, minn = 9999;
    vector<int> st, path;
    int g[4][4] = {{0, 10, 15, 20},
                   {5, 0, 9, 10},
                   {6, 13, 0, 12},
                   {8, 8, 9, 0}};

    for (int i = 0; i < 4; i++)
        if (i != s)
            st.push_back(i);

    path.push_back(s + 1);

    while (next_permutation(st.begin(), st.end()))
    {
        int sum = 0, k = s, v[10], l = 0;

        for (int i = 0; i < 10; i++)
            v[i] = 0;

        for (int i = 0; i < st.size(); i++)
        {
            sum += g[k][st[i]];
            k = st[i];
            v[l++] = k + 1;
        }

        sum += g[k][s];

        if (sum < minn)
        {
            for (int i = 0; i < l; i++)
                path.push_back(v[i]);

            minn = sum;

            for (int i = 0; i < 10; i++)
                v[i] = 0;
        }
    }
    
    path.push_back(s + 1);

    cout << "min distance: " << minn << endl
         << "path: ";

    for (auto i : path)
        cout << i << " "; // index from 1
}