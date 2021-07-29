
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <ll> a;

int bsearch(ll lo, ll hi, ll x){
    ll md;
    while(lo < hi){
        md = lo + (hi-lo)/2;
        if(a[md] <= x) hi = md;
        else lo = md + 1;
    }
    return lo; 
}

int main(){
    ll n, k, ki, ic;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> ki;
        a.push_back(ki);
    }
    for(int i = 0; i < k; i++){
        cin >> ki;
        ic = bsearch(0, n-1, ki);
        if(a[ic] < ki) cout << n+1 << endl;
        else cout << ic+1 << endl;
    }
    return 0;
}