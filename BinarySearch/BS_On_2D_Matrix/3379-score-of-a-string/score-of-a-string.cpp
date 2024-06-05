class Solution {
public:
    int absolute(int n){
        if(n<0){
            return -n;
        }
        else
            return n;
    }
    int scoreOfString(string s) {
        int score =0;
        for(int i=0;i<=s.size()-2;i++){
            int diff = s[i]-s[i+1];
            score += absolute(diff);
        }
        return score;
    }
};