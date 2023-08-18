#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, j, c;
int balances[51];

// 은행 계좌에 담긴 돈만큼 티켓을 지급하고, 당첨된 사람에겐 J원을 준다.
// c주가 지난 후의 내 잔고의 기댓값을 출력하기
// 여기서 나란 balances[0]을 말한다.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;

    memset(balances, 0, sizeof(balances));
    for(int i = 1; i <= n; i++) cin >> balances[i];
    cin >> j >> c;

    // 내 첫 잔고의 기댓값
    double my_balance = balances[1];

    // 총 잔고
    double total = 0;
    for(int i = 1; i <= n; i++) total += balances[i];

    double dj = (double)j;

    for(int i = 0; i < c; i++) {
        // 내 잔고의 기댓값 = (현재 잔고의 기댓값/전체 잔고의 액수) * J
        // 왜냐면 못받았을 때는 0원을 받게되니 기댓값 확률 변수에서 제외시켜도 가능하다.
        my_balance += (my_balance / total) * dj;

        // 전체 잔고의 액수 갱신
        total += dj;
    }

    cout.precision(10);
    cout << my_balance;

    return 0;
}