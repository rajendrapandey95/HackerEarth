#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

using lli = long long;

vector<lli> palindromes;

lli cal(string p) {
    string p1 = p;
    reverse(p1.begin(), p1.end());
    p += p1;
    lli ans = 0;
    for (int i = p.size() - 1; i >= 0; i--) {
        if (p[i] == '1') ans += (1LL << (p.size() - 1 - i));
    }
    return ans;
}

lli cal1(string p) {
    string p1 = p;
    reverse(p1.begin(), p1.end());
    p1.erase(p1.begin());
    p += p1;
    lli ans = 0;
    for (int i = p.size() - 1; i >= 0; i--) {
        if (p[i] == '1') ans += (1LL << (p.size() - 1 - i));
    }
    return ans;
}

void f(int idx, string p, int flag) {
    if (idx == 16) {
        palindromes.push_back(cal(p));
        if (!p.empty()) palindromes.push_back(cal1(p));
        return;
    }
    if (flag == 0) {
        f(idx + 1, p, 0);
        f(idx + 1, p + "1", 1);
    }
    else {
        f(idx + 1, p + "0", 1);
        f(idx + 1, p + "1", 1);
    }
}

int main() {
    int t;
    lli idx, ans, n;
    cin >> t;
    assert(t >= 1 && t <= 100000);

    f(0, "", 0);
    sort(palindromes.begin(), palindromes.end());
    
    while (t--) {
        cin >> n;
        assert(n >= 0 && n <= 2000000000);
        idx = lower_bound(palindromes.begin(), palindromes.end(), n) - palindromes.begin();
        ans = palindromes[idx] - n;
        if (idx > 0) ans = min(ans, n - palindromes[idx - 1]);
        cout << ans << endl;
    }
    
    return 0;
}
