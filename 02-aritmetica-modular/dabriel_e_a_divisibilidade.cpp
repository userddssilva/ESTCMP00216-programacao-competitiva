#include <bits/stdc++.h>
using namespace std;


string n;
int m, mi;
vector<int> ans;


int main() {
	cin >> n >> m;

	for (int i=0; i<m; i++) {
		cin >> mi;
		int binnum = 0;
		int pow2 = 1;
		for (int j=n.size()-1; j >= 0; j--) {
			binnum += (((n[j]-'0')%mi)*(pow2)%mi)%mi;
			pow2 = (2%mi*pow2%mi)%mi;
		}
		if(!(binnum % mi)) ans.push_back(mi);
	}

	if (ans.size() != 0) {
		sort(ans.begin(), ans.end());
		for(int i=0; i<ans.size(); i++) {
			cout << ans[i];
			if (i != ans.size()-1) cout << ' ';
		}
	} else {
		cout << "Nenhum";
	}
	cout << '\n';

	return 0;
}