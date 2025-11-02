int manhattan(vector<pair<int,int>> coordinates){

    vector<int> sum;
    vector<int> diff;

    for(auto i: coordinates){
        sum.push_back(i.first+i.second);
        diff.push_back(i.first-i.second);
    }


    return max(*max_element(sum.begin(),sum.end())-*min_element(sum.begin(),sum.end()),
               *max_element(diff.begin(),diff.end())-*min_element(diff.begin(),diff.end()));
}