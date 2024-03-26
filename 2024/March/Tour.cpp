#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> p;
long long arr[1000 + 1][1000 + 1];

int main() {
    long long n, m, tem1, ans = 0;
    string s;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;
        p[s] = i; // map every town to an index
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tem1;
            arr[i][j] = tem1; // 2D array for Distances between towns
        }
    }

    cin >> m;

    int last = 0; // indicates the first town

    for (int i = 0; i < m; i++) {
        cin >> s;
        ans += arr[last][p[s]]; // add the distance between 2 towns to the answer
        last = p[s];            // update the last town
    }

    cout << ans << "\n";

    return 0;
}
