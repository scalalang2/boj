#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

ll X;
ll dp[1000001];
ll trace[1000001];

// 관전 포인트
// f(x) = 1부터 x까지 만들기 위한 최소 연산 회수
// 문제에서는 1로만들기 위한 회수를 구하라고 했지만, 코딩 편의상 반대로 뒤집어서 생각해도 되는 거였다.
//
// 그리고, ll& 연산자로 주소를 따온다음에 값을 직접 갱신해도 된다.
ll f(ll x) {
    if(x == 0) return llINF;
    if(x == 1) return 0;
    ll& ret = dp[x];
    if(ret != -1) return ret;

    ret = llINF;
    if(x % 3 == 0 && (ret > f(x/3) + 1)) {
        ret = f(x/3) + 1;
        trace[x] = x/3;
    }
    if(x % 2 == 0 && (ret > f(x/2) + 1)) {
        ret = f(x/2) + 1;
        trace[x] = x/2;
    }
    if(ret > f(x-1) + 1) {
        ret = f(x-1) + 1;
        trace[x] = x-1;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> X;
    memset(dp, -1, sizeof(dp));
    cout << f(X) << endl;
    while(X != 0) {
        cout << X << " ";
        X = trace[X];
    }

    return 0;
}