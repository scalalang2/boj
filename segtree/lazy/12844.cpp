#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N, sz;
ll arr[500001];
vector<ll> tree;
vector<ll> lazy;

void init() {
    sz = 1;
    while(sz < N) sz <<= 1;
    tree.resize(sz * 2);
    lazy.resize(sz * 2);

    for(int i = 0; i < N; i++) tree[sz + i] = arr[i];
    for(int i = sz - 1; i > 0; i--) tree[i] = tree[i * 2] ^ tree[i * 2 + 1];
}

void prop(int node, int l, int r) {
    if(lazy[node] != 0) {
        if(l != r) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        } else {
            tree[node] ^= lazy[node];
        }

        lazy[node] = 0;
    }
}

void update(int node, int s, int e, int l, int r, ll val) {
    prop(node, l, r);
    if(r < s || e < l) return;
    if(s <= l && r <= e) {
        lazy[node] ^= val;
        prop(node, l, r);
        return;
    }

    int mid = (l+r)/2;
    update(node*2, s, e, l, mid, val);
    update(node*2+1, s, e, mid+1, r, val);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}

ll query(int node, int s, int e, int l, int r) {
    prop(node, l, r);
    if(r < s || e < l) return 0;
    if(s <= l && r <= e) return tree[node];
    int mid = (l+r)/2;
    return query(node*2, s, e, l, mid) ^ query(node*2+1, s, e, mid+1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    init();

    int Q, a, b, c;
    ll d;
    cin >> Q;
    while(Q--) {
        cin >> a;
        if(a == 1) {
            cin >> b >> c >> d;
            update(1, b+1, c+1, 1, sz, d);
        } else {
            cin >> b >> c;
            cout << query(1, b+1, c+1, 1, sz) << '\n';
        }
    }

    return 0;
}