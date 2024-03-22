class Solution {
public:
    // time/space: O(n)/O(1)
    bool isPalindrome(ListNode* head) {
        // find the middle node
        ListNode *slow = head, *fast = head;
        while ((fast != NULL) && (fast->next != NULL)) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second half part
        ListNode *prev = NULL, *curr = slow;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // compare between left and right
        ListNode *left = head, *right = prev;
        while ((left != NULL) && (right != NULL)) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        
        return true;
    }
};
