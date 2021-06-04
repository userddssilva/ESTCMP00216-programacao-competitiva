#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define i64 long long
#define MAXN 1000123
#define sz(x) (int)(x).size()

using namespace std;

i64 fexp(i64 base, i64 expoente, i64 modulo) {
    i64 ans = 1;
    while (expoente) {
        if (expoente&1) ans = (ans * base) % modulo;
        base = (base * base) % modulo;
        expoente >>= 1;
    }
    return ans;    
}

i64 n, m, dp[MAXN], pot[10], rb;
string b, e;

int main() {_
    cin >> b >> e >> m;
    
    rb = 0;
    for (char d : b) {
        rb = (10 * rb + (d - '0')) % m;
    }

    pot[0] = 1;
    for (int i = 1; i < 10; ++i) {
        pot[i] = (pot[i-1] * rb) % m;
    }

    n = sz(e);

    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        dp[i+1] = (fexp(dp[i], 10, m) * pot[e[i]-'0']) % m;
    }

    cout << dp[n] << endl;
    return 0;
}