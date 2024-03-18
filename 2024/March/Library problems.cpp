#include <iostream>
#include <vector>
#include <algorithm>

#define pb push_back
#define X first
#define Y second

const bool DEBUG = false;
#define cerr if(DEBUG)cerr
#define bit(num,i) ((num>>i)&1)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<long long, long long> pll;
typedef pair<pii, pii> point;

const long long maxn = 1e5 + 5 + 1;
const long long INF = 4e18;
const long long M = 1e9 + 7;
const int lg = 21;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    ll n, r;
    cin >> n >> r;

    vector<pll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].X >> a[i].Y;
    }

    cout << n << endl;
    for(int i = 0; i < n; i++){
        cout << a[i].X << " " << a[i].Y << endl;
    }

    return 0;
}
