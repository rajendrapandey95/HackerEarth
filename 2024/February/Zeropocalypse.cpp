#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1000005;
#define M 1000000007

int fact[N], ifact[N];
 
int power(int x,int y,int m){
    if (y == 0)
        return 1;
    int p = power(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}
 
void process(){
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = (fact[i - 1] * i) % M;
    for(int i = 0; i < N; i++)
        ifact[i] = power(fact[i], M - 2, M);
}
 
int nCr(int n, int r){
    if(r > n) return 0;
    if(r == n) return 1;
    int ans = (ifact[n - r] * ifact[r]) % M;
    ans = (ans * fact[n]) % M;
    return ans;
}


void solve() {

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> v;
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
            v.push_back(i);
        }
    }
    for(int i = 1; i < v.size(); i++) {
        if(a[v[i]] <= a[v[i - 1]]) {
            cout << 0 << endl;
            return ;
        }
        if((a[v[i]] - a[v[i - 1]] - 1) < (v[i] - v[i - 1] - 1)) {
            cout << 0 << endl;
            return ;
        }
    }
    if(v.size() > 0) {
        if(v[0] > 0 and (a[v[0]] - 1) < v[0]) {
            cout << 0 << endl;
            return ;
        }
    }
    if(a[n - 1] == 0) {
        cout << -1 << endl;
        return ;
    }

    int c = 1;
    if(v[0] > 0) {
        c = nCr(a[v[0]] - 1, v[0]);
    }

    for(int i = 1; i < v.size(); i++) {
        if((v[i] - v[i - 1]) > 1) {
            c = (c * nCr(a[v[i]] - a[v[i - 1]] - 1, v[i] - v[i - 1] - 1)) % M;
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

    process();

    for(int tc = 1; tc <= T; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }

return 0;  

}
