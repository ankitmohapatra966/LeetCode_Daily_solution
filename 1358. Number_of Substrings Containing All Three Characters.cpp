class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[3] = {-1, -1, -1}, left = 0, count = 0;
        for(int right = 0; right < s.size(); right++){
            char c = s[right];
            last[c - 'a'] = right;
            if(last[0] != -1 && last[1] != -1 && last[2] != -1){
                count += min({last[0], last[1], last[2]}) + 1;
            }
        }

        return count;
    }
};
