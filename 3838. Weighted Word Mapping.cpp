class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int h = 0;
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            int weight = 0;
            for (int j = 0; j < words[i].size(); j++) {
                weight += weights[words[i][j] - 'a'];
            }
            result += 'z' - (weight%26);
        }
        return result;
    }
};
