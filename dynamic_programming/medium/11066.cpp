#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

// 해석 링크 : https://developerbee.tistory.com/97
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        // f(p, q) = p~q 까지의 연산 합산치
        // f(p, q) = min(f(p, p) + f(p+1, q), f(p, p+1) + f(p+2, q))

        // dp[P][Q] = P~Q 까지의 합산치
        vector<int> arr(501);
        vector<int> sum(501, 0);
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            // sum 같은 경우에는 한 번 더 분해를 하는거구나
            // a~d는 세가지 경우가 있음
            // 40, 30, 30, 50
            // (a+b) = 70
            // (c+d) = 80
            // (a+b+c+d) = 150
            // (a+b) + (c+d) + (a+b+c+d)

            // (a+b) = 70
            // (a+b+c) = 100
            // (a+b+c+d) == 150
            /// (a+b) + (a+b+c) + (a+b+c+d)
            sum[i] = sum[i-1] + arr[i];
        }

        vector<vector<int>>dp(501, vector<int>(501, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n-i; j++) {
                dp[j][i+j] = INF;
                for(int k = j; k < i + j; k++) {
                    dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + sum[i+j] - sum[j-1]);
                }
            }
        }

        cout << dp[1][n] << endl;
    }



    return 0;
}