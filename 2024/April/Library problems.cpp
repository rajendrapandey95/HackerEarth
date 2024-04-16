#include <iostream>
#include <vector>
#include <utility>

#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 5 + 1;

ll n, r;
pll a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> a[i].X >> a[i].Y;
    }

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i].X << " " << a[i].Y << endl;
    }

    return 0;
}
