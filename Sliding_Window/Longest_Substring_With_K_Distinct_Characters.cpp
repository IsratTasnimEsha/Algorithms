//Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

bool isValid(int mp[], int k)
{
    int val=0;
    for(int i=0; i<26; i++)
    {
        if(mp[i]>0) val++;
    }
    if(val<=k) return true;
    else return false;
}

int mp[26];

int main()
{
    string s="abbbcbdbdbbdcdabd";
    int k=2, l=0, u=0, h=-1, msz=1, ml=0;

    for(int i=0; i<s.size(); i++)
    {
        mp[s[i]-'a']++;
        h++;
        while(!isValid(mp, k))
        {
            mp[s[l]-'a']--;
            l++;
        }
        if(h-l+1>msz)
        {
            msz=h-l+1;
            ml=l;
        }
    }
    cout<<s.substr(ml, msz)<<" "<<msz<<endl;
}