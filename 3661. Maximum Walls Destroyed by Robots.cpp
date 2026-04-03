#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
      
        vector<pair<int, int>> rd(n);
        for (int i = 0; i < n; ++i) {
            rd[i] = {robots[i], distance[i]};
        }
        sort(rd.begin(), rd.end());
        sort(walls.begin(), walls.end());

        vector<int> w;
        int base_destroyed = 0;
        int i = 0, j = 0;
        
        while (i < walls.size() && j < n) {
            if (walls[i] < rd[j].first) {
                w.push_back(walls[i]);
                i++;
            } else if (walls[i] == rd[j].first) {
                base_destroyed++; 
                i++;
            } else {
                j++;
            }
        }
        while (i < walls.size()) {
            w.push_back(walls[i]);
            i++;
        }

        int idx = 0;
        int s = 0;
        
        while (idx < w.size() && w[idx] < rd[0].first) {
            idx++;
        }
        int e = idx;
        
        long long reach_L = (long long)rd[0].first - rd[0].second;
     
        int dp0 = (w.begin() + e) - lower_bound(w.begin() + s, w.begin() + e, reach_L);
        int dp1 = 0;

        for (int k = 1; k < n; ++k) {
            s = idx;
            while (idx < w.size() && w[idx] < rd[k].first) {
                idx++;
            }
            e = idx;

            long long X = (long long)rd[k-1].first + rd[k-1].second; 
            long long Y = (long long)rd[k].first - rd[k].second;     

            int count_le_X = upper_bound(w.begin() + s, w.begin() + e, X) - (w.begin() + s);

            int count_ge_Y = (w.begin() + e) - lower_bound(w.begin() + s, w.begin() + e, Y);
            
            int count_union = 0;
            if (X >= Y) {
                count_union = e - s;
            } else {
                count_union = count_le_X + count_ge_Y;
            }


            int next_dp0 = max(dp0 + count_ge_Y, dp1 + count_union);
            int next_dp1 = max(dp0 + 0, dp1 + count_le_X);
            
            dp0 = next_dp0;
            dp1 = next_dp1;
        }

        s = idx;
        e = w.size();
        long long X_last = (long long)rd[n-1].first + rd[n-1].second;
        int count_last = upper_bound(w.begin() + s, w.begin() + e, X_last) - (w.begin() + s);

        int ans = max(dp0, dp1 + count_last);

        return ans + base_destroyed;
    }
};
