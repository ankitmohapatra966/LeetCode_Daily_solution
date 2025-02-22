class Solution {
public:
    TreeNode* recoverFromPreorder(string t) {
        unordered_map<int,TreeNode*> par;
        int od= 0;
        int nd=0;
        int i = 0;
        string a;
        while(t[i]>=48 && t[i]<=57){
                a += t[i];
                i++;
            }
            TreeNode* root = new TreeNode(stoi(a));
            par[0]= root;
        while(i<t.length()){
            while(t[i]=='-'){
                nd++;
                i++;
            }
            string s;
            while(t[i]>=48 && t[i]<=57){
                s += t[i];
                i++;
            }
            if(nd>od){
                par[od]->left = new TreeNode(stoi(s));
                par[nd] = par[od]->left;
                od = nd;
                nc = 0;
                
            }else if(nd==od){
                par[od-1]->right = new TreeNode(stoi(s));
                par[od] = par[od-1]->right;
                nd = 0;
            }else{
                par[nd-1]->right = new TreeNode(stoi(s));
                par[nd] = par[nd-1] ->right;
                od = nd;
                nd = 0;

            }
        }
        return root;
    }
};
