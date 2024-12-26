class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int S = accumulate(nums.begin(), nums.end(), 0);
        if (S < abs(target) || (S + target) % 2 != 0) return 0;

        int P = (S + target) / 2;
        vector<int> dp(P + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int j = P; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }

        return dp[P];
    }
};
