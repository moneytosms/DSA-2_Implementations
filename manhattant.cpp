#include<bits/stdc++.h>
using namespace std;

int manhattan(vector<pair<int,int>> coordinates) {
    vector<int> sum;
    vector<int> diff;

    for(auto i: coordinates){
        sum.push_back(i.first + i.second);
        diff.push_back(i.first - i.second);
    }

    return max(
        *max_element(sum.begin(), sum.end()) - *min_element(sum.begin(), sum.end()),
        *max_element(diff.begin(), diff.end()) - *min_element(diff.begin(), diff.end())
    );
}

int main() {
    // Example 1: Simple square points
    vector<pair<int,int>> points1 = {{0,0}, {0,1}, {1,0}, {1,1}};
    cout << "Max Manhattan distance (points1) = " << manhattan(points1) << endl;
    // Expected: 2 (from (0,0) to (1,1))

    // Example 2: Spread out points
    vector<pair<int,int>> points2 = {{-1,-1}, {2,3}, {5,0}, {0,6}};
    cout << "Max Manhattan distance (points2) = " << manhattan(points2) << endl;
    // Check: between (-1,-1) and (5,0) = 7, or (-1,-1) and (0,6) = 8 → max = 8

    // Example 3: Single point
    vector<pair<int,int>> points3 = {{3,4}};
    cout << "Max Manhattan distance (points3) = " << manhattan(points3) << endl;
    // Expected: 0

    // Example 4: Two far apart points
    vector<pair<int,int>> points4 = {{0,0}, {100,200}};
    cout << "Max Manhattan distance (points4) = " << manhattan(points4) << endl;
    // Expected: 300

    return 0;
}
