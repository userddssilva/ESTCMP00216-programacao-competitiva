//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector <ll> a;


ll busca_binaria(ll lo, ll hi, ll x){
    ll md;
    while(lo < hi){
        md = lo + (hi-lo)/2;
        if(a[md] <= x) lo = md + 1;
        else hi = md;
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
        ic = busca_binaria(0, n, ki);
        cout << ic << endl;
    }
    return 0;
}