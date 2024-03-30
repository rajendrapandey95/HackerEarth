#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m[a[i] - i]++;
    }

    long long c = 0; // Changed type to long long to match 'int' definition in main
    for (const auto& [key, value] : m) { // Using structured binding introduced in C++17
        c += static_cast<long long>(value) * (value - 1); // Explicit cast to avoid potential overflow
    }
    cout << c << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);

    solve();

    return 0;
}
