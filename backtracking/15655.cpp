#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n, m;
int arr[9];
int chk[9];

// i번째 숫자를 선택할지 안할지에 대한 것
void track(int idx) {
    int cnt = 0;
    for(int i = 0; i < n; i++) cnt += chk[i];
    if(cnt == m) {
        for (int i = 0; i < n; i++) {
            if(chk[i] == 1) cout << arr[i] << ' ';
        }
        cout << endl;
        return;
    }
    if(idx == n) return;

    chk[idx] = 1;
    track(idx+1);
    chk[idx] = 0;
    track(idx+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(chk, 0, sizeof(chk));

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    track(0);

    return 0;
}