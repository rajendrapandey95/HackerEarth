#include<bits/stdc++.h>
using namespace std;

#define int long long int

const int maxm = (1LL<<20) + 1;
int n, mask;
int a[20];
int dp[20][maxm];
int gcd_calc[maxm];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int getGCD(int &curMask) {
    if (gcd_calc[curMask] != -1) {
        return gcd_calc[curMask];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (curMask & (1LL << i)) {
            ans = gcd(ans, a[i]);
        }
    }
    return gcd_calc[curMask] = ans;
}

int checker(int ind, int curMask) {
    if (ind >= n) {
        return 0;
    }
    if (dp[ind][curMask] != -1) {
        return dp[ind][curMask];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((curMask & (1LL << i)) == 0) {
            int newMask = curMask | (1LL << i);
            int prefGCD = getGCD(newMask);
            ans = max(ans, prefGCD + checker(ind + 1, newMask));
        }
    }
    return dp[ind][curMask] = ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    memset(gcd_calc, -1, sizeof gcd_calc);
    cin >> n;
    mask = (1LL << n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = checker(0, 0);
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
