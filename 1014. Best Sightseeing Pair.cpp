int dp[50000];
class Solution {
public:
    int score=0;
    int f(int i, vector<int>& values){
        if (i<0) return 0;
        if(dp[i]!=0) return dp[i];
        int x=values[i], prev=f(i-1, values);
        score=max(score, prev+x-i);
        return dp[i]=max(prev, x+i);
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        const int n=values.size();
        fill(dp, dp+n, 0);
        f(n-1, values);
        return score;
    }
};
