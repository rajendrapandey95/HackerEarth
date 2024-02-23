#include <iostream>
#include <vector>

using namespace std;

struct Dsu {
    vector<int> par, siz, sum;
    int tot;

    void init(int n) {
        tot = n;
        par.resize(2 * n + 1);
        siz.resize(2 * n + 1);
        sum.resize(2 * n + 1);
        for (int i = 1; i <= n; i++) {
            par[i] = i + n;
            siz[n + i] = 1;
            sum[i + n] = i;
            par[i + n] = i + n;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return;
        }
        if (siz[a] > siz[b]) {
            swap(a, b);
        }
        par[a] = b;
        siz[b] += siz[a];
        sum[b] += sum[a];
        siz[a] = 0;
        sum[a] = 0;
    }

    void move(int a, int b) {
        int parA = find(a), parB = find(b);
        if (parA == parB) {
            return;
        }
        siz[parA]--;
        sum[parA] -= a;
        par[a] = parB;
        siz[parB]++;
        sum[parB] += a;
    }

    int getSum(int x) {
        x = find(x);
        return sum[x];
    }

    int getSize(int x) {
        x = find(x);
        return siz[x];
    }
};

vector<vector<int>> teamUp(int n, int q, vector<vector<int>> &queries) {
    Dsu d;
    d.init(n);
    vector<vector<int>> ans;
    for (int i = 0; i < queries.size(); i++) {
        if (queries[i][0] == 1) {
            d.unite(queries[i][1], queries[i][2]);
        } else if (queries[i][0] == 3) {
            d.move(queries[i][1], queries[i][2]);
        } else {
            vector<int> currAns = {d.getSize(queries[i][1]), d.getSum(queries[i][1])};
            ans.push_back(currAns);
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> queries(q);
        for (int i = 0; i < q; i++) {
            int choice;
            cin >> choice;
            if (choice == 2) {
                int a;
                cin >> a;
                queries[i] = {choice, a};
            } else {
                int a, b;
                cin >> a >> b;
                queries[i] = {choice, a, b};
            }
        }
        vector<vector<int>> res = teamUp(n, q, queries);
        for (auto &i : res) {
            cout << i[0] << " " << i[1] << "\n";
        }
    }
    return 0;
}
