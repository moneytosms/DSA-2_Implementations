#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr)
{

    for (int i = 0; i < (int)arr.size() - 1; i++)
    {
        for (int j = 0; j < ((int)arr.size() - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j+1], arr[j]);
            }
        }
    }
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bubble_sort(arr);

    for (auto x : arr)
    {
        cout << x<<" ";
    }
}