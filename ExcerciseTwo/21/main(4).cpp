#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int main() {
    int n, k, i, ans = 0; cin >> n >> k;
    vector<pair<int, int> > path(n);
    for (i = 0; i < n; i++) {scanf("%d", &path[i].first);}
    for (i = 0; i < n; i++) {scanf("%d", &path[i].second);}
    i = 0;
    int loc = path[k - 1].first;
    sort(path.begin(), path.end(), cmp);
    while (path[i].first < loc) i++;
    int m = i - 1;
    while (path[i].first == loc) {ans++; i++;}
    int mm = i;
    int speed1 = path[m + 1].second, speed2 = path[mm - 1].second;
    int ma_s = speed2, mi_s = speed1;
    i = 0;
    while (i <= m) {
        if (speed1 < path[i].second) ans++;
        ma_s = max(ma_s, path[i].second);
        i++;
    }
    i = mm;
    while (i < n) {
        if (speed2 > path[i].second) ans++;
        mi_s = min(mi_s, path[i].second);
        i++;
    }
    if (ma_s > speed2) {
        for (i = mm; i < n; i++){
            if (loc == path[i].first) continue;
            if (path[i].second >= speed2 && path[i].second < ma_s) ans++;
        }

    }
    if (mi_s < speed1) {
        for (i = m; i >= 0; i--) {
            if (loc == path[i].first) continue;
            if (path[i].second <= speed1 && path[i].second > mi_s) ans++;
        }
    }
    cout << ans;
}