#include <bits/stdc++.h>

#define TAM 1050

using namespace std;

int N, M, ans;
char grid[TAM][TAM];
int visited[TAM][TAM];

// int di[] = {0, 1, 0, -1};
// int dj[] = {1, 0, -1, 0};

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};



void floodfill(int i, int j){
   
    visited[i][j] = 1;

	for (int k = 0; k < 4; k++) {
		int ki = i + di[k];
		int kj = j + dj[k];
		if(ki >= 0 && ki < N && kj >= 0 && kj < M && grid[ki][kj] != 'o' && !visited[ki][kj])
			floodfill(i + di[k], j + dj[k]);

	}
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (grid[i][j] != 'o' && !visited[i][j]){
                floodfill(i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
     
}