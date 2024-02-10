#include<bits/stdc++.h>
using namespace std;


int hammingDistance(int x, int y) {
    int xorResult = x ^ y;
    int distance = 0;
    while (xorResult) {
        distance += xorResult & 1;
        xorResult >>= 1;
    }
    return distance;
}

bool customCompare(int a, int b, int k) {
    int distA = hammingDistance(a, k);
    int distB = hammingDistance(b, k);
    if (distA != distB) {
        return distA < distB;
    } else {
        return a < b;
    }
}

vector<int> solve(int N, int K, vector<int> A) {
    sort(A.begin(), A.end(), [K](int a, int b) {
        return customCompare(a, b, K);
    });
    return A;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        vector<string> custom_input_1(2);
        for(int i_custom_input_1 = 0; i_custom_input_1 < 2; i_custom_input_1++)
        {
        	cin >> custom_input_1[i_custom_input_1];
        }
        int N = stoi(custom_input_1[0]);
        int K = stoi(custom_input_1[1]);
        vector<int> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
        	cin >> A[i_A];
        }

        vector<int> out_;
        out_ = solve(N, K, A);
        cout << out_[0];
        for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
        	cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}
