#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

// 사람에 따른 스코어
int scores[51][9];
bool check[9];
vector<int> order;
int n;
int ans = 0;

int play() {
    vector<int> players;
    int i = 0;
    for(auto c : order) {
        if(i == 3) {
            players.push_back(0);
            players.push_back(c);
        }
        else players.push_back(c);
        i++;
    }

    int curr = 0;
    int games = 0;
    int score = 0;
    while(games < n) {
        int out = 0;
        int base[3] = {0, 0, 0};
        while(out < 3) {
            int player = players[curr % 9];
            int result = scores[games][player];
            if(result == 0) {
                out++;
            } else if(result == 1) {
                score += base[2];
                base[2] = base[1];
                base[1] = base[0];
                base[0] = 1;
            } else if(result == 2) {
                score += base[2] + base[1];
                base[2] = base[0];
                base[1] = 1;
                base[0] = 0;
            } else if(result == 3) {
                score += base[2] + base[1] + base[0];
                base[2] = 1;
                base[1] = 0;
                base[0] = 0;
            } else if(result == 4) {
                score += base[2] + base[1] + base[0] + 1;
                base[2] = 0;
                base[1] = 0;
                base[0] = 0;
            }
            curr++;
        }
        games++;
    }
    return score;
}

void run() {
    if(order.size() == 8) {
        ans = max(ans, play());
        return;
    }

    for(int i = 1; i < 9; i++) {
        if(check[i]) continue;
        check[i] = true;
        order.push_back(i);
        run();
        order.pop_back();
        check[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> scores[i][j];
        }
    }

    run();
    cout << ans << endl;

    return 0;
}