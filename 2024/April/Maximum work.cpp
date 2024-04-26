#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

#define mod 1000000007
#define mp make_pair
#define pb push_back
#define ll long long int
#define MAXN 200000

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int k, b, m;

bool check(int idx, int a[], int s[]) {
    int pills = 0;
    for (int i = idx, j = 1; i > 0; --i, ++j) {
        int diff = max(0, s[j] - a[i]);
        pills += diff / b + ((diff % b) != 0);
    }
    if (pills <= k)
        return true;
    return false;
}

int binary(int a[], int s[]) {
    int low = 1, high = m;

    while (high - low > 3) {
        int mid = (low + high) / 2;
        if (check(mid, a, s)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    for (int i = high; i >= low; --i) {
        if (check(i, a, s))
            return i;
    }
    return 0;
}

int myrandom(int i) {
    return std::rand() % i;
}

int main() {
    int t;
    cin >> t;
    assert(0 < t && t <= 100);
    while (t--) {
        cin >> k >> b;
        assert(0 < k && k <= 1e5);
        assert(0 < b && b <= 10);
        int n;
        cin >> n;
        assert(0 < n && n <= 1e4);

        int a[MAXN];
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            assert(0 < a[i] && a[i] <= 1e5);
        }

        sort(a + 1, a + n + 1, greater<int>());
        cin >> m;
        assert(0 < m && m <= 1e4);
        int s[MAXN];
        for (int i = 1; i <= m; ++i) {
            cin >> s[i];
            assert(0 < s[i] && s[i] <= 1e5);
        }
        sort(s + 1, s + m + 1);
        m = min(m, n);
        int ans = binary(a, s);
        cout << ans << "\n";
    }
    return 0;
}
