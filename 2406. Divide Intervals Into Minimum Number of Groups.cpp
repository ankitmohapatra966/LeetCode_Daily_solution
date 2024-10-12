class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        vector<pair<int,int>> timelines;
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            timelines.push_back({intervals[i][0],0});
            timelines.push_back({intervals[i][1],1});
        }
        sort(timelines.begin(), timelines.end());
        int cnt = 0, res = 0;
        for(const auto &x : timelines){
            if(x.second == 0) res = max(res,++cnt);
            else cnt--;
        }
        return res;
    }
};
