#include <bits/stdc++.h>
using namespace std;

int main(){
    int build_number_4 = 0; 
    int build_number_9 = 0; 
    int build_number_25 = 0; 
    string s;
    cin >> s;
    for (auto c:s) {
        int d = c - '0';
        int pot10 = (10 % 4 * build_number_4 % 4) % 4;
        build_number_4 =  (pot10 % 4 + d % 4) % 4;
        // cout << build_number << endl;
        pot10 = (10 % 9 * build_number_9 % 9) % 9;
        build_number_9 =  (pot10 % 9 + d % 9) % 9;
        // cout << build_number << endl;
        pot10 = (10 % 25 * build_number_25 % 25) % 25;
        build_number_25 =  (pot10 % 25 + d % 25) % 25;
        // cout << build_number << endl;
    }
    cout << (build_number_4 == 0 ? "S":"N") << endl;
    cout << (build_number_9 == 0 ? "S":"N") << endl;
    cout << (build_number_25 == 0 ? "S":"N") << endl;
    return 0;
} 