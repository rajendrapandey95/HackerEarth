#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000005;
const int LG = 22;

int lvl[N], P[N][LG];
vector<int> g[N];

void clear(int n) {
    for(int i = 0; i <= n; i++) {
        lvl[i] = 0;
        g[i].clear();
        for(int j = 0; j < LG; j++) {
            P[i][j] = -1;
        }
    }
}

void dfs(int u, int par){
    lvl[u] = 1 + lvl[par];
    P[u][0] = par;
    for(int i = 1; i < LG; i++) {
        if(P[u][i - 1] != -1) {
            P[u][i] = P[P[u][i - 1]][i - 1];
        }
    }
    for(int v : g[u]){
        if (v == par) continue;
        dfs(v, u);
    }
}
 
int lca(int u, int v){
    int lg;
    if (lvl[u] < lvl[v]) swap(u, v);
 
    for(lg = 0; (1 << lg) <= lvl[u]; lg++);
    lg--;
 
    for(int i = lg; i >= 0; i--){
        if (lvl[u] - (1 << i) >= lvl[v])
            u = P[u][i];
    }
 
    if (u == v) 
        return u;
 
    for(int i = lg; i >= 0; i--){
        if (P[u][i] != -1 && P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    }
 
    return P[u][0];
}

int dis(int u, int v){
    if (lvl[u] < lvl[v]) swap(u, v);
    int w = lca(u, v);
    return lvl[u] + lvl[v] - 2 * lvl[w];
}

void solve() {
    int n;
    cin >> n;
    clear(n);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        int l = dis(x, y) + 1;
        if((l % 2) == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
            cout << 1 << ' ' << l << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        solve();
    }
    return 0;
}
