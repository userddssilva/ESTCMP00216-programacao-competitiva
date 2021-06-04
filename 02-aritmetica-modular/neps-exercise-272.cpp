#include <bits/stdc++.h>
using namespace std;

int main(){
    int buid_number_11 = 0; 
    string s;
    cin >> s;
    for (auto c:s) {
        int d = c - '0';
        int pot10 = (10 % 11 * buid_number_11 % 11) % 11;
        buid_number_11 =  (pot10 % 11 + d % 11) % 11;
    }
    cout << (buid_number_11 == 0 ? "S":"N") << endl;
    return 0;
} 