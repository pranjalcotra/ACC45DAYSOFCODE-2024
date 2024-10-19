#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;       
        fast = fast->next->next;  

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next;  
    cout << "Has Cycle (Example 1): " << (hasCycle(head1) ? "true" : "false") << endl; 

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = head2;  
    cout << "Has Cycle (Example 2): " << (hasCycle(head2) ? "true" : "false") << endl;  

    ListNode* head3 = new ListNode(1);
    cout << "Has Cycle (Example 3): " << (hasCycle(head3) ? "true" : "false") << endl;  

    return 0;
}
