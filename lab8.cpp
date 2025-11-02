#include <iostream>
#include <algorithm>
using namespace std;

struct Playzone {
    int x1, y1, x2, y2;
    string name;
};


bool isOverlap(Playzone A, Playzone B) {
    return !(A.x2 < B.x1 || B.x2 < A.x1 || A.y2 < B.y1 || B.y2 < A.y1);
}

Playzone getOverlap(Playzone A, Playzone B) {
    Playzone res;
    res.x1 = max(A.x1, B.x1);
    res.y1 = max(A.y1, B.y1);
    res.x2 = min(A.x2, B.x2);
    res.y2 = min(A.y2, B.y2);
    return res;
}

void printPlayzone(Playzone R) {
    cout << "{" << R.x1 << ", " << R.y1 << ", " << R.x2 << ", " << R.y2 << "}";
}

int main() {

    int N = 550, M = 550;

    Playzone cricket   = {0, 0, 128, 128, "Cricket"};
    Playzone football  = {175, 175, 320, 320, "Football"};
    Playzone badminton = {108, 108, 500, 500, "Badminton"};

    if(isOverlap(cricket, football)) {
        Playzone ov = getOverlap(cricket, football);
        cout << "Overlap between Cricket and Football at ";
        printPlayzone(ov);
        cout << "\n";
    } else cout << "Cricket and Football do not overlap.\n";


    if(isOverlap(cricket, badminton)) {
        Playzone ov = getOverlap(cricket, badminton);
        cout << "Overlap between Cricket and Badminton at ";
        printPlayzone(ov);
        cout << "\n";
    } else cout << "Cricket and Badminton do not overlap.\n";


    if(isOverlap(football, badminton)) {
        Playzone ov = getOverlap(football, badminton);
        cout << "Overlap between Football and Badminton at ";
        printPlayzone(ov);
        cout << "\n";
    } else cout << "Football and Badminton do not overlap.\n";

    return 0;
}
