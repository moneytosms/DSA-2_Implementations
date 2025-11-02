#include <bits/stdc++.h>
using namespace std;

long double polygon_area(vector<pair<int,int>> &pts) {
    int n = pts.size();
    long double area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i+1) % n;
        area += (long double)(pts[i].first * pts[j].second - pts[j].first * pts[i].second);
    } 
    return fabsl(area) / 2.0;
}

int boundary_on_edge(pair<int,int> p1, pair<int,int> p2) {
    return __gcd(abs(p2.first - p1.first), abs(p2.second - p1.second));
}

int main() {
    vector<pair<int,int>> poly = {
        {10,8}, {25,8}, {27,15}, {25,20}, {10,20}
    };

    long double Area = polygon_area(poly);
    cout<<Area<<"\n";
    int Bpoints = 0;
    for (int i = 0; i < (int)poly.size(); i++) {
        int j = (i+1) % poly.size();
        Bpoints += boundary_on_edge(poly[i], poly[j]);
    }

    long long I = llround(Area - (long double)Bpoints/2.0 + 1);

    cout << I << "\n";
    return 0;
}