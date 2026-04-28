class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        int N = n * m;
        vector<int> data(10001, 0);
        int num0 = grid[0][0];
        int minValue(num0), maxValue(num0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((grid[i][j] - num0)%x != 0) {
                    return -1;
                }
                data[grid[i][j]]++;
                minValue = min(minValue, grid[i][j]);
                maxValue = max(maxValue, grid[i][j]);
            }
        }
        int count(0);
        for (int i = minValue + x; i <= maxValue; i += x) {
            count += (i - minValue)/x * data[i];
            data[i] = data[i] + data[i - x];
        }

        for (int i = minValue + x; i <= maxValue; i += x) {
            count = min(count, count + data[i - x] - (data[maxValue] - data[i - x]));
        }
        return count;
    }
};
