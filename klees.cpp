#include <bits/stdc++.h>
using namespace std;
#include "../../Setup/debug.h"
pair<int, int> klees(vector<pair<int, int>> coordinates)
{
    int maxlen = 0;

    vector<pair<int, bool>> aux_array;

    for (auto x : coordinates)
    {
        aux_array.push_back({x.first, false});
        aux_array.push_back({x.second, true});
    }
    sort(aux_array.begin(), aux_array.end());

    int count = 0;
    int result = 0;
    int seg_len = 0;

    for (int i = 0; i < aux_array.size(); i++)
    {
        if (count > 0)
        {
            result += aux_array[i].first - aux_array[i - 1].first;
            seg_len += aux_array[i].first - aux_array[i - 1].first;
        }

        aux_array[i].second ? count-- : count++;

        if (count == 0)
        {
            maxlen = max(seg_len, maxlen);
            seg_len = 0;
        }
    }

    return {result, maxlen};
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
    pair<int, int> r;
    r = klees(coordinates);
    int result = r.first;
    // cout << "Length Of Union Of Segments of a line : " << result;
    int maxlen = r.second;
    // cout << "Maximum Length of Segments of a line : " << maxlen;
    return 0;
}
