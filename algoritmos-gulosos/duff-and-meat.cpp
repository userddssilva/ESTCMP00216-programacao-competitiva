#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n), p(n);
    int ans = 0, preco = 200;
    for (int i=0; i<n; i++) cin >> a[i] >> p[i];
    for (int i=0; i<n; i++) {
        preco = min(preco, p[i]);
        ans += a[i] * preco;
    } 
    cout << ans << endl;
    return 0;
}