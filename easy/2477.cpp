#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N;
int arr[8][4];
int cnt[4];

// 방향
// 1: 동쪽, 2: 서쪽, 3: 남쪽, 4: 북쪽
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int s = 1, b = 1;
    cin >> N;
    for(int i = 0; i < 6; i++) {
        cin >> arr[i][0] >> arr[i][1];
        cnt[arr[i][0]]++;
    }

    for(int i = 0; i < 6; i++) {
        // 방향 당 한번 등장하는게 가장 큰 변
        if(cnt[arr[i][0]] == 1) {
            b *= arr[i][1];
            continue;
        }

        // 방향당 두번씩 등장하는게 작은 변임
        int n = (i + 1) % 6;
        int p = (i + 2) % 6;
        if(arr[i][0] == arr[p][0]) s *= arr[n][1];
    }

    cout << (b - s) * N;

    return 0;
}