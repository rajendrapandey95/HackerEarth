#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Hacker {
private:
    vector<int> parent;
    vector<int> size;

    int find(int i) {
        if (parent[i] != i) {
            return find(parent[i]);
        }
        return i;
    }

    void unionSet(int a, int b) {
        int x = find(a);
        int y = find(b);

        if (x != y) {
            if (size[x] > size[y]) {
                size[x] += size[y];
                parent[y] = x;
            } else {
                size[y] += size[x];
                parent[x] = y;
            }
        }
    }

public:
    string solution(const string& a, const string& b, const string& c) {
        parent.resize(26);
        size.resize(26);

        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
            size[i] = 1;
        }

        for (int i = 0; i < a.length(); ++i) {
            int x = a[i] - 'a';
            int y = b[i] - 'a';
            unionSet(x, y);
        }

        string ans = "";
        for (char ch : c) {
            int f = find(ch - 'a');
            for (int j = 0; j < 26; ++j) {
                if (find(j) == f) {
                    ans += ('a' + j);
                    break;
                }
            }
        }
        return ans;
    }

    void solve() {
        string a, b, c;
        cin >> a >> b >> c;
        cout << solution(a, b, c) << endl;
    }
};

int main() {
    Hacker hacker;
    hacker.solve();
    return 0;
}
