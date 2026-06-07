class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        static const auto fast_io = [](){
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
            return nullptr;
        }();

        static TreeNode nodes[100001] = {};
        static int is_child[100001] = { false };
        static int generation[100001] = { 0 };
        static int generation_id = 0;

        ++generation_id;

        for(const auto& v : descriptions){
            const int parent = v[0], child = v[1];
            const bool left_child = v[2];
            if(generation[parent] != generation_id){
                TreeNode* temp = &nodes[parent];
                temp->left = temp->right = nullptr;
                temp->val = parent;
                generation[parent] = generation_id;
            }
            if(generation[child] != generation_id){
                TreeNode* temp = &nodes[child];
                temp->left = temp->right = nullptr;
                temp->val = child;
                generation[child] = generation_id;
            }
            TreeNode* parent_node = &nodes[parent];
            TreeNode* child_node = &nodes[child];
            if(left_child){
                parent_node->left = child_node;
            } else {
                parent_node->right = child_node;
            }
            is_child[child] = true;
        }
        int root = -1;
        for(const auto& v : descriptions){
            const int parent = v[0];
            if(!is_child[parent]){
                root = parent;
                break;
            }
        }
        for(const auto& v : descriptions){
            const int parent = v[0], child = v[1];
            is_child[parent] = false;
            is_child[child] = false;
        }

        return &nodes[root];
    }
};
