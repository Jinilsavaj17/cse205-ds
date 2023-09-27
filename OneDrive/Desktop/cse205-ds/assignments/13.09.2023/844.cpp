class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char> s1;
        stack<char> s2;

        for(int i=0;i<s.size();i++){
            if(s[i]!='#') s1.push(s[i]);
            else if(s[i]=='#' && !s1.empty()) s1.pop();       
        }

        for(int j=0;j<t.size();j++){
            if(t[j]!='#') s2.push(t[j]);
            else if(t[j]=='#' && !s2.empty()) s2.pop();
        }
        
        return s1==s2;
    }
};