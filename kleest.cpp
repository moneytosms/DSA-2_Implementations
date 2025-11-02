#include <bits/stdc++.h>
using namespace std;

int klees(vector<pair<int,int>> coordinates){

    vector<pair<int,bool>> aux_array;

    for (auto x: coordinates){
        aux_array.push_back({x.first,false});
        aux_array.push_back({x.second,true});
    }

    
    sort(aux_array.begin(),aux_array.end());

    int count = 0;
    int result = 0;

    for(int i = 0; i< aux_array.size();i++){

        if (count > 0){
            result+=aux_array[i].first-aux_array[i-1].first;
        }

        if(!aux_array[i].second){
            count++;
        }
        else{
            count--;
        }
    }

    return result;
}

int main() {
    vector<pair<int,int>> intervals;

    // Example 1: overlapping intervals
    intervals = {{1, 5}, {2, 6}, {8, 10}};
    cout << "Union length = " << klees(intervals) << endl;
    // Expected: [1,6] and [8,10] → length = 5 + 2 = 7

    // Example 2: disjoint intervals
    intervals = {{1, 2}, {3, 4}, {5, 7}};
    cout << "Union length = " << klees(intervals) << endl;
    // Expected: (1,2)=1, (3,4)=1, (5,7)=2 → total = 4

    // Example 3: nested intervals
    intervals = {{1, 10}, {2, 5}, {6, 9}};
    cout << "Union length = " << klees(intervals) << endl;
    // Expected: (1,10) covers everything → length = 9

    return 0;
}
