#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

constexpr int N = 1000005;
constexpr int M = 1000000007;

int n, dp[N][2];

int foo(int i, int j, const vector<int>& a) {
    if (i == n) {
        if (j == 1) {
            return 1;
        }
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int c = foo(i + 1, j ^ a[i], a);
    if (j == 1) {
        c = (c + foo(i + 1, a[i], a)) % M;
    }
    return dp[i][j] = c;
}

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = bitset<64>(a[i]).count() % 2;
    }
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = dp[i][1] = -1;
    }

    int c = foo(0, 0, a);

    cout << c << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        solve();
    }

    return 0;
}
