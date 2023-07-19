/*
 * AtCoder F - Box in Box랑 유사한 문제
 * */
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

struct student {
    int a;
    int b;
    int c;
};

struct segtree {
    int size;
    vector<int> tree;
    segtree(int n) {
        size = 1;
        while(size < n) size <<= 1;
        tree.resize(size*2, INF);
    }

    int get(int idx) {
        return tree[idx+size];
    }

    void update(int idx, int val) {
        idx += size;
        tree[idx] = val;
        while(idx > 1) {
            idx /= 2;
            tree[idx] = min(tree[idx*2], tree[idx*2+1]);
        }
    }

    int query(int pos, int l, int r, int s, int e) {
        if(r < s || e < l) return INF;
        if(s <= l && r <= e) return tree[pos];
        int mid = (l + r) / 2;
        return min(query(pos*2, l, mid, s, e), query(pos*2+1, mid+1, r, s, e));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s;
    cin >> n;
    vector<student> v(n);
    for(int i = 0; i < n; i++) {
        cin >> s;
        v[s-1].a = i+1;
    }
    for(int i = 0; i < n; i++) {
        cin >> s;
        v[s-1].b = i+1;
    }
    for(int i = 0; i < n; i++) {
        cin >> s;
        v[s-1].c = i+1;
    }

    sort(v.begin(), v.end(), [](student &a, student &b) {
        return a.a < b.a;
    });
    segtree seg(n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int mn = seg.query(1, 1, seg.size, 1, v[i].b-1);
        if(mn > v[i].c) ans++;
        seg.update(v[i].b-1, v[i].c);
    }
    cout << ans << endl;

    return 0;
}