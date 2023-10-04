#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int sz;
vector<ll> tree;
vector<ll> lazy;

int N, M, K;

void init() {
    int size = 1;
    while(size < N) size *= 2;
    tree.resize(2 * size);
    lazy.resize(2 * size);
    sz = size;
}

// 이건 인덱스가 0부터 시작
void update(int idx, ll val) {
    tree[idx] += val;
    idx /= 2;
    while(idx >= 1) {
        tree[idx] = tree[2*idx] + tree[2*idx+1];
        idx /= 2;
    }
}

// 구간 [s, e]인 idx의 lazy 값을 전파한다.
void prop(int idx, int s, int e) {
    if(lazy[idx] != 0) {
        // 리프노드가 아니라면 자식에게 레이지 값을 전파
        if(s != e) {
            lazy[idx * 2] += lazy[idx];
            lazy[idx * 2 + 1] += lazy[idx];
        }
        // 본인의 레이지 값을 갱신하는데
        // (e-s) <- 구간에 포함된 원소의 개수 * 레이지 값
        // 즉, 구간에 반영해야 할 전체합이라 하겠다.
        tree[idx] += (e - s + 1) * lazy[idx];

        // 반영했으면 레이지값 초기화
        lazy[idx] = 0;
    }
}

void add(int node, int s, int e, int l, int r, ll val) {
    // 레이지 값을 전파한다
    prop(node, l, r);

    if(r < s || e < l) return;
    if(s <= l && r <= e) {
        // 구간에 완전히 포함된다면, 레이지 값을 부여하고 갱신
        // 즉 기존에는 트리를 직접 변경하는 거였다면
        // 여기는 구간 정보의 값만 업데이트하고 자식 노드로 전파하는 거지
        // 자식의 값을 개별적으로 업데이트 하는게 아니라
        lazy[node] += val;
        prop(node, l, r);
        return;
    }

    // 이건 구간에 포함되지 않은 값들을 계산하는 공간
    int mid = (l+r)/2;
    add(node*2, s, e, l, mid, val);
    add(node*2+1, s, e, mid+1, r, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int node, int s, int e, int l, int r) {
    prop(node, l, r);
    if(r < s || e < l) return 0;
    if(s <= l && r <= e) return tree[node];
    int mid = (l+r)/2;
    return query(node*2, s, e, l, mid) + query(node*2+1, s, e, mid+1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;

    init();
    for(int i = 0; i < N; i++) {
        ll x;
        cin >> x;
        update(sz + i, x);
    }

    int a, b, c;
    ll d;
    for(int i = 0; i < M + K; i++) {
        cin >> a;
        if(a == 1) {
            cin >> b >> c >> d;
            // 구간 업데이트
            add(1, b, c, 1, sz, d);
        } else {
            cin >> b >> c;
            // 구간 정보 조회
            cout << query(1, b, c, 1, sz) << '\n';
        }
    }

    return 0;
}