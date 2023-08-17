#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

const int INF = 1e9 + 5;
const ll llINF = 1e18;

int n;
struct point {
    int x,y,z;
};
vector<pair<point, point>> points;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    points.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].first.x;
        cin >> points[i].first.y;
        cin >> points[i].first.z;
        cin >> points[i].second.x;
        cin >> points[i].second.y;
        cin >> points[i].second.z;
    }

    point amin,amax;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            amin = points[i].first;
            amax = points[i].second;
            continue;
        }
        // 가장 큰게 가장 작은것보다 작다면
        point bmin,bmax;
        bmin = points[i].first;
        bmax = points[i].second;
        bool collided = amin.x <= bmax.x && amax.x >= bmin.x && amin.y <= bmax.y && amax.y > bmin.y && amin.z <= bmax.z && amax.z >= bmin.z;
        if(!collided) {
            cout << 0 << endl;
            return 0;
        }
        amin = {max(amin.x, bmin.x), max(amin.y, bmin.y), max(amin.z, bmin.z)};
        amax = {min(amax.x, bmax.x), min(amax.y, bmax.y), min(amax.z, bmax.z)};
    }

    cout << (amax.x - amin.x) * (amax.y - amin.y) * (amax.z - amin.z) << endl;

    return 0;
}