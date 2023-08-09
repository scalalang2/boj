#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int dist[101][101];
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++) {
            dist[i][j] = INF;
            if(i == j) dist[i][j] = 0;
        }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }

    // 플로이드 와샬 k를 키워가면서 dist[i][j] = min(dist[i][k] + dist[k][j]) 을 계속 갱신 하는 것
    // 플로이드 와샬에서 거쳐가는 노드가 먼저 등장하면서 갱신해줘야 한다.
    // 즉, for문 순서는 k > i > j
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = INF;
    int idx = INF;
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            sum += dist[i][j];
        }

        if(sum < ans) {
            ans = sum;
            idx = i;
        }
    }

    cout << idx << endl;

    return 0;
}