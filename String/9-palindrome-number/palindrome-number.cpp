class Solution {
public:
    bool isPalindrome(int x) {
        long long num = x;
        long long reversed = 0;
        while(num > 0){
            int rem = num % 10;
            reversed = reversed*10+rem;
            num = num/10;
        }
        return(reversed == x);
    }
};