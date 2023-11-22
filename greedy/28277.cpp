#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

// 뭉쳐야 산다.
// 앳코더 329 - F 문제랑 동일함
int N, Q;
set<int> sets[500001];
int owner[500001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> Q;
    for(int i = 1; i <= N; i++) {
        int sz; cin >> sz;
        owner[i] = i;
        for(int j = 0; j < sz; j++) {
            int x; cin >> x;
            sets[i].insert(x);
        }
    }

    while(Q--) {
        int q; cin >> q;
        if(q == 1) {
            int a, b; cin >> a >> b;
            if(sets[owner[a]].size() < sets[owner[b]].size()) swap(owner[a], owner[b]);
            for(auto x : sets[owner[b]]) {
                sets[owner[a]].insert(x);
            }
            sets[owner[b]].clear();
        } else {
            int a; cin >> a;
            cout << sets[owner[a]].size() << '\n';
        }
    }

    return 0;
}