#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* next_node = removeNodes(head->next);

        if (head->val < next_node->val)
            return next_node;

        head->next = next_node;
        return head;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ListNode* head = new ListNode(a[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(a[i]);
        current = current->next;
    }

    Solution sol;
    ListNode* new_head = sol.removeNodes(head);

    current = new_head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    while (new_head) {
        ListNode* temp = new_head;
        new_head = new_head->next;
        delete temp;
    }

    return 0;
}
