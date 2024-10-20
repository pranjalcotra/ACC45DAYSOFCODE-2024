#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); 
        ListNode* current = dummy;        
        int carry = 0;                     

        // Loop through both linked lists until both are exhausted and no carry remains
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0; // Get the value of the current node in l1 (or 0 if null)
            int val2 = (l2 != nullptr) ? l2->val : 0; // Get the value of the current node in l2 (or 0 if null)

            int sum = val1 + val2 + carry; // Add the values and the carry
            carry = sum / 10;              // Calculate the new carry (sum divided by 10)
            current->next = new ListNode(sum % 10); // Create a new node with the single-digit result
            current = current->next;       // Move to the next node

            // Move to the next nodes in l1 and l2, if available
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummy->next; // Return the next node after dummy, which is the head of the result list
    }
};

// Function to print the linked list
void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val;
        if (node->next != nullptr) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Create the first linked list: 2 -> 4 -> 3 (represents the number 342)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Create the second linked list: 5 -> 6 -> 4 (represents the number 465)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Add the two numbers
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result: 7 -> 0 -> 8 (represents the number 807)
    printList(result);

    return 0;
}