#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
const int maxn = 30*200000;
long long fact[maxn], inv_fact[maxn];

long long pow_mod(long long a, long long b) {
    long long x = 1, y = a;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x * y) % mod;
        }
        y = (y * y) % mod;
        b /= 2;
    }
    return x;
}

void build() {
    fact[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        fact[i] = (fact[i-1] * i) % mod;
    }
    inv_fact[maxn-1] = pow_mod(fact[maxn-1], mod-2);
    for (int i = maxn-2; i >= 0; --i) {
        inv_fact[i] = (inv_fact[i+1] * (i+1)) % mod;
    }
}

long long C(int n, int r) {
    long long val1 = fact[n];
    long long val2 = inv_fact[r];
    long long val3 = inv_fact[n-r];
    long long mul = (val2 * val3) % mod;
    return (val1 * mul) % mod;
}

long long get(int sum, int n) {
    sum -= n;
    long long tot = C(sum+n-1, n-1), sub = 0;
    for (int i = 1, x = 1; i <= n; ++i, x *= -1) {
        int curr = (26 * i), left = sum - curr;
        if (left >= 0) {
            long long now1 = C(left+n-1, n-1);
            long long now2 = C(n, i);
            now1 = (now1 * now2) % mod;
            now1 = (now1 * x + mod) % mod;
            sub = (sub + now1) % mod;
        }
    }
    return (tot - sub + mod) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build();
    int n, m, k;
    cin >> n >> m >> k;

    string a;
    cin >> a;
    int sum = 0, add = 0;
    for (int i = 0; i < n; ++i) {
        sum = (sum + a[i] - 'a' + 1) % m;
    }

    add = (k - sum + m) % m;
    long long res = 0;
    int max = 26 * n;

    while (add <= max) {
        if (add >= n) {
            res = (res + get(add, n)) % mod;
        }
        add += m;
    }

    cout << res << "\n";
    return 0;
}
