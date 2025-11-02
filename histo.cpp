#include <bits/stdc++.h>
using namespace std;

int getArea(vector<int>& arr) {
    int n = arr.size();
    int res = 0;

    // Consider every bar one by one
    for (int i = 0; i < n; i++) {
        int curr = arr[i];

        // Traverse left while we have a greater height bar
        for (int j = i - 1; j >= 0 && arr[j] >= arr[i]; j--) {
            curr += arr[i];
        }

        // Traverse right while we have a greater height bar
        for (int j = i + 1; j < n && arr[j] >= arr[i]; j++) {
            curr += arr[i];
        }

        res = max(res, curr);
    }
    return res;
}

int main() {
    
    vector<int> arr;
    
    int n;
    cin >> n;
    
    
    int x;
    
    
    while(cin >> x){
        arr.push_back(x);
    }


    cout << getArea(arr) << endl;

    return 0;
}