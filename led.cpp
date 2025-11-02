#include<bits/stdc++.h>
using namespace std;

int brian(unsigned char x) {
int count = 0;
while (x) {
    x = x & (x - 1);
    count++;
}
return count;
}

int main() {

    unsigned char SIG_IN = 0b00000111;

    unsigned char LED_Status=0b10101100;

    LED_Status = LED_Status | SIG_IN;   
    LED_Status = LED_Status & SIG_IN;   
    LED_Status = ~LED_Status;           
    LED_Status = LED_Status ^ SIG_IN;   
    
    // for (int i = 7; i >= 0; i--) {
    //     cout << ((LED_Status >> i) & 1);
    // }
    // cout << endl;

    cout << brian(LED_Status) << endl;

    return 0;
}
