#include <bits/stdc++.h>
using namespace std;

int main()
{
    int prof[] = {1, 2, 5, 6};
    int wt[] = {2, 3, 4, 5};
    int W = 8;
    int n = sizeof(prof) / sizeof(prof[0]);

    int dp[100][100];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (wt[i - 1] <= w)
                dp[i][w] = max(prof[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);

            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    if (!dp[n][W])
        cout << "No ans available" << endl;

    else
    {
        int i = n;
        while (i >= 1)
        {
            if (dp[i][W] == dp[i - 1][W])
                i--;

            else
            {
                cout << wt[i - 1] << " ";
                W -= wt[i - 1];
            }
        }
    }
}