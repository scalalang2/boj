#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

bool prime(ll num) {
    if(num <= 1) return false;
    for(ll i = 2; i * i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        while(!prime(n)) n++;
        cout << n << '\n';
    }


    return 0;
}