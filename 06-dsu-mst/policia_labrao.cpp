#include<bits/stdc++.h>
using namespace std;

int n, m;
int matriz[5][5];
int visitado[5][5];

int a[] = {0,0,1,-1};
int b[] = {1,-1,0,0};

void dfs(int i, int j){
    visitado[i][j] = 1;
    for(int k = 0; k < 4; k++){
        if(i+a[k] >=0 && i+a[k] < n && j+b[k] >= 0 && j+b[k] < m &&
		 !visitado[i+a[k]][j+b[k]] && matriz[i+a[k]][j+b[k]] == 0){
            dfs(i+a[k],j+b[k]);
        }
        
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        n = 5, m = 5;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> matriz[i][j];
                visitado[i][j] = 0;
            }
        }
        if(matriz[0][0] == 0) dfs(0,0);
        // if(visitado[0][0] && visitado[4][4]) cout << "COPS\n";
        // else cout << "ROBBERS\n";

		cout << ( (visitado[0][0] && visitado[4][4]) ? "COPS" : "ROBBERS" ) << endl;
    }
    return 0;
}