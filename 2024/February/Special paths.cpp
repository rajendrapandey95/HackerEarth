#include <iostream>
#include <cstring>

const int maxn = 1e5 + 14;

struct Dsu {
    int par[maxn];

    Dsu() {
        std::memset(par, -1, sizeof par);
    }

    int root(int v) {
        return par[v] < 0 ? v : par[v] = root(par[v]);
    }

    bool fri(int v, int u) {
        return root(v) == root(u);
    }

    bool merge(int v, int u) {
        if ((v = root(v)) == (u = root(u)))
            return 0;
        par[u] += par[v];
        par[v] = u;
        return 1;
    }
} dsu;

int n, m, v[maxn], u[maxn], a[maxn];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        std::cin >> v[i] >> u[i];
        v[i]--, u[i]--;
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int s, e;
    std::cin >> s >> e;
    s--, e--;

    int lo = -1, hi = 1e6;

    while (hi - lo > 1) {
        dsu = Dsu();
        int mid = (lo + hi) / 2;

        for (int i = 0; i < m; ++i) {
            if (std::abs(a[v[i]] - a[u[i]]) <= mid)
                dsu.merge(v[i], u[i]);
        }

        (dsu.fri(s, e) ? hi : lo) = mid;
    }

    std::cout << hi << '\n';

    return 0;
}
