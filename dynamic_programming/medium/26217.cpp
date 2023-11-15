#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    double ans;
    for(double i = 1; i <= N; i++) ans += (double)N/i;
    cout << fixed;
    cout.precision(11);
    cout << ans;

    return 0;
}