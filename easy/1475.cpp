#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int cnt[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string x;
    cin >> x;

    for(int i = 0; i < x.size(); i++) {
        cnt[x[i] - '0']++;
    }

    int A = cnt[6] + cnt[9];
    int mxn = 0;
    for(int i = 0; i <= 9; i++) {
        if(i == 6 || i == 9) continue;
        mxn = max(mxn, cnt[i]);
    }

    cout << max(A / 2 + A % 2, mxn);


    return 0;
}