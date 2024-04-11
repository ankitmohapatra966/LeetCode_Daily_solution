class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        for (char c : num) {
            while (!res.empty() && res.back() > c && k) {
                res.pop_back();
                k--;
            }
            if (res.size() || c != '0')
                res += c;
        }

        while (!res.empty() && k) {
            res.pop_back();
            k--;
        }

        if (res == "") return "0";
        return res;
    }
};
