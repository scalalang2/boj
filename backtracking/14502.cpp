#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int N, M;
int cnt = 0;
int total = 0;
int ans = 0;
const int mxn = 8;
int board[mxn][mxn];
bool check[mxn][mxn] = {false,};
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
vector<pi> virus;

bool inrange(int y, int x) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

int safe_area() {
    int ret = 0;
    queue<pi> p;
    vector<vector<bool>> infected(mxn, vector<bool>(mxn, false));
    for(auto &i : virus) {
        p.push(i);
        infected[i.first][i.second] = true;
    }
    while(!p.empty()) {
        auto [y, x] = p.front();
        p.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(!inrange(ny, nx)) continue;
            if(infected[ny][nx]) continue;
            if(board[ny][nx] == 1) continue;
            infected[ny][nx] = true;
            p.emplace(ny, nx);
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(board[i][j] == 0 && !infected[i][j]) ret++;
        }
    }

    return ret;
}

void search() {
    if(cnt == 3) {
        ans = max(ans, safe_area());
        return;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(cnt == 3) continue;
            if(board[i][j] != 0) continue;
            if(check[i][j]) continue;
            board[i][j] = 1;
            check[i][j] = true;
            cnt++;
            search();
            cnt--;
            check[i][j] = false;
            board[i][j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) virus.emplace_back(i, j);
        }
    }

    search();
    cout << ans;

    return 0;
}