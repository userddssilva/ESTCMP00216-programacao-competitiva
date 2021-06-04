#include <bits/stdc++.h>
#define MOD int(10e9)+7
using namespace std;

int ans;
int expoente;
int letter;
int a, b;
long long mult;
long long soma;
string s;
map<char, int>abc;

int main() {
    
    letter = 65;
    for (int i=0; i<26; i++) {
        abc.insert(make_pair((char)letter, i));
        //  cout << abc[(char)letter] << endl;
        letter++;
    }

    while(cin >> s) {
        expoente = s.size() - 1;
        soma = 0;
        for(char c: s) {
            cout << c << abc[c] << endl;
            soma = (abc[c] + soma*26) % MOD;
            // a = abc[c] % MOD;
            // b = pow(26, expoente);
            // mult = (a%MOD *( b % MOD)) % MOD;
            // soma = (soma%MOD + mult%MOD) % MOD;
            // expoente--;
        }
        cout << soma << endl;
    }
    return 0;
}