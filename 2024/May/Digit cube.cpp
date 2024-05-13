#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 3e6 + 14, LOG = 50, MAX_S = 136;

int sum_of_digits(ll n) {
    string str = to_string(n);
    return accumulate(str.begin(), str.end(), 0) - '0' * str.size();
}

int nxt[MAX_S][LOG];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    for (int k = 0; k < LOG; ++k) {
        for (int i = 1; i < MAX_S; ++i) {
            if (k)
                nxt[i][k] = nxt[nxt[i][k - 1]][k - 1];
            else
                nxt[i][0] = sum_of_digits(i * i * i);
        }
    }
    
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        k--;
        n = sum_of_digits(n);
        for (int i = LOG - 1; i >= 0; --i)
            if (k >> i & 1)
                n = nxt[n][i];
        cout << n * n * n << '\n';
    }
}
