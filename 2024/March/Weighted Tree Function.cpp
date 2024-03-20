#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define t_times int t; cin >> t; while(t--)
#define int long long
const int MOD = 1000000000 + 7;
const int N = 2e5 + 22;

int n, m, k, sz[N], root[N];
int sum[N];

int _find(int x) {
    if (root[x] != x) root[x] = _find(root[x]);
    return root[x];
}

void _union(int x, int y) {
    root[y] = x;
    sz[x] += sz[y];
    sum[x] += sum[y];
    sum[x] %= MOD;
}

void _init() {
    for (int i = 0; i <= n; i++)
        root[i] = i, sz[i] = 1, sum[i] = i;
}

void _solve() {
    cin >> n;
    assert(n >= 1 && n <= 200000);
    _init();
    vector<pair<int, pair<int, int>>> a;
    for (int i = 0; i + 1 < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        assert(u >= 1 && u <= n);
        assert(v >= 1 && v <= n);
        assert(w >= 1 && w <= 1000000);
        a.push_back({w, {u, v}});
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        int x = a[i].second.first, y = a[i].second.second;
        int mul = (sum[_find(x)] * sum[_find(y)]) % MOD;
        ans += (a[i].first * mul) % MOD;
        ans %= MOD;
        _union(_find(x), _find(y));
    }
    cout << ans << '\n';
}

signed main() {
    fastio;
    // t_times
    _solve();
    return 0;
}
