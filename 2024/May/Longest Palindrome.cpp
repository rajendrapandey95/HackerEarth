#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    assert(N == 1000);
    assert(K >= 50 && K <= 100);

    string ans;
    cin >> ans;

    for(int i = 1; i <= K - 1; i++) {
        cout << i << endl;
    }   
    cout << N << endl;

    for(int i = 1; i <= K; i++) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
