class Solution {
public:
    int longestPalindrome(string s) {
        int len=0;
        int odd=0;
        unordered_map<char,int>map;
        for(auto ch:s){
            map[ch]++;
        }
        for(auto it:map){
            if(it.second % 2 ==0)
                len+=it.second;
            else{
                len+=it.second-1;
                odd=1;
            }
        }
        return len+odd;
    }
};