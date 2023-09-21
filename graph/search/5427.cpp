#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int t;
int h, w;
int sy, sx;
int MAP[101][101];
int dist[101][101];
int dist2[101][101];
int fire[101][101];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1 ,0 ,0};
vector<pi> fires;

void clear() {
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            dist[i][j] = INF;
            dist2[i][j] = INF;
            fire[i][j] = INF;
        }
    }

    fires.clear();
}

void init() {
    for(int i = 0 ; i < h ; i++) {
        for(int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if(c == '.') {
                MAP[i][j] = 0;
            } else if(c == '#') {
                MAP[i][j] = 1;
            } else if(c == '@') {
                MAP[i][j] = 0;
                sy = i;
                sx = j;
            } else {
                MAP[i][j] = 2;
                fires.emplace_back(i, j);
            }
        }
    }
}

void start_fire() {
    queue<pi> Q;
    for(auto &f : fires) {
        cout << "fire!!!" << f.first << " " << f.second << endl;
        Q.emplace(f.first, f.second);
        dist[f.first][f.second] = 1;
    }

    while(!Q.empty()) {
        auto[cy, cx] = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(MAP[ny][nx] >= 1) continue;
            if(fire[ny][nx] < fire[cy][cx] + 1) continue;
            fire[ny][nx] = fire[cy][cx] + 1;
            Q.emplace(ny, nx);
        }
    }
}

void run_sanguen() {
    queue<pi> Q;
    Q.emplace(sy, sx);
    dist[sy][sx] = 1;
    while(!Q.empty()) {
        auto[cy,cx] = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(MAP[ny][nx] >= 1) continue;
            if(dist[ny][nx] < dist[cy][cx] + 1) continue;
            dist[ny][nx] = dist[cy][cx] + 1;
            Q.emplace(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    while(t--) {
        cin >> w >> h;
        clear();
        init();
        start_fire();

        int ans = INF;
        queue<pi> Q;
        Q.emplace(sy, sx);
        dist2[sy][sx] = 1;

        while(!Q.empty()) {
            auto [cy, cx] = Q.front();
            Q.pop();

            for(int i = 0; i < 4; i++) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                if(MAP[ny][nx] != 0) continue;
                if(dist2[ny][nx] < dist2[cy][cx] + 1) continue;
                if(dist2[cy][cx] + 1 > fire[ny][nx]) continue;
                dist2[ny][nx] = dist2[cy][cx] + 1;

                printf("ny: %d, nx: %d, dist: %d, fire: %d m[ny][nx]: %d \n", ny, nx, dist2[ny][nx], fire[ny][nx], MAP[ny][nx]);
                Q.emplace(ny, nx);
            }
        }

        for(int i = 0; i < w; i++) {
            if(dist2[0][i] != INF) ans = min(ans, dist2[0][i]);
            if(dist2[h-1][i] != INF) ans = min(ans, dist2[h-1][i]);
        }
        for(int i = 0; i < h; i++) {
            if(dist2[i][0] != INF) ans = min(ans, dist2[i][0]);
            if(dist2[i][w-1] != INF) ans = min(ans, dist2[i][w-1]);
        }

        if(ans == INF) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }

    return 0;
}