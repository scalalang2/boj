#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

// Functional Graph 특성임을 인지하고 무조건 Cycle이 발생한다고 생각한 뒤에 접근해야 하는 문제
// Functional Graph = '방향 그래프' 에서 모든 정점이 나가는 간선이 1개씩 있는 경우
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(true) {
        ll n, a, b;
        cin >> n;
        if(n == 0) break;
        cin >> a >> b;
        unordered_map<ll, ll> cache;

        ll cur = 0;
        for(int i = 0; ;i++) {
            ll next = (((a * cur)%n * cur)%n + b)%n;
            if(cache.find(next) != cache.end()) {
                cout << n - i + cache[next] << "\n";
                break;
            } else {
                cache[next] = i;
                cur = next;
            }
        }
    }

    return 0;
}