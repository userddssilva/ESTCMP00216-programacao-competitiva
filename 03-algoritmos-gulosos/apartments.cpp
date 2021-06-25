// https://cses.fi/problemset/task/1084

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    unsigned long long k;
    int n, m; 
    cin >> n >> m >> k;
    vector<unsigned long long> a(n), b(m);
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<m;i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i=0;i<n;i++) cout << a[i] << " "; cout << endl;
    for (int i=0;i<m;i++) cout << b[i] << " "; cout << endl;
    cout << endl;
    int j = 0, ans=0;
    for (int i=0;i<m;i++) 
    {
        cout << a[j]-k << " " << b[i] << " " << a[j]+k << endl;
        if ((a[j]-k <= b[i]) && (b[i] <= a[j] + k)) 
        {
            j++;
            ans++;

            cout << a[j]-k << " " << b[i] << " " << a[j]+k << endl;
            
        }
        j++;

    }
    cout << ans << endl;
}