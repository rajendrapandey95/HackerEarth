#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int n, m, x, y;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dp[26][7][7][64][64];

int calcIntro(int pos, int introMask, int extroMask) {
    int r = pos / m;
    int c = pos - (r * m);
    int ans = 0;

    if (r > 0) {
        if (introMask & (1 << (m - 1))) {
            ans -= 180;
        }
        if (extroMask & (1 << (m - 1))) {
            ans -= 30;
        }
    }

    if (c > 0) {
        if (introMask & 1) {
            ans -= 180;
        }
        if (extroMask & 1) {
            ans -= 30;
        }
    }

    return ans;
}

int calcExtro(int pos, int introMask, int extroMask) {
    int r = pos / m;
    int c = pos - (r * m);
    int ans = 0;

    if (r > 0) {
        if (introMask & (1 << (m - 1))) {
            ans -= 30;
        }
        if (extroMask & (1 << (m - 1))) {
            ans += 120;
        }
    }

    if (c > 0) {
        if (introMask & 1) {
            ans -= 30;
        }
        if (extroMask & 1) {
            ans += 120;
        }
    }

    return ans;
}

int checker(int pos, int introLeft, int extroLeft, int introMask, int extroMask) {
    if (pos >= (n * m)) {
        return 0;
    }

    if (dp[pos][introLeft][extroLeft][introMask][extroMask] != -1) {
        return dp[pos][introLeft][extroLeft][introMask][extroMask];
    }

    int newIntroMask = (introMask << 1) & 63;
    int newExtroMask = (extroMask << 1) & 63;
    int ans = checker(pos + 1, introLeft, extroLeft, newIntroMask, newExtroMask);

    if (introLeft) {
        ans = max(ans, 360 + checker(pos + 1, introLeft - 1, extroLeft, newIntroMask + 1, newExtroMask) + calcIntro(pos, introMask, extroMask));
    }

    if (extroLeft) {
        ans = max(ans, 120 + checker(pos + 1, introLeft, extroLeft - 1, newIntroMask, newExtroMask + 1) + calcExtro(pos, introMask, extroMask));
    }

    return dp[pos][introLeft][extroLeft][introMask][extroMask] = ans;
}

void solve() {
    cin >> n >> m >> x >> y;
    memset(dp, -1, sizeof dp);
    int ans = checker(0, x, y, 0, 0);
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    solve();
    return 0;
}
