#include <iostream>
#include <cmath>

using namespace std;

#define ll long long int

void solve() {
    ll n, ans, t;
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        ll j = sqrt(n);
        for (ll i = 1; i <= j; i++) {
            ans += (n / i);
        }
        for (ll i = 1; i <= j; i++) {
            ll lo, hi;
            hi = n / i;
            lo = n / (i + 1);
            lo = max(lo, j);
            hi = max(hi, j);
            ans += i * (hi - lo);
        }
        cout << ans << "\n";
    }
}

int main() {
    solve();
    return 0;
}
