class Solution {
public:
    vector<TreeNode*> arr;
    void inOrder(TreeNode* root){
        if (!root) return;
        inOrder(root->left);
        arr.push_back(root);
        inOrder(root->right);
    }

    TreeNode* balanceBST(const int l, const int r){
        if (l>r) return NULL;
        const int m=(l+r)/2;
        TreeNode* const left=balanceBST(l, m-1);
        TreeNode* const right=balanceBST(m+1, r);
        arr[m]->left=left;
        arr[m]->right=right;
        return arr[m];
    }

    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        return balanceBST(0, arr.size()-1);
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
