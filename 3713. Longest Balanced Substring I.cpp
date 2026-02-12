class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();

        // Transform char -> int
        vector<int> a(n);
        for (int i = 0; i < n; ++i) 
            a[i] = s[i] - 'a';

        int result = 0;
        for (int l = 0; l < n; ++l) {
            // Early exit, can't be bigger
            if (n - l <= result) break;

            int cnt[26] = {0};          // Counts of every char
            int uniq = 0, maxfreq = 0;  // Number of uniq chars and maximum frequency
            for (int r = l; r < n; ++r) {
                int i = a[r];

                // There was no this char before => one more uniq
                if (cnt[i] == 0) ++uniq;

                ++cnt[i];
                // Update max frequency
                if (cnt[i] > maxfreq) 
                    maxfreq = cnt[i];

                // Check if all uniq chars have maxfreq frequency then update the result
                int cur = r - l + 1;
                if (uniq * maxfreq == cur && cur > result)
                    result = cur;
            }
        }
        return result;
    }
};
