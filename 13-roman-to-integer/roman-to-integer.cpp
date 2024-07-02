class Solution {
public:
    int getRomanValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0; // handle invalid characters
        }
    }

    int romanToInt(string s) {
        // The key intuition lies in the fact that in Roman numerals, when a smaller value appears before a larger value, it represents subtraction, while when a smaller value appears after or equal to a larger value, it represents addition.
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && getRomanValue(s[i]) < getRomanValue(s[i + 1])) {
                ans -= getRomanValue(s[i]);
            } else {
                ans += getRomanValue(s[i]);
            }
        }
        return ans;
    }
};
