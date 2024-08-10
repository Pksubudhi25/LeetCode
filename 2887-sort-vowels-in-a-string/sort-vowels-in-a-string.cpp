class Solution {
public:
    string sortVowels(string s) {
        vector<int> upper(26,0);
        vector<int> lower(26,0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                lower[s[i]-'a']++;
                s[i] = '#';
            }
            else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                upper[s[i]-'A']++;
                s[i] = '#';
            }
        }
        string ans;
        for(int i=0;i<26;i++){
            char c = i + 'A';
            while(upper[i]){
                ans+=c;
                upper[i]--;
            }
        }
        for(int i=0;i<26;i++){
            char c = i+'a';
            while(lower[i]){
                ans += c;
                lower[i]--;
            }
        }
        int index1 =0, index2=0;
        while(index2 < ans.size()){
            if(s[index1] == '#'){
                s[index1] = ans[index2];
                index2++;
            }
            index1++;
        }
        return s;    
    }
};