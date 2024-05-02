#include <bits/stdc++.h>
using namespace std;

class BinaryBlocks {
public:
    vector<vector<int>> grid;

    int sum(int x1, int y1, int x2, int y2) {
        x2 = min((int)grid.size() - 1, x2);
        y2 = min((int)grid[0].size() - 1, y2);

        return grid[x2][y2] - grid[x2][y1 - 1] - grid[x1 - 1][y2] + grid[x1 - 1][y1 - 1];
    }

    void solve(istream& in, ostream& out) {
        int n, m;
        in >> n >> m;
        grid.assign(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            string s;
            in >> s;
            for (int j = 1; j <= m; j++) {
                grid[i][j] = s[j - 1] - '0' + grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
            }
        }

        int ret = n * m;
        for (int k = 2; k < max(n, m); k++) {
            int ss = 0;
            for (int x = 1; x <= n; x += k) {
                for (int y = 1; y <= m; y += k) {
                    int g = sum(x, y, x + k - 1, y + k - 1);
                    ss += min(g, k * k - g);
                }
            }
            ret = min(ret, ss);
        }
        out << ret << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    BinaryBlocks solver;
    solver.solve(cin, cout);
    return 0;
}
