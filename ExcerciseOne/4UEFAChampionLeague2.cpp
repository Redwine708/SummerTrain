#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
bool cmp(pair<string, pair<int, int> > a, pair<string, pair<int, int> > b) {
    if (a.second.first == b.second.first) return a.second.second > b.second.second;
    return a.second.first > b.second.first;
}
int main() {
    int n;
    cin >> n;
    while (n) {
        unordered_map<string, pair<int, int>> score;
        vector<pair<string, pair<int, int> > > ans;
        string a, b;
        int a1, b1;
        for (int i = 0; i < 12; i++) {
            cin >> a >> a1 >> b >> b1 >> b;
            if (a1 == b1) {score[a].first++; score[b].first++;}
            else if (a1 > b1) {score[a].first += 3; score[a].second += (a1 - b1); score[b].second -= (a1 - b1);}
            else {score[b].first += 3; score[b].second += (b1 - a1); score[a].second -= (b1 - a1);}
        }
        pair<string, pair<int, int> > it;
        for (auto& v : score) {
            ans.push_back(v);
        }
        sort(ans.begin(), ans.end(), cmp);
        cout << ans[0].first << " " << ans[1].first << endl;
        n--;
    }
}