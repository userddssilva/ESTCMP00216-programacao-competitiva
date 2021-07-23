#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    int n, q, k = 1;
    while(cin >> n >> q){
        v.clear();
        if(!n && !q) return 0;
        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        int consulta;
        cout << "CASE# " << k << ":\n";
        for(int i = 0; i < q; i++){
            int f= 0;
            cin >> consulta;
            for(int j = 0; j < n; j++){
                if(consulta == v[j]){
                    f = 1;
                    cout << consulta << " found at " << j+1 << endl;
                    break;
                }
            }if(!f){
                cout << consulta << " not found" <<  endl;
            }
        }
        k++;
    }
    return 0;
}