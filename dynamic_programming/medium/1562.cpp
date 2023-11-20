#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

ll MOD = 1000000000;
int N;
ll dp[101][11][1<<11];

ll f(int len, int num, int state) {
    if(len == N) {
        if(state == (1<<10)-1) return 1;
        else return 0;
    }
    ll &ret = dp[len][num][state];
    if(ret != -1) return ret;

    ll cnt = 0;
    // -1 차이나는 경우
    if(num-1 >= 0) cnt += f(len+1, num-1, state | (1<<(num-1)));
    // +1 차이나는 경우
    if(num+1 < 10) cnt += f(len+1, num+1, state | (1<<(num+1)));
    cnt %= MOD;
    return ret = cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 11; j++) {
            for(int k = 0; k < (1<<11); k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    cin >> N;
    ll ans = 0;
    for(int i = 1; i <= 9; i++) {
        // 1번 자리에 i가 먼저 오는 경우
        ans += f(1, i, 1<<i);
        ans %= MOD;
    }

    cout << ans;

    return 0;
}
