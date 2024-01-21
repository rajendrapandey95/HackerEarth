#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define V vector
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define endl "\n"
#define all(x) x.begin(), x.end()
#define forstl(i, s) for (__typeof((s).end()) i = (s).begin(); i != (s).end(); ++i)

void solve()
{
    int n;
    cin >> n;

    map<int, int> freq;
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ans += freq[x ^ i];
        freq[x ^ i]++;
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif              

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
