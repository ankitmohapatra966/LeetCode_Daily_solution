class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, bool> map;
        int count = 0;

        for (const string& item : arr) {
            if (map.find(item) != map.end()) {
                map[item] = false;
            } else {
                map[item] = true;  
            }
        }

        for (const string& item : arr) {
            if (map[item]) {  
                count++;
                if (count == k) {
                    return item;
                }
            }
        }

        return ""; 
    }
};
