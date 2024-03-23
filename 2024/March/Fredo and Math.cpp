#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

vector<ll> etf(10000100);
vector<ll> prime(10000100);

ll power(ll a, ll b, ll mod) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

ll solve(ll x, ll k, ll m) {
    if (k == 0) return 1;
    if (m == 1) return 0;
    return power(x, solve(x, k - 1, etf[m]), m);
}

int main() {
    ll t;
    cin >> t;
    etf[1] = 1;
    for (ll i = 2; i <= 10000000; i++) {
        if (!prime[i]) {
            etf[i] = i - 1;
            for (ll j = 1; j * i <= 10000000; j++)
                if (!prime[j * i]) prime[j * i] = i;
        } else {
            etf[i] = etf[prime[i]] * etf[i / prime[i]];
            ll g = 1;
            if (i % (prime[i] * prime[i]) == 0) g = prime[i];
            etf[i] *= g;
            etf[i] /= etf[g];
        }
    }
    while (t--) {
        ll x, k, m;
        cin >> x >> k >> m;
        cout << solve(x, k, m) << endl;
    }
    return 0;
}
