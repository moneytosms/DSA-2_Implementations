#include <bits/stdc++.h>
using namespace std;

#define pdd pair<double, double>
#define line tuple<double, double, double>


line lineFromPoints(pdd P, pdd Q)
{
    double a = Q.second - P.second;
    double b = P.first - Q.first;
    double c = a * P.first + b * P.second;
    return make_tuple(a, b, c);
}

line getPerpendicularBisector(pdd P, pdd Q)
{
    double a, b, c;
    tie(a, b, c) = lineFromPoints(P, Q);

    pdd mid_point = make_pair((P.first + Q.first) / 2.0,
                              (P.second + Q.second) / 2.0);

    swap(a, b);
    a = -a;

    c = a * mid_point.first + b * mid_point.second;

    return make_tuple(a, b, c);
}

pdd getIntersection(line L1, line L2)
{
    double a1, b1, c1;
    double a2, b2, c2;
    tie(a1, b1, c1) = L1;
    tie(a2, b2, c2) = L2;

    double det = a1 * b2 - a2 * b1;
    if (fabs(det) < 1e-9)
        return make_pair(1e18, 1e18); // parallel

    double x = (b2 * c1 - b1 * c2) / det;
    double y = (a1 * c2 - a2 * c1) / det;
    return make_pair(x, y);
}

pdd findCircumCenter(pdd P, pdd Q, pdd R)
{
    line L1 = getPerpendicularBisector(P, Q);
    line L2 = getPerpendicularBisector(Q, R);
    return getIntersection(L1, L2);
}
int main()
{
    pdd P = make_pair(6.0, 0.0);
    pdd Q = make_pair(0.0, 0.0);
    pdd R = make_pair(0.0, 8.0);

    pdd C = findCircumCenter(P, Q, R);
    cout << "The meeting point is: ";
    cout << "(" << C.first << "," << C.second << ")" << endl;

    return 0;
}
