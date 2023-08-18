#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, ans;
int A[1001];
int dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];

    fill(dp, dp+1001, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= A[i]; j++) {
            if(i+j >= n) continue;
            dp[i+j] = min(dp[i+j], dp[i] + 1);
        }
    }

    if(dp[n-1] == INF) cout << -1;
    else cout << dp[n-1];


    return 0;
}