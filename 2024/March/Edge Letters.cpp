#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    int q;
    cin >> s >> q;
    int n = s.length();

    vector<vector<int>> cnt(26, vector<int>(26, 0));
    vector<int> prefix_cnt(26, 0);

    for(int i = 0; i < n; i++) {
        int d2 = s[i] - 'a';
        prefix_cnt[d2]++;
        for(int d1 = 0; d1 < 26; d1++) {
            cnt[d1][d2] += prefix_cnt[d1];
        }
    }

    while(q--) {
        char x, y;
        cin >> x >> y;
        int d1 = x - 'a';
        int d2 = y - 'a';
        cout << cnt[d1][d2] << '\n';
    }

    return 0;
}
