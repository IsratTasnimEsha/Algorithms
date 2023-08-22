// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

int subset[100][100];
int main()
{
    int n = 6;
    int a[]={2, 1, 9, 6, 7, 3};
    int m = 21;

    for (int i = 0; i < n; i++)
        subset[i][0] = 1;

    subset[0][a[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            subset[i][j] = subset[i - 1][j] || subset[i - 1][j - a[i]];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << subset[i][j] << " ";
        }
        cout << endl;
    }

    if (!subset[n - 1][m])
        cout << "No ans available" << endl;

    else
    {
        int p = n;
        while (m)
        {
            for (int i = 0; i < p; i++)
            {
                if (subset[i][m]!=0)
                {
                    p = i;
                    m -= a[i];
                }
            }
            cout << a[p] << " ";
        }
    }
}