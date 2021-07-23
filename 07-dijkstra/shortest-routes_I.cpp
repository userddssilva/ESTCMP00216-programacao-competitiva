#include<bits/stdc++.h>
using namespace std;
#define N 100002
#define INF 2000000000000009


long long int n, m, u, s, v, w, dist[N], processed[N];
vector<pair<long long int, long long int> > adj[N];

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        processed[i] = 0;
    }
    dist[1] = 0;

    priority_queue<pair<long long int, long long int>> pq;
    pq.push({ 0, 1 });

    while(pq.size()) {
        int u = pq.top().second;
        pq.pop();
		
        if (processed[u]) continue;
        processed[u] = 1;
		
		for (auto [v, w] : adj[u]) {
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({ -dist[v], v });
			}
		}
    }
	for (int i = 1; i <= n; i++){
		if (i != n) cout << dist[i] << " ";
		else cout << dist[i] << "\n";
	}
}

int main() {
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
	// cin >> s;
    dijkstra();

    return 0;
}