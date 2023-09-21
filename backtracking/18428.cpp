#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N;
set<pi> cand_set;
vector<pi> cands;
vector<bool> vis;
vector<pi> teachers;
char board[6][6];
int cnt = 0;

bool inrange(int y, int x) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void add_candidates(int y, int x) {
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        while(inrange(ny, nx) && board[ny][nx] != 'S' && board[ny][nx] != 'T') {
            cand_set.insert({ny, nx});
            ny += dy[i];
            nx += dx[i];
        }
    }
}

bool teacher_can_watch_s() {
    for(auto [y, x] : teachers) {
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            while(inrange(ny, nx) && board[ny][nx] != 'O' && board[ny][nx] != 'T') {
                if(board[ny][nx] == 'S') {
                    return true;
                }
                ny += dy[i];
                nx += dx[i];
            }
        }
    }

    return false;
}

void backtrack() {
    if(!teacher_can_watch_s()) {
        cout << "YES" << endl;
        exit(0);
    }

    for(int i = 0; i < cands.size(); i++) {
        if(vis[i]) continue;
        if(cnt == 3) continue;
        cnt++;
        vis[i] = true;
        board[cands[i].first][cands[i].second] = 'O';
        backtrack();
        board[cands[i].first][cands[i].second] = 'X';
        vis[i] = false;
        cnt--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // 선생님을 기준으로 장벽을 세울 수 있는 곳에 위치시킨다.
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(board[i][j] == 'T') {
                add_candidates(i, j);
                teachers.emplace_back(i, j);
            }
        }
    }

    for(auto it = cand_set.begin(); it != cand_set.end(); it++) {
        cands.push_back(*it);
    }
    vis.resize(cands.size(), false);

    backtrack();
    cout << "NO" << endl;

    return 0;
}