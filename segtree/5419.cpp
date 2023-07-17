#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int t, n;

struct segtree {
    int size;
    vector<int> tree;

    segtree(int n) {
        size = 1;
        while(size < n) size <<= 1;
        tree.resize(2 * size, 0);
    }

    void add(int idx) {
        idx += size;
        tree[idx]++;
        while(idx > 1) {
            idx /= 2;
            tree[idx] = tree[idx*2] + tree[idx*2+1];
        }
    }

    int query(int pos, int l, int r, int s, int e) {
        if(r < s || e < l) return 0;
        if(s <= l && r <= e) return tree[pos];
        int mid = (l + r) / 2;
        return query(pos*2, l, mid, s, e) + query(pos*2+1, mid+1, r, s, e);
    }
};

// 5 3
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while(t--) {
        cin >> n;
        vector<pi> v;

        // 좌표 압축 수행
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            v.emplace_back(x, y);
        }

        sort(v.begin(), v.end(), [](pi &a, pi &b) {
            return a.second < b.second;
        });
        vector<int> ny(n);
        int idx = 0;
        for(int i = 0; i < n; i++) {
            if(i > 0 && v[i].second != v[i-1].second) idx++;
            ny[i] = idx;
        }
        for(int i = 0; i < n; i++) v[i].second = ny[i];

        segtree sg(n);
        sort(v.begin(), v.end(), [](pi &a, pi &b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        ll ans = 0;
        for(auto p : v) {
            ans += sg.query(1, 1, sg.size, p.second+1, sg.size);
            sg.add(p.second);
        }
        cout << ans << '\n';
    }

    return 0;
}