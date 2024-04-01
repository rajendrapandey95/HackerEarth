#include <iostream>

using namespace std;

// Function to calculate GCD (Greatest Common Divisor)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int tests;
    cin >> tests;

    while (tests--) {
        int n;
        cin >> n;
        int g = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (i == 0)
                g = x;
            else
                g = gcd(g, x);  // Using the custom gcd function
        }
        
        if (g == 1)
            cout << "FINITE" << endl;
        else
            cout << "INFINITE" << endl;
    }

    return 0;
}
