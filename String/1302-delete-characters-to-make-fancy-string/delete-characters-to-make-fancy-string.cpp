class Solution {
public:
    string makeFancyString(string s) 
    {
        string ans="";
        ans+=s[0];
        int count=1;
        for(int i=1;i<s.length();i++)
        {
            if(ans.back()==s[i] && count<2)
            {
                ans+=s[i];
                count++;
            }
            else if(count>=2 && ans.back()==s[i])
            {
                
                continue;
            }
            else
            {
                ans+=s[i];
                count=1;
            }

        }
        return ans;
    }
};