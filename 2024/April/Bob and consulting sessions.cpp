#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1000000007;
const long long N = 100005;

long long n, ans, fact[N], inv[N];

inline long long power(long long x, long long y) {
    long long res = 1;
    for (; y; y >>= 1, x = x * x % mod) {
        if (y & 1) {
            res = res * x % mod;
        }
    }
    return res;
}

inline long long choose(long long x, long long y) {
    return (x > y ? 0 : fact[y] * inv[x] % mod * inv[y - x] % mod); 
}

int main() {
    fact[0] = 1;
    for (long long i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv[N - 1] = power(fact[N - 1], mod - 2);
    for (long long i = N - 2; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
    cin >> n;
    for (long long i = 0; i <= n; i++) {
        ans = ((ans + (i & 1 ? -1 : 1) * choose(i, n) * power(2, (n - i) * (n - i - 1) / 2) % mod) % mod + mod) % mod;
    }
    cout << ans;
    return 0;
}
