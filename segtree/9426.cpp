#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N, K;
int arr[250001];

struct segtree {
    int size;
    vector<int> tree;

    segtree(int n) {
        size = 1;
        while(size < n) size *= 2;
        tree.resize(2 * size);
    }

    void update(int i, int d) {
        int idx = size + i;
        tree[idx] += d;
        while(idx >= 1) {
            idx /= 2;
            tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
        }
    }

    // L,R이 고정
    // low, high가 변동
    int query(int root, int L, int R, int val) {
        if(L == R) return L;
        int mid = (L + R) / 2;
        int left_node = 2 * root;
        int right_node = 2 * root + 1;

        // 트리의 왼쪽보다 val이 더 크다면
        // 오른쪽에 있다는 것
        if(tree[left_node] < val) {
            return query(right_node, mid+1, R, val - tree[left_node]);
        } else {
            return query(left_node, L, mid, val);
        }
    }
};

// 중앙값 측정
// N개의 수 중, K개의 윈도우로 짤라서 정렬한 경우의 중앙값을 갱신하면서 계속 업데이트하기
// 세그먼트 트리를 쓸건데 중앙값을 어떻게 구할 수 있을까?

// 원하는 타겟은 정확히 (K+1)/2 에 존재하는 값임
// 일단 수의 값이 1~65535 일 뿐이니 각 수마다 개수를 세는 세그먼트 트리를 준비한다.
// 구간에 쿼리를 할건데 구간을 절반을 잘라서 왼쪽에 있는 값의 개수가 타겟값 T보다 크다면?
// 우리가 원하는 타겟값은 왼쪽 구간에 존재한다는 걸 의미하고 반대인 경우에는 오른쪽에 있다는 걸 의미함
// 우측으로 이동할 때는 왼쪽에 있는 걸 빼고 이동한다

// 세그먼트 트리로 원하는 위치의 값을 찾는 테크닉 기억할 필요가 있음
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> arr[i];

    segtree seg(65536);
    ll ans = 0;
    for(int i = 0; i < K-1; i++) seg.update(arr[i], 1);
    for(int i = K-1; i < N; i++) {
        seg.update(arr[i], 1);
        ans += seg.query(1, 0, 65535, (K+1)/2);
        seg.update(arr[i-(K-1)], -1);
    }

    cout << ans << endl;
    return 0;
}