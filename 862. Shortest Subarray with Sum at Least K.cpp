const int MAX_N = 100000 + 1;

int* nums;

long long st_s[MAX_N];
int pos[MAX_N];

class Solution {
public:
    int shortestSubarray(vector<int>& _nums, int k) {
        int n = _nums.size();
        nums = &_nums[0];
        
        long long sp = 0LL;
        int res = n + 1;

        int b = 0, e = 0;
        st_s[e] = 0;
        pos[e++] = -1;

        for (int i = 0; i < n; i++) {
            sp += nums[i];

            while (b < e && sp - st_s[b] >= k) {
                res = std::min(res, i - pos[b]);
                b++;
            }

            while (b < e && sp <= st_s[e - 1])
                e--;
            st_s[e] = sp;
            pos[e++] = i;
        }

        if (res == n + 1)
            return -1;
        return res;
    }
};
