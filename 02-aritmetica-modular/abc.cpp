#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ar array
#define vec vector
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define MOD (int)(1e9+7)
int inv_mod(int a, int b){return a > 1 ? b-inv_mod(b%a, a)*b/a : 1;};

string s;

void solve() {
	while(cin >> s) {
		ll int n = 0;
		ll int pow26 = 1;
		for (int i=s.size()-1; i>=0; i--) {
			n += (s[i]-'A')*pow26;
			pow26 = (pow26%MOD * 26%MOD)%MOD;
		}
		cout << n%MOD << '\n';
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	solve();

	return 0;
}