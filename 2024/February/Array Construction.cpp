#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, b;
        cin >> n;
        priority_queue<ll> q;
        for (int i = 0; i < n; i++) {
            cin >> b;
            q.push(b);
        }
        vector<ll> x;
        string ans = "YES";
        while (q.size() > 2 && q.top() > 1) {
            for (int i = 0; i < 3; i++) {
                x.push_back(q.top());
                q.pop();
            }
            if (x[1] >= 1) {
                if (x[0] - x[1] * x[2] <= x[2] && x[0] - x[1] * x[2] >= 0) x[0] -= x[1] * x[2];
                else if (x[0] % (x[1] + 1) == 0 && x[0] / (x[1] + 1) >= x[2]) x[0] /= x[1] + 1;
                else {
                    ans = "NO";
                    break;
                }
            }
            for (int i = 0; i < 3; i++) q.push(x[i]);
            if (x[1] < 1) break;
            x.clear();
        }
        while (q.size() == 2 && q.top() > 1) {
            for (int i = 0; i < 2; i++) {
                x.push_back(q.top());
                q.pop();
            }
            if (x[1] >= 1) {
                if (x[0] % (x[1] + 1) == 0) x[0] /= x[1] + 1;
                else {
                    ans = "NO";
                    break;
                }
            }
            for (int i = 0; i < 2; i++) q.push(x[i]);
            if (x[1] < 1) break;
            x.clear();
        }
        for (int i = 0; i < 2; i++) {
            x.push_back(q.top());
            q.pop();
        }
        if (x[1] < 1) ans = "NO";
        cout << ans << endl;
    }

    return 0;
}
