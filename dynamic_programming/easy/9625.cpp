#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int k;
int dp[46][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k;
    dp[0][0] = 1;
    dp[0][1] = 0;

    for(int i = 1; i <= k; i++) {
        // A
        dp[i][0] = dp[i-1][1];
        // B;
        dp[i][1] = dp[i-1][0] + dp[i-1][1];
    }

    cout << dp[k][0] << " " << dp[k][1];

    return 0;
}