#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c;
    while(1){
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        if(a > b) swap(a, b);
        if(b > c) swap(b, c);

        // 제곱이니까 pow 함수 없이 그냥 곱 2개 쓰기
        if(a*a + b*b == c*c) cout << "right\n";
        else cout << "wrong\n";
    }

    return 0;
}