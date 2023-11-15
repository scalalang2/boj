#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

ll dp[70];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i <= 69; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}