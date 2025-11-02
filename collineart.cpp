#include <bits/stdc++.h>
using namespace std;

bool checkStraightLine(vector<pair<int,int>> coordinates){
	int x1=coordinates[0].first;
	int y1=coordinates[0].second;
	int x2=coordinates[1].first;
	int y2=coordinates[1].second;

	for(auto i: coordinates){
		int x = i.first;
		int y = i.second;

		if((y2-y1)*(x-x1)!=(x2-x1)*(y-y1)){
			return false;
		}
	}

	return true;
}


int main(int argc, char const *argv[])
{
	

	vector<pair<int,int>> coordinates={{0,0},{0,1},{0,3},{1,99999}};

	cout << (checkStraightLine(coordinates)?"True":"False");



	return 0;
}
