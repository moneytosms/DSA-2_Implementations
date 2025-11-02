#include <bits/stdc++.h>
using namespace std;

long double triangle_area(pair<int,int> a, pair<int,int> b, pair<int,int> c) {
    return fabsl((long double)(a.first*(b.second-c.second) + b.first*(c.second-a.second) + c.first*(a.second-b.second))) / 2.0;
}

int boundary_on_edge(pair<int,int> p1, pair<int,int> p2) {
    return __gcd(abs(p2.first - p1.first), abs(p2.second - p1.second));
}

int main() {
    pair<int,int> A, B, C;
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> C.first >> C.second;

    long double Area = triangle_area(A,B,C);

    int Bpoints = boundary_on_edge(A,B) + boundary_on_edge(B,C) + boundary_on_edge(C,A);

    long long I = llround(Area - (long double)Bpoints/2.0 + 1);

    cout<<I;
    return 0;
}