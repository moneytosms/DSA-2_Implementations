#include <bits/stdc++.h>
using namespace std;
  
float find_area(pair<int,int> a, pair<int,int> b, pair<int,int> c){

	int x1= a.first;
	int y1= a.second;
	int x2= b.first;
	int y2= b.second;
	int x3= c.first;
	int y3= c.second;

	return abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));

}

bool checkInterior(vector<pair<int,int>> coordinates, pair<int,int> point){

	float a1= find_area(coordinates[0],coordinates[1],point);
	float a2= find_area(coordinates[1],coordinates[2],point);
	float a3= find_area(coordinates[0],coordinates[2],point);
	float a4= find_area(coordinates[0],coordinates[1],coordinates[2]);

	return (a1+a2+a3==a4);

}

int main(int argc, char const *argv[]) {
    // Define triangle
    pair<int,int> A = {0, 0};
    pair<int,int> B = {5, 0};
    pair<int,int> C = {0, 5};

    // Test points
    vector<pair<int,int>> testPoints = {
        {1, 1},   // inside
        {2, 2},   // inside
        {5, 5},   // outside
        {3, 0},   // on edge
        {0, 0},   // vertex
        {-1, 1}   // outside
    };

    for (auto P : testPoints) {
        cout << "Point (" << P.first << "," << P.second << ") is: ";
        if (checkInterior({A, B, C}, P))
            cout << "INSIDE\n";
        else
            cout << "OUTSIDE\n";
    }

    return 0;
}
