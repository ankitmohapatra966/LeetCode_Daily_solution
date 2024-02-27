class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        diameter(root, res);
        return res;
    }

private:
    int diameter(TreeNode* curr, int& res){
        if (!curr) return 0;

        int left = diameter(curr->left, res);
        int right = diameter(curr->right, res);
        res = std::max(res, left + right);
        
        return std::max(left, right) + 1;
    }
};
