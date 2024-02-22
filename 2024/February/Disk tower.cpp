#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
using namespace std;

vector<vector<int>> SolveTower(int N, vector<int> a) {
    vector<vector<int>> ans;
    int done = N;
    priority_queue<int> pq;
    for (auto x : a) {
        pq.push(x);
        vector<int> aux;
        while (!pq.empty() && pq.top() == done) {
            aux.push_back(done);
            pq.pop();
            done--;
        }
        ans.push_back(aux);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    assert(a.size() == N);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    assert(1 <= N && N <= 1e6);
    vector<int> a(N);
    for (int i_a = 0; i_a < N; i_a++) {
        cin >> a[i_a];
    }

    vector<vector<int>> out_;
    out_ = SolveTower(N, a);
    for (int i = 0; i < out_.size(); i++) {
        for (int j = 0; j < out_[i].size(); j++) {
            cout << out_[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
