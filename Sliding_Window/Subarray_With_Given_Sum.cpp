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
        sumMap[sum] = i;
    }

    for (int i = 0; i < n; i++) {
        int target = sum + k;
        if (sumMap.find(target) != sumMap.end() && sumMap[target] > i) {
            cout << "Indices: " << i + 1 << " " << sumMap[target] << endl;
        }
    }

    return 0;
}
