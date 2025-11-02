#include <iostream>
using namespace std;



int main() {
    int N = 550, M = 550; 
    long long rows = 1LL * N * (N + 1) / 2; 
    long long cols = 1LL * M * (M + 1) / 2; 


    long long total =rows * cols;

    cout << "Grid size: " << N << " x " << M << "\n";
    cout << "Total number of rectangles possible: " << total << "\n";

    return 0;
}
