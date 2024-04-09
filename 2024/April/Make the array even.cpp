#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        int len = 0;
        
        while (n--) {
            int x;
            cin >> x;
            
            if (x % 2)
                len++;
            else {
                ans += len + (len % 2) * 3;
                len = 0;
            }
        }
        
        ans += len + (len % 2) * 3;
        cout << ans / 2 << '\n';
    }
    return 0;
}
