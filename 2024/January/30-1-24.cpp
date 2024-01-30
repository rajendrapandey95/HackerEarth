#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test;
    cin >> test;

    assert(test >= 1 && test <= 1e5);

    int totalN = 0;
    int totalQ = 0;

    while (test--) {
        int N;
        cin >> N;

        assert(N >= 3 && N <= 1e6);
        totalN += N;

        vector<vector<int>> tree(N);

        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;

            assert(1 <= u && u <= N);
            assert(1 <= v && v <= N);

            u--, v--;

            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        vector<ll int> Guards(N);

        for (auto &e : Guards) {
            cin >> e;
            assert(e >= 1 && e <= 1e9);
        }

        int l = log2(N) + 2;

        vector<vector<int>> par(N, vector<int>(l, -1));
        vector<vector<ll int>> vals(N, vector<ll int>(l));

        function<void(int, int)> DFS = [&](int u, int p) {
            int _p = p;
            int i = 0;
            ll int temp = Guards[u];

            while (_p != -1) {
                par[u][i] = _p;
                vals[u][i] = temp;

                temp += vals[_p][i];
                _p = par[_p][i];

                i++;
            }

            for (auto v : tree[u]) {
                if (v == p)
                    continue;

                DFS(v, u);
            }
        };

        DFS(0, -1);

        int Q;
        cin >> Q;

        assert(Q >= 1 && Q <= 1e6);
        totalQ += Q;

        while (Q--) {
            ll int u, x;
            cin >> u >> x;

            assert(1 <= u && u <= N);
            assert(1 <= x && x <= 1e15);

            u--;

            while (x > 0 && u) {
                int p = -1;
                ll int tmp = 0;

                for (int i = 0; i <= l; i++) {
                    if (par[u][i] == -1)
                        break;
                    if (vals[u][i] >= x)
                        break;

                    p = par[u][i];
                    tmp = vals[u][i];
                }

                if (p == -1)
                    break;

                x -= tmp;
                u = p;
            }

            cout << u + 1 << "\n";
        }
    }

    assert(totalN <= 1e6);
    assert(totalQ <= 1e6);

    return 0;
}
