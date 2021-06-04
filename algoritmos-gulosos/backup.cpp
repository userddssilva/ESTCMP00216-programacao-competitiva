#include <bits/stdc++.h>
using namespace std;

int main() {
    int equipamentos [] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};
    int backup, n=0; cin >> backup;
    for (int i=14; i >= 0; i--) {
        while(backup >= equipamentos[i]) {
            n++;
            backup = backup%equipamentos[i];
        }
    }
    cout << n << endl;
}