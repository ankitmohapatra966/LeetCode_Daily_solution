class Solution {
    vector<int> calcZ(const string &s) {
        int size = s.size();
        vector<int> z(size, 0);
        int l = 0, r = 0;  
        for (int i = 1; i < size; i++) {
            if (i <= r)
                z[i] = min(z[i - l], r - i + 1);
            while (i + z[i] < size && s[z[i]] == s[i + z[i]]) {
                l = i;
                r = i + z[i]++;
            }
        }
        z[0] = size;
        return z;
    }
public:
    string generateString(string str1, string str2) {
        int size1 = str1.size(), size2 = str2.size();
        int wordSize = size1 + size2 - 1;
        string word(wordSize, '*');
        vector<int> z = calcZ(str2);

        int pre = -size2;
        for (int i = 0; i < size1; i++) {
            if (str1[i] == 'F')
                continue;
            int residueLen = max(0, pre + size2 - i);
            if (residueLen && z[size2 - residueLen] < residueLen)
                return "";
            for (int j = residueLen; j < size2; j++) {
                word[i + j] = str2[j];
            }
            pre = i;
        }

        vector<int> lastWild(wordSize, -1);
        pre = -1;
        for (int i = 0; i < wordSize; i++) {
            if (word[i] == '*') {
                word[i] = 'a';
                pre = i;
            }
            lastWild[i] = pre;
        }

        // process F
        z = calcZ(str2 + word);
        for (int i = 0; i < size1; i++) {
            if (str1[i] == 'T' || z[size2 + i] < size2)
                continue;
            int candidatePos = lastWild[i + size2 - 1];
            if (candidatePos < i)
                return "";
            word[candidatePos] = 'b';
            i = candidatePos;
        }
        return word;
    }
};
