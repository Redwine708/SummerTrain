#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 10000010;

int n, k, ans = 0;
ll max_v = LONG_LONG_MIN, min_v = LONG_LONG_MAX, max_s = LONG_LONG_MIN, min_s = LONG_LONG_MAX;
ll s[MAX];
ll v[MAX];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
    {
        if ( (s[i] < s[k] && v[i] > v[k]) || (s[i] > s[k] && v[i] < v[k]))
        {
            max_v = max(v[i], max_v);
            min_v = min(v[i], min_v);
        }
        if (s[i] == s[k])
        {
            ans++;
            max_v = max(v[i], max_v);
            min_v = min(v[i], min_v);
        }
    }
    for (int i = 1; i <= n; i++)
        if ((s[i] < s[k] && v[i] > min_v) || (s[i] > s[k] && v[i] < max_v))
            ans++;
    cout << ans;
}

