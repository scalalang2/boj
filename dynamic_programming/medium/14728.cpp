#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N, T;
// K = 공부 시간, S = 배점
int K[105], S[105];
int dp[105][10005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> T;
    for(int i = 1; i <= N; i++) {
        cin >> K[i] >> S[i];
    }

    for(int i = 1; i <= N; i++) {
        for(int t = 0; t <= 10000; t++) {
            if(t-K[i] >= 0) dp[i][t] = max(dp[i-1][t], dp[i-1][t-K[i]] + S[i]);
            else dp[i][t] = max(dp[i][t], dp[i-1][t]);
        }
    }

    int ans = 0;
    for(int t = 0; t <= T; t++) ans = max(ans, dp[N][t]);
    cout << ans << endl;

    return 0;
}