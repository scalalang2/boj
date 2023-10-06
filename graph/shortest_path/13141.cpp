#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N, M;
vector<vector<int>> adj;
vector<vector<int>> dist;

double burn() {
    double shortest_time = INF, longest_time, spent_time, remain_len;
    int edge_len;

    for(int i = 1; i <= N; i++) {
        longest_time = 0;

        for(int from = 1; from <= N; from++) {
            for(int to = 1; to <= N; to++) {
                edge_len = adj[from][to];
                if(edge_len == -1) continue;

                remain_len = edge_len - (dist[i][to] - dist[i][from]);
                if(remain_len > 0) {
                    spent_time = (remain_len/2) + dist[i][to];
                    longest_time = max(longest_time, spent_time);
                }
            }
        }

        shortest_time = min(shortest_time, longest_time);
    }

    return shortest_time;
}

void floyd() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    adj.resize(N+1, vector<int>(N+1, -1));
    dist.resize(N+1, vector<int>(N+1, INF));

    for(int i = 1; i <= N; i++) dist[i][i] = 0;

    int u, v, w;
    for(int i = 0; i < M; i++) {
        cin >> u >> v >> w;

        // 가장 짧은 간선으로 거리 갱신
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);

        // 가장 긴 간선만 저장해둔다
        if(adj[u][v] == -1 || adj[u][v] < w) {
            adj[u][v] = w;
            adj[v][u] = w;
        }
    }

    floyd();

    printf("%.1f\n", burn());

    return 0;
}