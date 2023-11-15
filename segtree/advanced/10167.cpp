#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

// https://blog.naver.com/kks227/220605936611 블로그 참고
const int SIZE = 8192;
typedef tuple<int, int, int> P;

// 사실상 세그 트리
struct segtree {
    int sz, start;
    ll sum[SIZE], lsum[SIZE], rsum[SIZE], maxsum[SIZE];

    segtree(int n) {
        sz = n;
        start = 1;
        while(start < sz) start *= 2;
        clear();
    }

    void clear() {
        for(int i = 0; i < SIZE; i++) {
            sum[i] = lsum[i] = rsum[i] = maxsum[i] = 0;
        }
    }

    void update(int i, int x) {
        i += start;
        // 각 4개의 트리의 리프 노드를 갱신하는 ㅗㅋ드
        sum[i] = lsum[i] = rsum[i] = maxsum[i] += x;

        i /= 2;
        while(i > 0) {
            int l = i * 2;
            int r = i * 2 + 1;
            sum[i] = sum[l] + sum[r];
            lsum[i] = max(lsum[l], sum[l] + lsum[r]);
            rsum[i] = max(rsum[r], sum[r] + rsum[l]);
            maxsum[i] = max(max(rsum[l]+lsum[r], sum[i]), max(maxsum[l], maxsum[r]));
            i /= 2;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    ll result = 0;
    cin >> N;
    vector<P> point;
    for(int i = 0; i < N; i++) {
        int x,y,w;
        cin >> x >> y >> w;
        point.emplace_back(x,y,w);
    }

    // 좌표압축 수행
    int tx[3000];
    int newx = 0;
    sort(point.begin(), point.end());
    for(int i = 0; i < N; i++) {
        if(i > 0 && get<0>(point[i]) != get<0>(point[i-1])) newx++;
        tx[i] = newx;
    }

    for(int i = 0; i < N; i++) {
        int x,y,w;
        tie(x,y,w) = point[i];
        point[i] = {y, tx[i], w};
    }
    // y 에 대해 정렬
    sort(point.begin(), point.end());

    segtree seg(newx+1);
    for(int i = 0; i < N; i++) {
        int sy, sx, sw;
        tie(sy, sx, sw) = point[i];
        if(i > 0 && sy == get<0>(point[i-1])) continue;
        seg.clear();

        for(int j = i; j < N; j++) {
            int ey, ex, ew;
            tie(ey, ex, ew) = point[j];
            seg.update(ex, ew);

            if(j == N-1 || ey != get<0>(point[j+1]))
                result = max(result, seg.maxsum[1]);
        }
    }

    cout << result << endl;


    return 0;
}