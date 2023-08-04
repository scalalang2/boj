#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int t, n;
int dp[5002][5002];
int modn = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    dp[1][1] = 1;
    for(int i = 1; i <= 5000; i++) {
        for(int j = 0; j <= i; j++) {
            if(i == 1 && j == 1) continue;
            dp[i][j] = dp[i-1][j+1]%modn; // ) 닫는 괄호로 하나 줄이는 경우
            if(j > 0) dp[i][j] += dp[i-1][j-1]%modn; // ( 하나 여는 괄호 추가하는 경우
        }
    }

    cin >> t;
    while(t--){
        cin >> n;
        // 길이가 n인 괄호 문자열의 총 개수
        // dp[n][k] = 길이가 n이면서 k개의 '('를 가지는 괄호 문자열의 총 개수

        cout << dp[n][0]%modn << endl;
    }

    return 0;
}