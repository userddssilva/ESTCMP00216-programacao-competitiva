#include <bits/stdc++.h>
using namespace std;

int pai[1000123],c;

void init(int n){
    for(int i=1;i<=n;++i) pai[i]=i;
}

int id(int n){
    return pai[n]=(n==pai[n] ? n:id(pai[n]));
}


void join(int u,int v){
    u=id(u);
    v=id(v);
    if(u!=v){
        pai[u]=v;
        ++c;
    }
}


int main(){
    int n, m, u, v, t;
    cin >> n >> m;
    init(n + 1);
    t = n;
    for(int i = 0; i < m; ++i){
        cin >> u >> v;
        join(u,v);
    }
    cout << t - c << endl;

    return 0;
}