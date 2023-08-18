#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

ll ans = 0;
int n;
ll rooms[250001];
ll dp[250001][2];

ll f(int cur, int flag) {
    if(cur > n) return 0;
    if(cur == n && flag) return 0;
    ll &ret = dp[cur][flag];
    if(~ret) return ret;
    if(rooms[cur] > 0) return ret=f(cur+1, flag);
    ret = 0;
    ret += max(f(cur+2, cur == 1 ? 1 : flag) + 1, f(cur+1, flag));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp, 0, sizeof(dp));

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> rooms[i];
        ans += rooms[i];
    }
    rooms[n+1]=rooms[1];

    for(int i = 0; i < 250001; i++) {
        for(int j = 0; j < 2; j++) {
            dp[i][j] = -1;
        }
    }
    cout << ans + f(1,0);

    return 0;
}