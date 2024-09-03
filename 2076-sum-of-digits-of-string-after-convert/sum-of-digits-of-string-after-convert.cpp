class Solution {
public:
    int sumOfDigits(string given){
        int sum = 0;
        for(int i=given.size()-1;i>=0;i--){
            sum += given[i]-'0'; // convert character to integer
        }
        return sum;
    }
    int getLucky(string s, int k) {
        string given = "";
        for(int i=0;i<s.size();i++){
            int num = s[i]-'a'+1;
            given += to_string(num);
        }
        int ans = sumOfDigits(given);
        while(--k > 0){
            ans = sumOfDigits(to_string(ans));
        }
        return ans;
    }
};