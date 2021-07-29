 
#include <bits/stdc++.h>
using namespace std;

int pai[110000];
int b,o,x,y;
char d;

void init(int n){
    for(int i = 1;i<=n;++i) pai[i] = i;
}

int id(int n){
    return pai[n] = (n==pai[n]? n:id(pai[n]));
}

void join(int u, int v){
    u = id(u);
    v = id(v);
    if(u!=v){
        pai[u]=v;
    }
}

char verify(int u, int v){
    u = id(u);
    v = id(v);
    if(u!=v) return 'N';
    return 'S';
}

int main(){
    cin >> b >> o;
    init(b+1);
    for(int k = 0; k < o; ++k){
        cin >> d >> x >> y;
        if(d == 'F'){
            join(x,y);
        }
        else{
            cout << verify(x,y) << endl;
        }
    }
    return 0;
}