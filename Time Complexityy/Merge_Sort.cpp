#include <bits/stdc++.h>
using namespace std;

int cnt=0;

void _merge(int a[], int p, int q, int rr)
{
    int n1 = q - p + 1;
    cnt++; //n1
    int n2 = rr - q;
    cnt++; //n2
    int l[n1], r[n2], i=0, j=0;
    cnt+=2; //i=0, j=0

    for (; i < n1; i++)
    {
        cnt+=2; //i<n1, i++
        l[i] = a[i + p];
        cnt+=2; //l[i] = a[i+p], a[i + p]
    }
    cnt++; // loop extra 1 condition check

    for (; j < n2; j++)
    {
        cnt+=2; //i<n1, i++
        r[j] = a[j + (q + 1)];
        cnt+=2; //a[j+(q+10], r[i] = a[j + (q+1)]
    }
    cnt++; // loop extra 1 condition check

    i = 0, j = 0;
    cnt+=2; //i = 0, j = 0

    int k=p;
    cnt++; //k=p
    for (; i < n1 && j < n2; k++)
    {
        cnt+=4; // i < n1, j < n2, i < n1 && j < n2, k++
        if (l[i] < r[j])
        {
            cnt++; //l[i]<r[j]
            a[k] = l[i++];
            cnt+=2; //i++, a[k]=l[i++]
        }

        else
        {
            cnt++; ////l[i]>=r[j]
            a[k] = r[j++];
            cnt+=2; // j++, a[k]=l[j++]
        }
    }
    cnt++; // loop extra 1 condition check

    while (i < n1)
    {
        cnt++; //i<n1
        a[k++] = l[i++];
        cnt+=3; //k++, i++, a[k++]=l[i++]
    }

    while (j < n2)
    {
        cnt++; //j<n2
        a[k++] = r[j++];
        cnt+=3; //k++, i++, a[k++]=r[j++]
    }
}

void mergeSort(int a[], int p, int r)
{
    int q;

    if (p < r)
    {
        cnt++; //p<r
        q = (p + r) / 2;
        cnt++; //q
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        _merge(a, p, q, r);
    }
}

int main()
{
    int n = 2;
    int a[] = {9, 1};

    mergeSort(a, 0, n - 1);
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    
    cout<<endl<<cnt<<endl;
}