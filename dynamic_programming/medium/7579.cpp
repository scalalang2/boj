#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N, M;
int memories[101];
int costs[101];

int dp[101][10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> memories[i];
    for(int i = 1; i <= N; i++) cin >> costs[i];

    /*
     * 5 60
     * 30 10 20 35 40
     * 3 0 3 5 4
     * */

    // 일부를 비 활성화 하여 M 이상의 메모리를 확보해야한다.
    // M이상이 될때의 최소 비용을 구해야 함
    // how..?

    for(int i = 1; i <= N; i++) {
        for(int c = 0; c <= 10000; c++) {
            if(c - costs[i] >= 0) dp[i][c] = max(dp[i-1][c-costs[i]] + memories[i], dp[i-1][c]);
            else dp[i][c] = dp[i-1][c];
        }
    }

    for(int i = 0; i <= 10000; i++) {
        if(dp[N][i] >= M) {
            cout << i;
            break;
        }
    }

    return 0;
}