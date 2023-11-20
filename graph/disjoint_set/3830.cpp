#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

const int mxn = 1e6+5;
int par[mxn];
ll value[mxn];

void init() {
    for(int i = 0; i < mxn; i++) {
        par[i] = i;
        value[i] = 0;
    }
}

int find(int a) {
    if(par[a] == a) return a;
    int p = find(par[a]);
    value[a] += value[par[a]];
    return par[a] = p;
}

bool merge(int a, int b, ll w) {
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) return false;
    value[pb] = value[a] + w - value[b];
    par[pb] = pa;
    return true;
}

void solve(int n, int m) {
    init();
    for(int i = 0; i < m; i++) {
        char op; cin >> op;
        if(op == '!') {
            int a,b;
            ll w;
            cin >> a >> b >> w;
            if(merge(a, b,w)) {

            }
        } else {
            int a, b;
            cin >> a >> b;
            if(find(a) != find(b)) {
                cout << "UNKNOWN\n";
            } else {
                cout << value[b] - value[a] << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        solve(n, m);
    }

    return 0;
}