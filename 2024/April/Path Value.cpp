#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 200005;

int val[MAX];
int parent[MAX];
int _size[MAX];
vector<pair<int,int>> a;
int n, m;
int startNode, endNode;

int par(int u) {
    while(u != parent[u]) {
        u = parent[u];
    }
    return u;
}

void merge(int u, int v) {
    if(_size[v] < _size[u]) {
        parent[v] = u;
        _size[u] += _size[v];
    } else {
        parent[u] = v;
        _size[v] += _size[u];
    }
}

bool possible(int value) {
    for(int i = 1; i < MAX; i++) {
        _size[i] = 1;
        parent[i] = i;
    }

    for(int i = 1; i <= m; i++) {
        int u = a[i-1].first;
        int v = a[i-1].second;

        if(abs(val[u] - val[v]) > value) {
            continue;
        } else {
            int pu = par(u);
            int pv = par(v);

            if(pu != pv) {
                merge(pu, pv);
            }
        }
    }

    return par(startNode) == par(endNode);
}

int findSolution() {
    int start = 0;
    int end = 1000000;

    int answer = -1;

    while(start <= end) {
        int m = (start + end) / 2;

        if(possible(m)) {
            answer = m;
            end = m - 1;
        } else {
            start = m + 1;
        }
    }    

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> startNode >> endNode;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a.push_back({u, v});
    }   

    for(int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    cout << findSolution() << endl;
    return 0;
}
