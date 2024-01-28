#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

int main() {
    std::vector<ll> a(1000005, 0);

    for (ll i = 1; i <= 1000000; ++i) {
        ll r = 1;

        for (ll j = 1; j <= 20; ++j) {
            r = r * 2;

            if (r > i) {
                break;
            }
        }

        ll z = (i * r) - 1;
        a[i] = z;
    }

    ll t, x;
    std::cin >> t;

    while (t--) {
        std::cin >> x;
        auto id = std::lower_bound(a.begin() + 1, a.begin() + 1000001, x) - a.begin();
        std::cout << (x - id + 1) << std::endl;
    }

    return 0;
}
