#include<bits/stdc++.h>
using namespace std;

void linear_search(vector<int> arr, int target){

    int index = -1;
    for(auto x: arr){
        index++;
        if(x==target){
            cout <<index;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cin >> target;

    linear_search(arr, target);

}