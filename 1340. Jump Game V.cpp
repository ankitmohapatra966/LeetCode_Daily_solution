class Solution {
public:
    int helper(vector<int>& arr, int d, int idx, vector<int>& dp) {
        int result = 1;
        if (dp[idx] != -1) {
            return max(result, dp[idx]);
        }

        for (int i = idx - 1; i >= max(idx - d, 0) && arr[idx] > arr[i]; i--) {
            if (dp[i] != -1) {
                result = max(result, 1 + dp[i]);
            } else {
                result = max(result, 1 + helper(arr, d, i, dp));
            }
        }

        int n = arr.size();
        for (int i = idx + 1; i <= min(idx + d, n - 1) && arr[idx] > arr[i];
             i++) {
            if (dp[i] != -1) {
                result = max(result, 1 + dp[i]);
            } else {
                result = max(result, 1 + helper(arr, d, i, dp));
            }
        }

        return dp[idx] = result;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] != -1)
                maxi = max(maxi, dp[i]);
            else
                maxi = max(maxi, helper(arr, d, i, dp));
        }
        return maxi;
    }
};
