#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;
const ll MOD = 1000000009;

ll dp[100001][4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 4는 1,2,3 으로 나타낼 방법이 3가지 인데 2개 이상 연속사용하면 안된다.
    // 1 + 2 + 1
    // 1 + 3
    // 3 + 1
    // 어떤 신이 f(N, k)을 미리 계산했는데, N을 1,2,3의 합으로 나타내는 방법의 수이고, 마지막에 사용한 수를 k라고 하자.
    // f(N, 1) = f(N-1, 2) + f(N-1, 3)
    // f(N, 2) = f(N-2, 1) + f(N-2, 3)
    // f(N, 3) = f(N-3, 1) + f(N-3, 2)
    // 이렇게 점화식을 세운다.
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][3] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;

    for(int i = 4; i <= 100000; i++) {
        dp[i][1] = (dp[i-1][2]%MOD + dp[i-1][3]%MOD)%MOD;
        dp[i][2] = (dp[i-2][1]%MOD + dp[i-2][3]%MOD)%MOD;
        dp[i][3] = (dp[i-3][1]%MOD + dp[i-3][2]%MOD)%MOD;
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << (dp[n][1] + dp[n][2] + dp[n][3])%MOD << '\n';
    }


    return 0;
}