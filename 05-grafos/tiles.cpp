#include <bits/stdc++.h>
#define MAX 205
using namespace std;

int telas[MAX][MAX];

int main(int argc, char const *argv[])
{
	set<pair<int,int>> s;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> telas[i][j];
			s.insert(make_pair(telas[i][j], 0));
		}
	}
	for (int i = 0; i < n; i++) {
	return 0;
}
