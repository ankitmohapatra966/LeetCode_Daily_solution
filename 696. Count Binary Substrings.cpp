class Solution {
public:
    int countBinarySubstrings(string s) {
    int ans = 0, previous = 0, current = 1;
    for(int i = 1 ; i < s.size() ; i++){
        if(s[i] == s[i-1]) current++;
        else{
            previous = current;
            current = 1;
        }
        if(current <= previous) ans++;
    }
    return ans;
        
       
    }
};
