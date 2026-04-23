#include <vector>
#include <algorithm>

using namespace std;

static const int adcelerator = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

struct Node {
    int val;
    int idx;
};

class Solution {
public:

    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<Node> nodes(n);
        for (int i = 0; i < n; ++i) {
            nodes[i] = {nums[i], i};
        }

        sort(nodes.begin(), nodes.end(), [](const Node& a, const Node& b) {
            if (a.val != b.val) return a.val < b.val;
            return a.idx < b.idx;
        });

        vector<long long> res(n);
        int i = 0;
        while (i < n) {
            int j = i;
            long long group_sum = 0;

            while (j < n && nodes[j].val == nodes[i].val) {
                group_sum += nodes[j].idx;
                j++;
            }

            int m = j - i;
            long long prefix_sum = 0;
            for (int k = 0; k < m; ++k) {
                long long p_k = nodes[i + k].idx;
                
                long long left = k * p_k - prefix_sum;
                long long suffix_sum = group_sum - prefix_sum - p_k;
                long long right = suffix_sum - (long long)(m - 1 - k) * p_k;
                
                res[p_k] = left + right;
                prefix_sum += p_k;
            }
            i = j; 
        }

        return res;
    }
};
