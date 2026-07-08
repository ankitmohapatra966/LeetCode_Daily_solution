class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int kMod = 1e9 + 7;
        const int n = s.length();

        vector<int> idx(n+1);
        vector<long long> val(n+1);
        vector<long long> total(n+1);
        vector<long long> pow10(n+1, 1);

        for (int i = 1; i <= n; ++i) {
            pow10[i] = (pow10[i-1] * 10) % kMod;
        }

        int c = 0;

        for (int i = 0; i < n; ++i) {
            const int d = s[i] - '0';
            if (0 != d) {
                ++c;
                val[c] = (val[c-1]*10 + d) % kMod;
                total[c] = total[c-1] + d;
            }
            idx[i+1] = c;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q: queries) {
            const int l = q[0];
            const int r = q[1];

            const int a = idx[l];
            const int b = idx[r+1];

            if (a == b) {
                ans.push_back(0);
                continue;
            }

            const int len = b-a;

            long long num = (val[b] - val[a] * pow10[len]) % kMod;
            if (num < 0) {
                num += kMod;
            }

            long long sum = total[b] - total[a];
            ans.push_back((num * sum) % kMod);
        }

        return ans;
    }
};
