#include<bits/stdc++.h>
using namespace std;
#define N 1002
#define INF 1000000009

int n, m, u, s, v, w, dist[N], processed[N];
vector<pair<int, int> > adj[N];

int dijkstra() {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        processed[i] = 0;
    }
    dist[s] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, s });

    while(pq.size()) {
        int u = pq.top().second;
        pq.pop();

        if (processed[u]) {
            continue;
        }

        processed[u] = 1;

		// for (int i = 1; i < adj[u].size(); i++){
			// int v = adj[u][i].first;
			// int w = adj[u][i].second;
			// cout << v << ":" << w << endl;
		for (auto [v, w] : adj[u]) {
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({ -dist[v], v });
			}
		}
		// }
    }
	int maior =-INF;
	int menor = INF;
	for (int i = 1; i <= n; i++) {
		// cout << dist[i] << endl;
		if (dist[i] > maior) {
			maior = dist[i];
		}
		if (dist[i] < menor && i != s) {
			menor = dist[i];
		}
	}
	//cout << maior << " " << menor << endl;
    return maior-menor;
}

int main() {
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
	cin >> s;
    cout << dijkstra() << endl;

    return 0;
}