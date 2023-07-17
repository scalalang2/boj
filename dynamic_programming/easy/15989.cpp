#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

const int mxn = 10001;
int dp[mxn][4] = {0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp[0][1] = 1;
    dp[1][1] = 1;
    for(int i = 2; i <= 10000; i++) {
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        if(i >= 3)
            dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
    }

    return 0;
}