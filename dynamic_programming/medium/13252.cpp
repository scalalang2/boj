#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

ll n,m,k;
double dm;

// dp[남은 칩][라운드] = K번 라운드에 남은 칩이 M개일 때의 최적의 승리 확률
double dp[51][51];

double f(ll chip, ll round) {
    if(round >= k) {
        // 칩이 남아있으면 무조건 승리한다.
        if(chip > 0) return 1;
        else return 0;
    }

    // 남은 칩이 없다면 확률은 0
    if(chip == 0) return 0;
    ll remain = chip % m;

    double &ret = dp[remain][round];
    if(ret != -1) return ret;
    ret = 0;

    // 칩이 M개의 영역보다 적게 남은 경우
    if(chip < m) {
        // 칩이 하나 따인 상태로 다음 라운드로 가는 경우의 수 = 칩의 개수 / M
        ret += f(chip-1, round+1) * (((double) chip) / dm);

        // 칩이 하나도 안따인 상태로 다음 라운드로 가는 경우의 수 = (M - 칩의 개수) / M
        ret += f(chip, round+1) * (((double) (m - chip)) / dm);
    } else {
        if(chip % m == 0) {
            // 골고루 배분하는 경우에는 무조건 승리하기 때문에 확률은 100% 인 상태로 칩만 제거되고 다음으로 넘어감
            ret += f(chip - (chip/m), round+1);
        } else {
            // 평평하게 배분할 때 (chip/m) 혹은 (chip/m)+1 개의 칩이 M개의 영역에 배분된다.
            // 여기서는 (chip/m) 만큼의 확률을 다룸
            // 1개씩 더 있을 경우의 수는 remain, 아닌 경우의 수는 m-remain
            ret += f(chip - (chip/m), round+1) * (((double) (m - remain)) / dm);

            ret += f(chip - (chip/m) - 1, round+1) * (((double) remain) / dm);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    dm = (double)m;
    fill(&dp[0][0], &dp[50][51], -1);
    cout.precision(10);
    cout << f(n,0);

    return 0;
}