#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int sum = 0;
    for(auto i : a) {
        sum += i;
    }
    for(auto i : b) {
        sum -= i;
    }

    if(sum != 0) {
        cout << -1 << endl;
        return;
    }

    int c = 0, x = 0, y = 0;
    int i = 0, j = 0;
    while(i < n || j < m) {

        if(x > y) {
            y = y + b[j];
            j = j + 1;
        } else {
            x = x + a[i];
            i = i + 1; 
        }

        if(x == y) {
            x = 0, y = 0;
            c = c + 1;
        }
    }
    
    cout << c << endl;
}

#undef int 
int main() {
#define int long long int
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }

    return 0;  
}
