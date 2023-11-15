#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

string s;

struct segtree {
    int size;
    vector<int> tree;
    segtree(int n) {
        size = 1;
        while(size < n) size <<= 1;
        tree.resize(size*2, 0);
    }

    int get(int idx) {
        return tree[idx+size];
    }

    void update(int idx, int val) {
        idx += size;
        tree[idx] = val;
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

vector<segtree> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> s;
    st.resize(26, segtree(s.size()));
    for(int i = 0; i < s.size(); i++) {
        st[s[i]-'a'].update(i, 1);
    }

    int q;
    cin >> q;
    while(q--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        cout << st[c-'a'].query(1, 1, st[c-'a'].size, l+1, r+1) << "\n";
    }

    return 0;
}