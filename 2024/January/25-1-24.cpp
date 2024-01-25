#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

const int N = 1 << 18;
const int MOD = 1e9 + 7;

struct BIT {
    int tree[N];

    void init() {
        memset(tree, 0, sizeof tree);
    }

    void add(int pos, int val) {
        for (++pos; pos <= N; pos += (pos & (-pos)))
            tree[pos - 1] += val;
    }

    int get(int pos) {
        int ret = 0;
        for (++pos; pos; pos -= (pos & (-pos)))
            ret += tree[pos - 1];
        return ret;
    }

    int find(int t) {
        int st = 0;
        for (int sz = N >> 1; sz; sz >>= 1) {
            if (tree[st + sz - 1] < t) {
                t -= tree[(st += sz) - 1];
            }
        }
        return st;
    }
};

struct MultiSet {
    BIT bit;

    MultiSet() {
        bit.init();
        bit.add(0, -1);
    }

    void insert(int val) {
        bit.add(val, 1);
    }

    void erase(int val) {
        bit.add(val, -1);
    }

    int count(int val) {
        return bit.get(val) - bit.get(val - 1);
    }

    int size() {
        return bit.get(N - 1) + 1;
    }

    int at(int ind) {
        return bit.find(ind);
    }
} mySet;

ll pow_MOD(ll n, ll m) {
    ll ans = 1;
    while (m) {
        if (m & 1)
            ans = (ans * n) % MOD;
        n = (n * n) % MOD;
        m >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int i;
    deque<int> dq;

    for (i = 0; i < k; i++) {
        int cur;
        cin >> cur;
        dq.emplace_back(cur);
        mySet.insert(cur);
    }

    vector<int> med;

    for (; i < n; i++) {
        med.push_back(mySet.at((k + 1) / 2 - 1));
        mySet.erase(dq.front());
        dq.pop_front();
        int cur;
        cin >> cur;
        dq.emplace_back(cur);
        mySet.insert(cur);
    }

    med.push_back(mySet.at((k + 1) / 2 - 1));
    cout << pow_MOD(n, *max_element(med.begin(), med.end()));
    return 0;
}
