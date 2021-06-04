#include <bits/stdc++.h>
using namespace std;

int main(){
    int build_number_2 = 0; 
    int build_number_3 = 0; 
    int build_number_5 = 0; 
    string s;
    cin >> s;
    for (auto c:s) {
        int d = c - '0';
        int pot10 = (10%2 * build_number_2%2) % 2;
        build_number_2 =  (pot10%2 + d%2)%2;
        // cout << build_number << endl;
        pot10 = (10%3 * build_number_3%3) % 3;
        build_number_3 =  (pot10%3 + d%3)%3;
        // cout << build_number << endl;
        pot10 = (10%5 * build_number_5%5) % 5;
        build_number_5 =  (pot10%5 + d%5)%5;
        // cout << build_number << endl;
    }
    cout << (build_number_2 == 0 ? "S":"N") << endl;
    cout << (build_number_3 == 0 ? "S":"N") << endl;
    cout << (build_number_5 == 0 ? "S":"N") << endl;
    return 0;
} 