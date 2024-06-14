#include <string>
#include <algorithm>

class Solution {
public:
    std::string reverseWords(std::string s) {
        int i = 0, l = 0, r = 0;
        int n = s.size();
        reverse(s.begin(), s.end());  // Reverse the entire string first
        
        while (i < n) {
            while (i < n && s[i] != ' ') {
                s[r++] = s[i++];
            }
            if (l < r) {  // If there was a word, reverse it
                reverse(s.begin() + l, s.begin() + r);
                if (r < n) {  // Add a space after the word if not at the end
                    s[r++] = ' ';
                }
                l = r;  // Move the left index to the start of the next word
            }
            i++;
        }

        // Remove the trailing space if it exists
        if (r > 0 && s[r - 1] == ' ') {
            r--;
        }

        return s.substr(0, r);
    }
};
