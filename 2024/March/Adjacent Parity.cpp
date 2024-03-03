#include <iostream>
#include <vector>
#include <cassert>

void solve(int tc) {
    int n;
    std::cin >> n;
    assert(n >= 3 && n <= 100);

    std::vector<int> a(2);

    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        assert(x >= 1 && x <= 100);
        a[x % 2]++;
    }

    if (a[0] == 0 || a[0] == n || std::abs(a[0] - a[1]) <= 1) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t = 1;
    std::cin >> t;
    assert(t >= 1 && t <= 100);

    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}
