#include <iostream>
#include <algorithm>
using namespace std;

struct Playzone {
    int x1, y1, x2, y2;
    string name;
};

int overlapArea(Playzone A, Playzone B) {
    int w = max(0, min(A.x2, B.x2) - max(A.x1, B.x1));
    int h = max(0, min(A.y2, B.y2) - max(A.y1, B.y1));
    return w * h;
}

int main() {
    Playzone cricket   = {0, 0, 128, 128, "Cricket"};
    Playzone football  = {175, 175, 320, 320, "Football"};
    Playzone badminton = {108, 108, 500, 500, "Badminton"};

    cout << "Overlap Areas:\n";

    int areaCF = overlapArea(cricket, football);
    cout << "Cricket & Football: " 
         << (areaCF ? to_string(areaCF) : "No Overlap") << "\n";

    int areaCB = overlapArea(cricket, badminton);
    cout << "Cricket & Badminton: " 
         << (areaCB ? to_string(areaCB) : "No Overlap") << "\n";

    int areaFB = overlapArea(football, badminton);
    cout << "Football & Badminton: " 
         << (areaFB ? to_string(areaFB) : "No Overlap") << "\n";

    return 0;
}
