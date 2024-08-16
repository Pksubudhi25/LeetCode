class Solution {
public:
    
    string intToRoman(int num) {
        vector<string> m = {"","M","MM","MMM"};
        vector<string> c = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        vector<string> x = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        vector<string> i  = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string thousands = m[num/1000];
        string hundreds = c[(num%1000)/100];
        string tens = x[(num%100)/10];
        string ones = i[(num%10)];
        string ans = thousands+hundreds+tens+ones;
        return ans;
    }
};