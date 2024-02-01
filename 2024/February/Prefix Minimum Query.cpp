#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int N = 500005;
const int M = 1000000007;
const int BINF = 1e16;
const int MAXN = 10000005;
const int LG = 22;

int P[N][LG], arr[N], sum[N];
vector<int> g[N];

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> v(n, n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        if (s.size() == 0) {
            s.push(i);
            continue;
        }
        while (s.size() > 0 and a[i] < a[s.top()]) {
            v[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < LG; i++) {
        P[0][i] = n;
    }

    for (int i = 0; i < n; i++) {
        g[i].push_back(v[i]);
        g[v[i]].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = (v[i] - i) * a[i];
    }

    queue<pair<int, pair<int, int>>> Q;
    Q.push({n, {n, 0}});

    while (Q.size() > 0) {
        auto st = Q.front();
        Q.pop();

        sum[st.first] = arr[st.first] + st.second.second;
        P[st.first][0] = st.second.first;
        for (int i = 1; i < LG; i++)
            P[st.first][i] = P[P[st.first][i - 1]][i - 1];

        for (auto i : g[st.first]) {
            if (i != st.second.first) {
                Q.push({i, {st.first, st.second.second + arr[st.first]}});
            }
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l = l - 1, r = r - 1;

        int ans = sum[l];

        int node = l;
        for (int i = LG - 1; i >= 0; i--) {
            if (P[node][i] <= r) {
                node = P[node][i];
            }
        }
        int c = (r - node + 1) * a[node];
        ans = ans - sum[node] + c;

        cout << ans << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("optput.txt", "w", stdout);
#endif

    solve();

    return 0;
}
