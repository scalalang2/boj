#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n;
int A[100001];
int U[100001];
int D[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> A[i];

    U[1] = 1;
    D[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(A[i] >= A[i-1]) U[i] = U[i-1] + 1;
        else U[i] = 1;

        if(A[i] <= A[i-1]) D[i] = D[i-1] + 1;
        else D[i] = 1;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, U[i]);
        ans = max(ans, D[i]);
    }

    cout << ans << endl;

    return 0;
}