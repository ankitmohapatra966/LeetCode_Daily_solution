class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        const int MOD=1000000007;
        const int M=200;
        vector<vector<int>>dp(M+1,vector<int>(M+1));
        dp[0][0]=1;
        for(int x:nums){
            vector<vector<int>> ndp=dp;
            for(int g1=0;g1<=M;g1++){
                for(int g2=0; g2<=M;g2++){
                    int cur=dp[g1][g2];
                    if(!cur) continue;
                    int ng1=g1 == 0 ? x:std::gcd(g1,x);
                    int &a=ndp[ng1][g2];
                    a +=cur;
                    if(a>=MOD) a-=MOD;
                    int ng2=g2==0 ? x:std::gcd(g2,x);
                    int &b=ndp[g1][ng2];
                    b+=cur;
                    if(b>=MOD) b-=MOD;
                }
            }
            dp.swap(ndp);
        }
        long long ans=0;
        for(int g=1;g<=M;g++){
            ans+=dp[g][g];
        }
        return ans%MOD;
    }
};
