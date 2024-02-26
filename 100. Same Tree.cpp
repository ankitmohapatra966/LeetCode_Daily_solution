class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p ==  NULL && q == NULL)return true;
        if(p == NULL || q == NULL)return false;
        bool leftSubTreeCheck = isSameTree(p->left, q->left), rightSubTreeCheck = isSameTree(p->right, q->right);
        return p->val == q->val && leftSubTreeCheck && rightSubTreeCheck;
    }
};
