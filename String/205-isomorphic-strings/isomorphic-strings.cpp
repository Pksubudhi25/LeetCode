class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,char> map_s_to_t; //to ensure that no s character is mapped to two t character
        unordered_map<char,char> map_t_to_s; // to ensure that no two s character are mapped to same t character
        for(int i=0;i<s.size();i++){
            char s_char = s[i];
            char t_char = t[i];
            if(map_s_to_t.find(s_char) != map_s_to_t.end()){
                if(map_s_to_t[s_char] != t_char) return false;
            }
            else map_s_to_t[s_char] = t_char;

            if(map_t_to_s.find(t_char) != map_t_to_s.end()){
                if(map_t_to_s[t_char] != s_char) return false;
            }
            else map_t_to_s[t_char] = s_char;
        }
        return true;
    }
};