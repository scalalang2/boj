#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N;
int P[1001];
int dp[1001];

int f(int n) {
    if(n == 0) return 0;
    int &ret = dp[n];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 1; i <= n; i++) {
        ret = min(ret, f(n-i) + P[i]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> P[i];
    memset(dp, -1, sizeof(dp));

    // 카드 i 개를 사기 위해 필요한 가격은 P[i]
    // 상태 공간을 생각해보자면
    // 카드 2개를 갖고 있는 상태에서 카드 3개를 지불하는 경우 (?)
    // f(N) = f(N-1) + P[1], f(N-2) + P[2], ... , f(1) + P[N-1], P[N]중에서의 최솟값을 계산하는 것
    // top down 방식으로 계산할 수 있으니 괜찮을지도

    cout << f(N) << endl;

    return 0;
}