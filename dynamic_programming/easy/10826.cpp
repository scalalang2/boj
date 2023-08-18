#include<bits/stdc++.h>

using namespace std;

using ll = unsigned long long int;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n;
ll dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    cin >> n;
    for(int i = 3; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];

    cout << dp[n];

    return 0;
}