// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dl double
#define st string
#define ch char

ll cnt = 0;

void Selection_Sort(ll a[], ll n)
{
    ll temp;
    cnt++; // temp
    ll min_index;
    cnt++; // index

    cnt += 1; // i=0
    for (ll i = 0; i < n - 1; i++)
    {
        cnt += 2; // i<n-1, i++
        min_index = i;
        cnt += 1; // min_index
        cnt += 1; // j=i+1
        for (ll j = i + 1; j < n; j++)
        {
            cnt += 2; // j<n, j++
            cnt += 3; // a[j], a[min_index], if(a[j]<a[min_index])
            if (a[j] < a[min_index])
            {
                min_index = j;
                cnt++; // min_index = j
            }
        }
        temp = a[i];
        cnt += 2; // a[i], temp=a[i]
        a[i] = a[min_index];
        cnt += 2; // a[min_index], a[i]=a[min_index]
        a[min_index] = temp;
        cnt += 2; // a[min_index]=temp
    }
    cnt += 2; // 2 loops (extra 1 condition check)
}

int main()
{
    ll a[] = {9, 8};
    ll n = sizeof(a) / sizeof(ll);

    Selection_Sort(a, n);

    for (ll i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl
         << cnt << endl;
}