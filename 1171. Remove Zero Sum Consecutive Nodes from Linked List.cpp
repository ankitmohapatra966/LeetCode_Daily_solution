#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode node=ListNode(0, head);
        unordered_map<int, ListNode*> mp;//or use map
        int prefix=0;
        for(ListNode* ptr=&node; ptr; ptr=ptr->next){
            prefix+=(ptr->val);
            mp[prefix]=ptr;
        }
        prefix=0;//reset
        for(ListNode* ptr=&node; ptr; ptr=ptr->next){
            prefix+=(ptr->val);
            ptr->next=mp[prefix]->next;
        }
        return node.next;
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
