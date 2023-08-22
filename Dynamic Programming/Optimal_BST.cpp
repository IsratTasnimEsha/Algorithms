// bismillahir rahmanir rahiim

#include <bits/stdc++.h>
using namespace std;

int key[100], freq[100];
int C[100][100], parent[100][100] = {0};

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the keys: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> key[i];
    }
    cout << "Enter the frequencies: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> freq[i];
    }
    for (int v = 1; v <= n; v++)
    {
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j <= n + 1; j++)
            {
                if ((j - i) == v)
                {
                    int z = 1;
                    int w = 0;
                    for (int s = i + 1; s <= j; s++)
                    {
                        w += freq[s];
                    }
                    for (int k = i + 1; k <= j; k++)
                    {
                        int r = C[i][k - 1] + C[k][j] + w;
                        if (z == 1)
                        {
                            z = 0;
                            C[i][j] = r;
                            parent[i][j] = k;
                        }
                        else if (C[i][j] > r)
                        {
                            C[i][j] = r;
                            parent[i][j] = k;
                        }
                    }
                }
            }
        }
    }
    cout << "Cost table: " << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << C[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "Parent table: " << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << parent[i][j] << "\t";
        }
        cout << "\n";
    }
}