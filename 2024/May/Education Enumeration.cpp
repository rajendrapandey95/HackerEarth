#include <bits/stdc++.h>
using namespace std;

#define bs 167772161
#define mod bs

int n, k;
vector<int> v;
int ans[1<<20];

long long S[100][100];
long long D[3000];
long long F[3000];
long long DP[3000][3000];
long long fact[1<<21];
map<long long, int> did;
map<long long, vector<long long>> memo;

const int root = 17;
const int root_1 = 29606852;
const int root_pw = 1<<25;

long long pw(long long a, long long b) {
    if (b==0)
        return 1;
    if (b%2)
        return a*pw(a,b-1)%bs;
    return pw(a*a%bs,b/2);
}

long long reverse(long long x) {
    return pw(x,bs-2);
}

void fft (vector<long long> & a, bool invert) {
    int n = (int) a.size();

    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        int wlen = invert ? root_1 : root;
        for (int i=len; i<root_pw; i<<=1)
            wlen = int (wlen * 1ll * wlen % mod);
        for (int i=0; i<n; i+=len) {
            int w = 1;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
                a[i+j] = u+v < mod ? u+v : u+v-mod;
                a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
                w = int (w * 1ll * wlen % mod);
            }
        }
    }
    if (invert) {
        int nrev = reverse (n);
        for (int i=0; i<n; ++i)
            a[i] = int (a[i] * 1ll * nrev % mod);
    }
}

vector<long long> mult (vector<long long> a, vector<long long> b) {
    vector<long long> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
    size_t n = 1;
    while (n < max (a.size(), b.size()))  n <<= 1;
    n <<= 1;
    fa.resize (n),  fb.resize (n);

    fft (fa, false),  fft (fb, false);
    for (size_t i=0; i<n; ++i)
        fa[i] *= fb[i], fa[i]%=bs;
    fft (fa, true);
    return fa;
}

vector<long long> solve(int x) {
    if (did[x])
        return memo[x];
    vector<long long> ret;
    if (x==1) {
        for (int i=0;i<=k;i++)
            ret.push_back(S[k][k-i]);
    } else {
        ret=mult(solve(x/2),solve(x-x/2));
    }
    memo[x]=ret;
    did[x]=1;
    return ret;
}

bool is_root(int x) {
    long long prod=1;
    for (int i=1;i<=(1<<25);i++) {
        prod=prod*x%bs;
        if (prod==1&&i<(1<<25))
            return false;
    }
    return (prod==1);
}

int find_root() {
    for (int i=3;;i++) {
        if (is_root(i))
            return i;
    }
}

int main() {
    fact[0]=1;
    for (int i=1;i<=(1<<20);i++)
        fact[i]=fact[i-1]*i%bs;

    for (int i=0;i<=50;i++)
        for (int j=0;j<=i;j++) {
            if (j==i)
                S[i][j]=1;
            else
                S[i][j]=S[i-1][j-1]+j*S[i-1][j], S[i][j]%=bs;
        }
    
    cin>>n>>k;

    for (int i=0;i<=k;i++)
        D[i]=S[k][k-i];

    vector<long long> F=solve(n);

    long long ans=0;

    for (int bad=0;bad<n*k;bad++) {
        if (bad%2==0)
            ans+=fact[n*k-bad]*F[bad];
        else
            ans-=fact[n*k-bad]*F[bad];
        ans%=bs;
        if (ans<0)
            ans+=bs;
    }

    cout<<ans<<endl;
    return 0;
}
