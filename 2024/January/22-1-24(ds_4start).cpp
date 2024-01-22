#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct SegTree {
    int n;
    vector<int> t;
    SegTree(int n_) {
        n = n_;
        t.resize(2 * n + 5, 0);
    }

    void add(int i, int x) {
        t[n + i] = x;
    }

    void build() {
        for (int i = n - 1; i > 0; --i)
            t[i] = t[i << 1] + t[i << 1 | 1];
    }

    void modify(int p, int value) {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
    }

    int query(int l, int r) {
        r++;
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res += t[l++];
            if (r & 1)
                res += t[--r];
        }
        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegTree st(n + 5);
    st.build();

    vector<pair<int, int>> v;
    vector<pair<int, pair<int, int>>> Q;

    for (int i = 0; i < n; i++) {
        v.push_back(make_pair(a[i], i));
    }
    sort(v.rbegin(), v.rend());

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        Q.push_back(make_pair(a[r], make_pair(l, i)));
    }
    sort(Q.rbegin(), Q.rend());

    vector<int> arr(q);
    int ind = 0;
    for (int i = 0; i < q; i++) {
        while (ind < n && v[ind].first > Q[i].first) {
            st.modify(v[ind].second, v[ind].first);
            ind = ind + 1;
        }
        arr[Q[i].second.second] = st.query(0, Q[i].second.first);
    }

    for (int i = 0; i < q; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        solve();
    }

    return 0;
}
