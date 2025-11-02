#include <bits/stdc++.h>
using namespace std;
#include "../../Setup/debug.h"

void manhattan(vector<pair<int, int>> coordinates)
{
    vector<int> sum;
    vector<int> diff;
    
    for (auto x : coordinates)
    {
        sum.push_back(x.first + x.second);
        diff.push_back(x.first - x.second);
    }

    int x1 = *max_element(sum.begin(), sum.end());
    int x2 = *min_element(sum.begin(), sum.end());
    int x3 = *max_element(diff.begin(), diff.end());
    int x4 = *min_element(diff.begin(), diff.end());

    cout << max(x1 - x2, x3 - x4)<<endl;
}

int main()
{
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;
    vector<pair<int, int>> coordinates(n);
    cout << "Enter intervals (start end) one per line:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> coordinates[i].first >> coordinates[i].second;
    }
    manhattan(coordinates);
}