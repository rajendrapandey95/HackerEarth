#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)

const int INF = 1000000000;
const int MAX = 1000007;

int a[MAX];
int dp[MAX];

void upd(int x) {
    for(int i = 2; i * x < MAX; ++i) {
        if (dp[x] + dp[i] < dp[i * x]) {
            dp[i * x] = dp[x] + dp[i];
            upd(i * x);
        }
    }
}

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    FOR(i, 0, m) {
        int x;
        cin >> x;
        a[x] = 1;
    }

    FOR(i, 0, MAX) {
        dp[i] = INF;
    }
    vector<int> res;
    FOR(i, 1, MAX) {
        if (res.size() == n) break;
        if (a[i]) continue;
        if (dp[i] <= k) continue;
        dp[i] = 1;
        upd(i);
        res.push_back(i);
    }

    FOR(i, 0, n) {
        cout << res[i];
        if (i + 1 < n) cout << ' ';
    }
    cout << endl;

    return 0;
}
