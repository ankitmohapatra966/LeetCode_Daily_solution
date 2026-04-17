class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> last;
        last.reserve(nums.size() * 2);

        int ans = INT_MAX;

        last[rev(nums[0])] = 0;

        for (int j = 1; j < (int)nums.size(); j++) {
            auto it = last.find(nums[j]);
            if (it != last.end()) {
                ans = min(ans, abs(j - it->second));
            }
            last[rev(nums[j])] = j;
        }

        return ans == INT_MAX ? -1 : ans;
    }

    int rev(int n) {
        int ans = 0;
        while (n > 0) {
            ans = ans * 10 + (n % 10);
            n /= 10;
        }
        return ans;
    }
};
