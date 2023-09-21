#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n;
int t[1500001];
int p[1500001];
vector<int> dp(1500001, 0);

// rotate 90 degree
void rotate(vector<vector<int>> &image, int n) {
    vector<vector<int>> tmp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tmp[j][n-i-1] = image[i][j];
        }
    }
    image = tmp;
}

void horizontal_flip(vector<vector<int>> &image, int n) {

}

/*
 * 상담할 때 t일이 걸리는데 비용을 p만큼 준다.
 * 어떻게 보면 클래식한 배낭 문제랑 비슷 비슷하네
 * 1일차에서 얻을 수 있는 비용 = 10
 * 2일차에서 얻을 수 있는 비용 = 20
 * 3일차에서 얻을 수 이는 비용 = 10 => 내 상담을 진행 + (이전에 얻을 수 있었던 상담 비용)
 * 4일차 = 3일차 + 4일차 or 1일차 + 4일차 = 30
 *
 * 먹거나 이전 걸 가져오거나
 * dp[i+t] = max(dp[i+t] + p[i], dp[i+1])
 *
 * */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    for(int i = n; i >= 1; i--) {
        if(i + t[i] > n + 1) {
            dp[i] = dp[i+1];
        } else {
            dp[i] = max(dp[i+1], p[i] + dp[i+t[i]]);
        }
    }
    cout << dp[1];

    return 0;
}