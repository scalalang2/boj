#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

// BOJ - 25428 분필 도둑
// 분필의 개수가 큰 정점에서 부터 출발해서 하나씩 연결해보며
// 교실 집합이 가진 가장 작은 분필의 개수 * 교실 집합의 크기로 정답을 계속 갱신해간다.
const int mxn = 100001;
ll N;
vector<pll> adj[mxn];
ll par[mxn], cnt[mxn];
vector<pll> cost;

ll find(int node) {
    if(par[node] == node) return node;
    return par[node] = find(par[node]);
}

ll merge(ll a, ll b) {
    a = find(a), b = find(b);
    if(a == b) return 0;
    if(cnt[a] < cnt[b]) swap(a, b);
    par[b] = a;
    cnt[a] += cnt[b];
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll ans = 0;

    for(int i = 0; i < mxn; i++) par[i] = i;
    cin >> N;
    for(int i = 0; i < N; i++) {
        ll c; cin >> c;
        cost.emplace_back(c, i);
        cnt[i] = 1;
        ans = max(ans, c);
    }
    for(int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].emplace_back(cost[b].first, b);
        adj[b].emplace_back(cost[a].first, a);
    }

    sort(cost.begin(), cost.end(), greater<>());
    for(int i = 0; i < N; i++) sort(adj[i].begin(), adj[i].end(), greater<>());
    for(int i = 0; i < N; i++) {
        ll c, node;
        tie(c, node) = cost[i];

        // cout << node << " " << c << endl;

        // 이제 하나씩 연결된 노드를 합쳐보자
        for(auto [to_cost, to_node] : adj[node]){
            if(to_cost < c) continue;
            if(find(node) == find(to_node)) continue;
            merge(node, to_node);

            ans = max(ans, c * cnt[find(node)]);
        }
    }

    cout << ans << endl;
    return 0;
}