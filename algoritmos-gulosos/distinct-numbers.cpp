#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned long long n, x;
    set <unsigned long long> numbers;
    cin >> n;
    while(n--){
        cin >> x;
        numbers.insert(x);
    }
    cout << numbers.size() << endl;
    return 0;
}
