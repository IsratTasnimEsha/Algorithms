// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dl double
#define st string
#define ch char

ll cnt=0;

void Insertion_Sort(ll a[], ll n)
{
    cnt++; //i=1
    for(ll i=1; i<n; i++)
    {
        cnt+=2; //i<n, i++

        ll m=a[i], j=i-1;
        cnt+=2; //m=a[i], j=i-1
        
        while (j>=0 && a[j]>m)
        {
            cnt+=3; //j>=0, a[j]>m, j>=0 && a[j]>m
            
            a[j+1]=a[j];
            cnt++; //a[j+1]=a[j]
            
            j--;
            cnt++; //j--
        }
        cnt+=3; //extra condition check
        
        a[j+1]=m;
        cnt++; //a[j+1]=m
    }
    cnt++; //extra condition check
}

int main()
{
    ll a[] = {2, 1};
    ll n = sizeof(a) / sizeof(ll);

    Insertion_Sort(a, n);

    for (ll i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
    cout<<cnt<<endl;
}