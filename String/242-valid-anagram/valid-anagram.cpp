class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int>s_map;
        unordered_map<char,int>t_map;
        for(int i=0;i<s.size();i++)
            s_map[s[i]]++;
        for(int j=0;j<t.size();j++)
            t_map[t[j]]++;
        
        for(int k=0;k<s.size();k++){
            char s_char = s[k];
            if(s_map[s_char] != t_map[s_char])
                return false;
        }
        return true;
    }
};