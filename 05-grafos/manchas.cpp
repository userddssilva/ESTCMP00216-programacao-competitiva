#include<bits/stdc++.h>
using namespace std;

bool vis[1010][1010];
int matriz[1010][1010];
int n, m;
int a[] = {0, -1, 1, 0};
int b[] = {1, 0, 0, -1};

void dfs(int i, int j){
    vis[i][j] = 1;
    for(int k = 0; k < 4; k++){
        if(i+a[k] >=0 && i+a[k] < n && j+b[k] >= 0 && j+b[k] < m &&
		 vis[i + a[k]][j + b[k]] == 0 && matriz[i + a[k]][j + b[k]] == 1){
            dfs(i + a[k], j + b[k]);
        }
    }
}

int main(){
    cin >> n >> m;  
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matriz[i][j];
        }
    }
    int cont = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] == 1 || matriz[i][j] == 0) continue;
            else{
                cont++;
                dfs(i,j);
            } 
        }
    }
    
    cout << cont << endl;
    return 0;
}