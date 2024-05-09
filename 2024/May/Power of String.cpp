#include <iostream>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

#define ll long long

const int MOD1 = (int)1e9 + 7;
const int MOD2 = (int)1e9 + 9;
const int N = (int)1e6 + 9;

char s[N];

struct Hash {
    int x, y;

    Hash() {}

    Hash(int _x, int _y) {
        x = _x;
        y = _y;
    }

    const bool operator<(Hash other) const {
        if (x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }

    const bool operator==(Hash other) const {
        return x == other.x && y == other.y;
    }
};

Hash add(Hash a, Hash b) {
    Hash res;
    res.x = (a.x + b.x) % MOD1;
    res.y = (a.y + b.y) % MOD2;
    return res;
}

Hash subtract(Hash a, Hash b) {
    Hash res;
    res.x = (a.x - b.x + MOD1) % MOD1;
    res.y = (a.y - b.y + MOD2) % MOD2;
    return res;
}

Hash multiply(Hash a, Hash b) {
    Hash res;
    res.x = ((ll)a.x * b.x) % MOD1;
    res.y = ((ll)a.y * b.y) % MOD2;
    return res;
}

Hash multiply(Hash a, int v) {
    Hash res;
    res.x = ((ll)a.x * v) % MOD1;
    res.y = ((ll)a.y * v) % MOD2;
    return res;
}

Hash hashes[N];
Hash p[N];
Hash tmp[N];

int main() {
    int k, n;
    scanf("%d %d\n", &k, &n);
    assert(1 <= n && n <= (int)1e6);
    assert(1 <= k && k <= n);
    cin.getline(s + 1, N);
    assert(strlen(s + 1) == n);
    for (int i = 1; i <= n; ++i) {
        assert(s[i] >= 'a' && s[i] <= 'z');
    }
    p[0] = Hash(1, 1);
    hashes[0] = Hash(0, 0);
    for (int i = 1; i <= n; ++i) {
        p[i] = multiply(p[i - 1], 31);
        hashes[i] = add(hashes[i - 1], multiply(p[i], (s[i] - 'a' + 1)));
    }
    int l = 1;
    int r = n;
    int res = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        int sz = 0;
        for (int i = m; i <= n; ++i) {
            tmp[sz++] = multiply(subtract(hashes[i], hashes[i - m]), p[n - i]);
        }
        sort(tmp, tmp + sz);
        int curCnt = 1;
        int maxCnt = 1;
        for (int i = 1; i < sz; ++i) {
            if (tmp[i] == tmp[i - 1]) {
                ++curCnt;
            } else {
                maxCnt = max(curCnt, maxCnt);
                curCnt = 1;
            }
        }
        maxCnt = max(curCnt, maxCnt);
        if (maxCnt >= k) {
            res = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    printf("%d\n", res);
    return 0;
}
