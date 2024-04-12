#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cassert>
#include <cstring>
using namespace std;

#define ll long long int
#define MOD 1000000007

ll pow_mod(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

const int maxn = 1000;
vector<int> adj[maxn + 5];
vector<pair<int, int>> adj1[maxn + 5];
vector<pair<pair<int, int>, pair<int, int>>> edges;
int cap[maxn + 5][maxn + 5];
int residual_network_cap[maxn + 5][maxn + 5];
int prev_nd[maxn + 5];
int flow_intermediate[maxn + 5];

void update_residual(int v, int flow) {
    while (v != prev_nd[v]) {
        residual_network_cap[prev_nd[v]][v] += flow;
        residual_network_cap[v][prev_nd[v]] -= flow;
        v = prev_nd[v];
    }
}

int find_augment_path_flow(int src, int snk, int n) {
    for (int i = 0; i <= n; ++i) {
        prev_nd[i] = -1;
        flow_intermediate[i] = 0;
    }
    queue<int> q;
    q.push(src);
    prev_nd[src] = src;
    flow_intermediate[src] = (int)(1e8);
    while (!q.empty()) {
        int nd = q.front();
        q.pop();
        if (nd == snk) {
            return flow_intermediate[nd];
        }
        for (int i = 0; i < (int)(adj[nd].size()); ++i) {
            int to = adj[nd][i];
            if ((cap[nd][to] <= residual_network_cap[nd][to]) || (prev_nd[to] != -1)) {
                continue;
            }
            flow_intermediate[to] = min(flow_intermediate[nd], cap[nd][to] - residual_network_cap[nd][to]);
            q.push(to);
            prev_nd[to] = nd;
        }
    }
    return 0;
}

int compute_max_flow(int src, int snk, int n) {
    memset(residual_network_cap, 0, sizeof(residual_network_cap));
    int cur_flow;
    int final_flow = 0;
    while ((cur_flow = find_augment_path_flow(src, snk, n))) {
        final_flow += cur_flow;
        update_residual(snk, cur_flow);
    }
    return final_flow;
}

vector<int> dijkstra(int src, int n) {
    vector<int> dist;
    dist.resize(n + 1, INT_MAX);
    priority_queue<pair<int, int>> pq;
    dist[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        pair<int, int> tp = pq.top();
        pq.pop();
        int local_nd = tp.second;
        int local_dist = -1 * tp.first;
        if (local_dist > dist[local_nd]) {
            continue;
        }
        for (int i = 0; i < (int)(adj1[local_nd].size()); ++i) {
            int nd = adj1[local_nd][i].first;
            int nd_dist = adj1[local_nd][i].second;
            if (dist[nd] > nd_dist + local_dist) {
                dist[nd] = nd_dist + local_dist;
                pq.push(make_pair(-1 * dist[nd], nd));
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    assert(1 <= n && n <= 1000);
    assert(1 <= m && m <= 400000);
    int x, y, w, c;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> w >> c;
        assert(1 <= x && x <= n);
        assert(1 <= y && y <= n);
        assert(1 <= w && w <= 1000000);
        assert(1 <= c && c <= 1000000);
        adj1[x].push_back(make_pair(y, w));
        adj1[y].push_back(make_pair(x, w));
        edges.push_back(make_pair(make_pair(x, y), make_pair(w, c)));
        edges.push_back(make_pair(make_pair(y, x), make_pair(w, c)));
    }
    memset(residual_network_cap, 0, sizeof(residual_network_cap));
    memset(cap, 0, sizeof(cap));
    vector<int> dist1 = dijkstra(1, n);
    vector<int> dist2 = dijkstra(n, n);
    for (int i = 0; i < (int)(edges.size()); ++i) {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int wt = edges[i].second.first;
        int cst = edges[i].second.second;

        if (dist1[n] == (dist1[u] + wt + dist2[v])) {
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
            cap[u - 1][v - 1] += cst;
        }
    }
    cout << compute_max_flow(0, n - 1, n) << endl;
    return 0;
}
