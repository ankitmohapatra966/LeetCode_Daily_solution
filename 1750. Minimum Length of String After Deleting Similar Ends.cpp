class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        // Iterate until left pointer is less than right pointer and characters match
        while (left < right && s[left] == s[right]) {
            char current = s[left]; // Store the current character for comparison
            // Move left pointer to the right until it points to a different character
            while (left <= right && s[left] == current) {
                left++;
            }
            // Move right pointer to the left until it points to a different character
            while (right >= left && s[right] == current) {
                right--;
            }
        }
        
        // Return the remaining length of the substring
        return max(0, right - left + 1);
    }
};
