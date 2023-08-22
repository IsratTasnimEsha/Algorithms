//Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=10, k=3, sum=0, maxx=0, l=0, p=0;
    int a[]={2, 3, 4, 5, 6, 7, 9, 2, 1, 10};

    for(int i=0; i<k; i++) sum+=a[i];

    for(int i=k; i<n; i++)
    {
        sum+=a[i]-a[l];
        l++;
        if(sum>maxx)
        {
            maxx=sum;
            p=l;
        }
    }

    cout<<maxx<<endl;
    for(int i=p; i<k+p; i++) cout<<a[i]<<" ";
}