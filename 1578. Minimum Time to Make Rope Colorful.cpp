class Solution {
public:
    int minCost(string& colors, vector<int>& neededTime) {
        const int n=colors.size();
        int removes=0;
        int locMax=neededTime[0], sum=neededTime[0];
        for (int r=1; r<n; r++) {
            const int x=neededTime[r];
            if (colors[r]==colors[r-1]) {
                sum+=x;
                locMax=max(locMax, x);
            } 
            else {
                removes+=sum-locMax;
                sum=x;
                locMax=x;
            }
        }
        removes+=sum-locMax; 
        return removes;
    }
};
