#include <bits/stdc++.h>
using namespace std;

int partition(int l, int h, vector<int> &arr)
{
    int pivot = arr[h]; 
    int i = l - 1;      

    for (int j = l; j < h; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;               
}

void quick_sort(int l, int h, vector<int>& arr)
{
    if (l < h)
    { 
        int part = partition(l, h, arr);
        quick_sort(l, part - 1, arr); 
        quick_sort(part + 1, h, arr);
    }
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quick_sort(0,arr.size()-1,arr);

    for (auto x : arr)
    {
        cout << x << " ";
    }
}
// time complexity:
// best case O(nlogn)
// average case O(nlogn)
// worst case O(n^2) if already sorted
// space complexity: O(logn) due to recursion