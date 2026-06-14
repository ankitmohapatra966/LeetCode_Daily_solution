class Solution {
public:
    static int pairSum(ListNode* head) {
        ListNode *fast=head, *slow=fast;
        ListNode *rev=NULL, *nextNode;
        while(fast){
            fast=fast->next->next;
            nextNode=slow->next;
            slow->next=rev;
            rev=slow;
            slow=nextNode;           
        }
        int ans=0;
        while(slow){
            int x=rev->val;
            rev=rev->next;
            ans=max(ans, x+(slow->val));
            slow=slow->next;
        }
        return ans;
    }
};
