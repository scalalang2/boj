#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N;
double dp[1000002];

double f(int n) {
    if (n <= 0) return 0.0;
    double &ret = dp[n];
    // 오차 때문에 -1.0을 그대로 비교하면 안된다.
    if(ret >= -0.5) return ret;
    ret = 0.0;
    for(int i = 1; i <= 6; i++)
        ret += (f(n-i) + 1)/6.0;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(dp, -1.0, sizeof(dp));
    cin >> N;
    cout << fixed;
    cout.precision(11);
    cout << f(N);

    return 0;
}