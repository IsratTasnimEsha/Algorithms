//Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

int mp[20];
int main()
{
    int n=10, k=5, sum=0;
    int a[]={3, 9, -2, 4, 1, -7, 16, 6, 5, -8};

    for(int i=0; i<20; i++) mp[i]=-1;
    
    for(int i=0; i<n; i++)
    {
        sum+=a[i];
        mp[sum]=i;
    }

    for(int i=0; i<20; i++) 
    {
        if(mp[i]==k) cout<<i<<endl;
        else if(mp[i]!=-1 && mp[i+k]!=-1 && mp[i]<mp[i+k]) cout<<mp[i]+1<<"\t:\t"<<mp[i+k]<<endl;
    }
}