#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

const int N = 2333;
const double eps = 1e-7;

pair<int, double> s[N], t[N];
pair<int, int> f[N];
int n, c;

void dfs(int x, int l, double r) {
    if (x == n) {
        if (r < eps) {
            int v = 1;
            for (int i = 0; i < n; ++i)
                v = v / __gcd(v, t[i].first) * t[i].first;

            f[c].second = v;
            f[c].first = 1;
            for (int i = 0; i < n; ++i)
                f[c].first *= t[i].first;

            ++c;
        }
    } else {
        if (r < eps) return;
        while (s[l].second * (n - x) >= r - eps) {
            t[x] = s[l];
            if (s[l].second <= r + eps)
                dfs(x + 1, l, r - s[l].second);
            ++l;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < N; ++i)
        s[i] = make_pair(i, 1.0 / i);

    n = 4;
    dfs(0, 1, 1);

    sort(f, f + c);

    int u = 0;
    for (int i = 0; i < c; ++i) {
        bool flag = false;
        for (int j = 0; j < u; ++j)
            if (f[i].second % f[j].second == 0) {
                flag = true;
                break;
            }
        if (!flag) f[u++] = f[i];
    }
    c = u;#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

const int N = 2333;
const double eps = 1e-7;

pair<int, double> s[N], t[N];
pair<int, int> f[N];
int n, c;

void dfs(int x, int l, double r) {
    if (x == n) {
        if (r < eps) {
            int v = 1;
            for (int i = 0; i < n; ++i)
                v = v / __gcd(v, t[i].first) * t[i].first;

            f[c].second = v;
            f[c].first = 1;
            for (int i = 0; i < n; ++i)
                f[c].first *= t[i].first;

            ++c;
        }
    } else {
        if (r < eps) return;
        while (s[l].second * (n - x) >= r - eps) {
            t[x] = s[l];
            if (s[l].second <= r + eps)
                dfs(x + 1, l, r - s[l].second);
            ++l;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < N; ++i)
        s[i] = make_pair(i, 1.0 / i);

    n = 4;
    dfs(0, 1, 1);

    sort(f, f + c);

    int u = 0;
    for (int i = 0; i < c; ++i) {
        bool flag = false;
        for (int j = 0; j < u; ++j)
            if (f[i].second % f[j].second == 0) {
                flag = true;
                break;
            }
        if (!flag) f[u++] = f[i];
    }
    c = u;

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        long long ans = -1;
        for (int i = 0; i < c; ++i)
            if (n % f[i].second == 0) {
                ans = (long long)n * n * n * n / f[i].first;
                break;
            }
        cout << ans << '\n';
    }

    return 0;
}


    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        long long ans = -1;
        for (int i = 0; i < c; ++i)
            if (n % f[i].second == 0) {
                ans = (long long)n * n * n * n / f[i].first;
                break;
            }
        cout << ans << '\n';
    }

    return 0;
}
