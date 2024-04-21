#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000001;

vector<int> arr(MAX), prime(MAX), primeprime(MAX);

void pre() {
    for(int i = 0; i < MAX; i += 2) 
        arr[i] = 0;
    
    for(int i = 3; i < MAX; i += 2) 
        arr[i] = 1;
    
    for(int i = 3; i * i <= MAX; i += 2) {
        if(arr[i]) {
            for(int j = i * i; j < MAX ; j += (i << 1)) 
                arr[j] = 0;
        }
    }
    
    prime[2] = 1;
    arr[2] = 1;
    
    for(int i = 3; i < MAX; i++) {
        if(arr[i])
            prime[i] = prime[i - 1] + 1;
        else
            prime[i] = prime[i - 1];
    }
    
    primeprime[0] = 0;
    primeprime[1] = 0;
    
    for(int i = 2; i < MAX; i++) {
        if(arr[prime[i]]) 
            primeprime[i] = primeprime[i - 1] + 1;
        else
            primeprime[i] = primeprime[i - 1];
    }
}

int main() {
    pre();
    int T;
    cin >> T;
    while(T--) {
        int L, R;
        cin >> L >> R;
        cout << primeprime[R] - primeprime[L - 1] << endl;
    }
    return 0;
}
