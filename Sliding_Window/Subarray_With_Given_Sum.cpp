//Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int main()
{ 
    int n = 10, k = -4;
    vector<int> a = {-2, 1, 7, -12, 3, -2, 4, 2, 7, -1};
    unordered_map<int, int> sumMap;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sumMap.find(sum - k) != sumMap.end()) {
            cout << "Indices: " << sumMap[sum - k] + 1 << " " << i + 1 << endl;
        }
        sumMap[sum] = i;
    }

    return 0;
}
