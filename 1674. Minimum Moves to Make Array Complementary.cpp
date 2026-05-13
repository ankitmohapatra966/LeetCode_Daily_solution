const int M=2e5+2;
int sweep[M];
class Solution {
public:
    static int minMoves(vector<int>& nums, int limit) {
        const int lim2=limit*2, n=nums.size(), h=n/2;
        memset(sweep+2, 0, lim2*sizeof(int));
        int y_lim=0;
        for(int i=0; i<h; i++){
            auto [x, y]=minmax(nums[i], nums[n-1-i]);
            const int s=x+y;
            sweep[2]+=2;
            sweep[x+1]--;
            sweep[s]--;
            sweep[s+1]++;
            sweep[y+limit+1]++;
            y_lim=max(y_lim, y+limit);
        }
        int ans=n, cnt=0;
        for(int s=2; s<=y_lim; s++)
            ans=min(ans, cnt+=sweep[s]);
        return ans;
    }
};
