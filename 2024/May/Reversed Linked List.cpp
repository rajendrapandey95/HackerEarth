#include <iostream>
#include <stack>

using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Main function
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    stack<int> stk;
    Node* ptr;
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    
    int n;
    cin >> n;
    
    // Building the linked list
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        Node* tmp = new Node;
        tmp->data = x;
        tmp->next = nullptr;
        if (head1 == nullptr) {
            head1 = tmp;
            ptr = tmp;
        } else {
            ptr->next = tmp;
            ptr = ptr->next;
        }
    }
    
    // Traversing the linked list
    while (head1 != nullptr) {
        if (head1->data % 2 == 0) {
            stk.push(head1->data);
        } else {
            bool flag = true;
            while (!stk.empty() || flag) {
                if (stk.empty())
                    flag = false;
                Node* tmp = new Node;
                tmp->data = flag ? stk.top() : head1->data;
                tmp->next = nullptr;
                if (head2 == nullptr) {
                    head2 = tmp;
                    ptr = tmp;
                } else {
                    ptr->next = tmp;
                    ptr = ptr->next;
                }
                if (!stk.empty())
                    stk.pop();
            }
        }
        head1 = head1->next;
    }
    
    // Pushing remaining even elements
    while (!stk.empty()) {
        Node* tmp = new Node;
        tmp->data = stk.top();
        tmp->next = nullptr;
        if (head2 == nullptr) {
            head2 = tmp;
            ptr = tmp;
        } else {
            ptr->next = tmp;
            ptr = ptr->next;
        }
        stk.pop();
    }
    
    // Printing the modified linked list
    while (head2 != nullptr) {
        cout << head2->data << ' ';
        head2 = head2->next;
    }
    cout << '\n';
    
    return 0;
}
