#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size(), k = n / 3;
        vector<long long> leftMins(n, 0), rightMaxs(n, 0);

        priority_queue<int> maxLeft;
        long long leftSum = 0;

        for (int i = 0; i < k; ++i) {
            maxLeft.push(nums[i]);
            leftSum += nums[i];
        }
        leftMins[k - 1] = leftSum;

        for (int i = k; i < n - k; ++i) {
            if (nums[i] < maxLeft.top()) {
                leftSum += nums[i] - maxLeft.top();
                maxLeft.pop();
                maxLeft.push(nums[i]);
            }
            leftMins[i] = leftSum;
        }

        priority_queue<int, vector<int>, greater<int>> minRight;
        long long rightSum = 0;

        for (int i = n - 1; i >= n - k; --i) {
            minRight.push(nums[i]);
            rightSum += nums[i];
        }
        rightMaxs[n - k] = rightSum;

        for (int i = n - k - 1; i >= k - 1; --i) {
            if (nums[i] > minRight.top()) {
                rightSum += nums[i] - minRight.top();
                minRight.pop();
                minRight.push(nums[i]);
            }
            rightMaxs[i] = rightSum;
        }

        long long minDiff = LLONG_MAX;
        for (int i = k - 1; i < n - k; ++i) {
            minDiff = min(minDiff, leftMins[i] - rightMaxs[i + 1]);
        }

        return minDiff;
    }
};
