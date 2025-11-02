#include <bits/stdc++.h>
using namespace std;

int binary_search(const vector<int> &arr, int n, int target) 
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; 
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cin >> target;

    int ans = binary_search(arr, arr.size(), target);

    if (ans != -1)
        cout << "Element found at index: " << ans;
    else
        cout << "Element not found";
}
