#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N, K;
vector<tuple<int, int, int>> scores;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tg, ts, tb;

    cin >> N >> K;
    scores.resize(N);
    for(int i = 0; i < N; i++) {
        int nation, gold, silver, bronze;
        cin >> nation >> gold >> silver >> bronze;
        scores[nation-1] = {gold, silver, bronze};
        if(nation == K) {
            tg = gold;
            ts = silver;
            tb = bronze;
        }
    }

    sort(scores.begin(), scores.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
        int ag, as, ab;
        int bg, bs, bb;
        tie(ag, as, ab) = a;
        tie(bg, bs, bb) = b;

        if(ag == bg && as == bs) {
            return ab > bb;
        } else if(ag == bg) {
            return as > bs;
        } else {
            return ag > bg;
        }
    });

    int i = 0;
    for(auto [a, b, c] : scores) {
        if(a > tg) {
            i++;
        } else if(a == tg && b > ts) {
            i++;
        } else if(a == tg && b == ts && c > tb) {
            i++;
        } else if(a == tg && b == ts && c == tb) {
            cout << i + 1;
            return 0;
        }
    }

    cout << 1 << endl;

    return 0;
}