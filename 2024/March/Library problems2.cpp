#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        
        while (currNode != nullptr) {
            ListNode* nextNode = currNode->next;  // Store reference to next node
            currNode->next = prevNode;            // Reverse pointer direction
            
            // Move to the next pair of nodes
            prevNode = currNode;
            currNode = nextNode;
        }
        
        // Return the new head of the reversed list
        return prevNode;
    }
};

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* reversedList = sol.reverseList(head);

    // Print the reversed list
    while (reversedList != nullptr) {
        std::cout << reversedList->val << " ";
        reversedList = reversedList->next;
    }
    std::cout << std::endl;

    return 0;
}
