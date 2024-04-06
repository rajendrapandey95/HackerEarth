#include <iostream>
#include <vector>

using namespace std;

string minRemoveToMakeValid(const string& s) {
    stack<int> st;
    unordered_set<int> to_remove;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            if (!st.empty()) {
                st.pop();
            } else {
                to_remove.insert(i);
            }
        }
    }

    while (!st.empty()) {
        to_remove.insert(st.top());
        st.pop();
    }

    string result;
    for (int i = 0; i < s.length(); ++i) {
        if (!to_remove.count(i)) {
            result.push_back(s[i]);
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << minRemoveToMakeValid(s) << endl;
    }
    return 0;
}
