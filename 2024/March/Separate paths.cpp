#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 500 + 14;

int n, m, ban, in[maxn];
vector<int> g[maxn];
bool seen[maxn], ok[maxn][maxn];

void dfs(int v) {
    if (seen[v] || v == ban)
        return;
    seen[v] = true;
    for (auto u : g[v])
        dfs(u);
}

void solve() {
    cin >> n >> m;
    fill(g, g + n, vector<int>());
    fill(in, in + n, 0);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        in[u]++;
    }
    memset(ok, 1, sizeof ok);
    for (ban = 0; ban < n; ban++) {
        fill(seen, seen + n, false);
        for (int i = 0; i < n; i++)
            if (!in[i])
                dfs(i);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!seen[i] && !seen[j])
                    ok[i][j] = false;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            ans += ok[i][j];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
