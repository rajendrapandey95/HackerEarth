#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <sstream>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<ll>;
using pii = pair<ll, ll>;

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ld PI = 2*acos(0.0);

template <typename T>
T gcd(T a, T b) {
    return (b == 0) ? a : gcd(b, a % b);
}

template <typename T>
T lcm(T a, T b) {
    return a * (b / gcd(a, b));
}

template <typename T>
T mod_exp(T b, T p, T m) {
    T x = 1;
    while (p) {
        if (p & 1) x = (x * b) % m;
        b = (b * b) % m;
        p >>= 1;
    }
    return x;
}

template <typename T>
T invFermat(T a, T m) {
    return mod_exp(a, m - 2, m);
}

string tostring(ll number) {
    stringstream ss; ss << number; return ss.str();
}

ll toint(const string &s) {
    stringstream ss(s); ll x; ss >> x; return x;
}

bool can_make(vi &a, multiset<ll> ok) {
    while (ok.size() < a.size()) {
        ll fr = *ok.rbegin();
        ok.erase(prev(ok.end()));
        ll lr = *ok.rbegin();
        ok.insert(fr + lr);
        ok.insert(fr - lr);
        ok.insert(fr);
    }
    sort(a.begin(), a.end());
    return equal(a.begin(), a.end(), ok.begin());
}

void solve() {
    ll n; cin >> n;
    vi a(n);
    for (ll &x : a) {
        cin >> x;
    }

    if (n >= 100) {
        if (all_of(a.begin(), a.end(), [](ll x){ return x == 0; })) {
            cout << "YES\n0 0\n";
            return;
        }
        cout << "NO\n";
        return;
    }

    multiset<ll> ok(a.begin(), a.end());

    while (ok.size() > 2) {
        auto fr_it = prev(ok.end());
        ll fr = *fr_it;
        ok.erase(fr_it);
        ll lr = *prev(ok.end());
        fr -= lr;

        if (ok.find(lr - fr) != ok.end()) {
            ok.erase(ok.find(lr - fr));
        } else {
            cout << "NO\n";
            return;
        }
    }

    if (ok.size() == 2 && can_make(a, ok)) {
        cout << "YES\n" << *ok.rbegin() << " " << *ok.begin() << "\n";
        return;
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll t; cin >> t;
    while (t--) solve();

    return 0;
}
