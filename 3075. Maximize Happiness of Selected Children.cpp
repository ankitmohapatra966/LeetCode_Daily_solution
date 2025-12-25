using namespace std;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin() , happiness.rend());
        int n = happiness.size();
        int h = 0 ;
        long long ct = 0 ;
        long long ans = 0;
        while(k-- and h<n){
            if(happiness[h]-ct<=0)break;
            long long val = max(0LL,happiness[h] - ct);
            ans+=val;
            ct++;
            h++;
        }
        return ans;
    }
};
