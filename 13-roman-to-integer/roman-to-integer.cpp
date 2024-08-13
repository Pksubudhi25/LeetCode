class Solution {
public:
    int getIntValue(char c){
        if(c == 'I') return 1;
        else if(c == 'V') return 5;
        else if(c == 'X') return 10;
        else if(c == 'L') return 50;
        else if(c == 'C') return 100;
        else if(c == 'D') return 500;
        else if(c == 'M') return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int ans = 0;
        for(int i=0;i<s.size()-1;i++){
            if(getIntValue(s[i])<getIntValue(s[i+1]))
                ans -=getIntValue(s[i]);
            else{
                ans += getIntValue(s[i]);
            }
        }
        ans += getIntValue(s[s.size() - 1]);
        return ans;
    }
};