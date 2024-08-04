class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        int count = 0;
        int odd = 0;

        // Count the frequency of each character
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                lower[s[i] - 'a']++;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                upper[s[i] - 'A']++;
            }
        }

        // Calculate the longest palindrome length
        for (int i = 0; i < 26; i++) {
            if (lower[i] % 2 == 0) {
                count += lower[i];
            } else {
                count += lower[i] - 1;
                odd = 1;
            }
            if (upper[i] % 2 == 0) {
                count += upper[i];
            } else {
                count += upper[i] - 1;
                odd = 1;
            }
        }

        return count + odd;
    }
};
