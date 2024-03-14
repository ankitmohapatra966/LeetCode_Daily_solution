#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    //count the subarrays having sum<=goal.
    int n;
    int atmost(vector<int>&nums, int goal){ 
        int sum=0, l=0, r=0, cnt=0;
        for(; r<n; r++){
            sum+=nums[r]; 
            for(; sum>goal; l++)
                sum-=nums[l];
            //add the length of each subarray 
            cnt+=(r-l+1);
        }       
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        n=nums.size();
        return goal>0?atmost(nums,goal)-atmost(nums,goal-1):atmost(nums,0);
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
