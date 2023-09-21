#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int mxn = 1000000;

const int INF = 1e9 + 5;
const ll llINF = 1e18;
bool che[mxn+1];
vector<int> primes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    che[0] = true;
    che[1] = true;
    for(int i = 2; i <= 1000000; i++) {
        if(!che[i]) {
            primes.push_back(i);
            for(int j = 2*i; j <= 1000000; j += i) {
                che[j] = true;
            }
        }
    }

    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        set<pi> ans;
        for(auto p : primes) {
            if(p >= N) break;
            if(!che[N-p]) {
                ans.insert({min(p, N-p), max(p, N-p)});
            };
        }
        cout << ans.size() << endl;
    }
    return 0;
}