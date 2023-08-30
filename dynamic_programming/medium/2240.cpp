#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

/**
 * 자두는 자두를 좋아한대요
 * 두 개의 자두나무가 있는데
 * T초동안 자두가 떨어지는 나무가 주어질때
 * 받아낼 수 있는 경우의 수를 최대화 해라
 *
 * 근데 옮길 수 있는 최대 회수 W가 제한되어 있음
 *
 * 1초에 먹을 수 있는 회수 = 1
 * 2초에 먹을 수 있는 회수 = 1
 * 3초에 먹을 수 있는 회수 = 3 (가만히있다가 1초에 이동하는 경우)
 * 그럼 결국 현재 상태에서 [이동해서 먹을 수 있는 회수 + 가만히 있어서 먹을 수 있는 회수]인데 상태란 W값이 되겠지
 *
 * t초에 w상태일때 먹을 수 있는 회수
 * w%2 == 0 > 1, w%2 == 1 > 1
 *
 * 7 2
 * 2 1 1 2 2 1 1
 *
 *   2 1 1 2 2 1 2 2
 *   0 0 1 2 2 2 3 4
 *   1 1 1 1 3 4 4 4
 *   2 X 2 3 3 3 5 6
 *
 *   dp[w][t] = dp[w-1][t-1] + w%2 == 0 || w%2 == 1
 * */
int T, W;
int A[1001];
int dp[31][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T >> W;
    for(int i = 1; i <= T; i++) cin >> A[i];

    dp[0][1] = 0;
    for(int w = 0; w <= W; w++) {
        for(int t = 1; t <= T; t++) {
            if(t < w) continue;
            int a = 0;
            if(w%2 == 0 && A[t] == 1) a = 1;
            if(w%2 == 1 && A[t] == 2) a = 1;
            if(w == 0) {
                    dp[w][t] = dp[w][t-1] + a;
                continue;
            }
            dp[w][t] = max(dp[w][t-1] + a, dp[w-1][t-1]+a);
        }
    }

    int ans = 0;

    // 아하 안 움직이면서 다 쳐먹는 경우까지 생각해야지 바보야
    for(int w = 0; w <= W; w++)
        ans = max(ans, dp[w][T]);
    cout << ans << endl;

    return 0;

}