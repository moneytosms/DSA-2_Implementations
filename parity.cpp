#include <iostream>
#include <vector>
using namespace std;

// Function to generate lookup table for 8-bit numbers
vector<int> createParityTable() {
    vector<int> parityTable(256); 
    for (int i = 0; i < 256; ++i) {
        int x = i;
        int parity = 0;
        while (x) { 
            parity ^= (x & 1); // XOR each bit
            x >>= 1;
        }
        parityTable[i] = parity;
    }
    return parityTable;
}

// Function to compute parity using lookup table
int getParity(unsigned int num, const vector<int>& parityTable) {
    int parity = 0;
    while (num) {
        parity ^= parityTable[num & 0xFF]; // Check lowest 8 bits
        num >>= 8;                         // Shift right by 8 bits
    }
    return parity;
}

int main() {
    vector<int> parityTable = createParityTable();

    unsigned int num;
    cout << "Enter a number: ";
    cin >> num;

    int parity = getParity(num, parityTable);
    cout << "Parity of " << num << " is " << parity << endl;

    return 0;
}
