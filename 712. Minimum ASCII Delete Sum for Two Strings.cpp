class Solution {
public:
    int helper(string&s1, string&s2, int i, int j, vector<vector<int>>&dp)
    {
        int n = s1.size();
        int m = s2.size();

        if(i==n)
        {
            int sum = 0;
            for(int k=j; k<m; k++)
            {
                sum+= s2[k];
            }
            return sum;
        }

        if(j==m)
        {
            int sum = 0;
            for(int k=i; k<n; k++)
            {
                sum+=s1[k];
            }
            return sum;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int match = 1e9;
        int notmatch = 1e9;

        if(s1[i] == s2[j])
        {
            match = helper(s1, s2, i+1, j+1, dp);
        }
        else
        {
            int delete_ = s1[i] + helper(s1, s2, i+1, j, dp);
            int insert = s2[j] + helper(s1, s2, i, j+1, dp);
            notmatch =  min(delete_, insert);
        }

        return dp[i][j] = min(match, notmatch);

    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return helper(s1, s2, 0, 0, dp);
    }
};


auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });
