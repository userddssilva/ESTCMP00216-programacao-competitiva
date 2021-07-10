#include<bits/stdc++.h>
using namespace std;
int n, k, cont;
int array_input[200123];
 
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> array_input[i];
    }
    sort(array_input, array_input+n);
    int i = 0, j = n-1;
    while(i <= j){
        if(i == j){
            cont++;
            i++;
            j--;
            break;
        }
        else if(array_input[i] + array_input[j] > k){
            cont++;
            j--;
            continue;
        }else if(array_input[i] + array_input[j] <= k){
            cont++;
            i++;
            j--;
            continue;
        }
    }cout << cont << endl;
    return 0;
}