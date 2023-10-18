class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> str;
        set<string> unique;
        unordered_map<char,string> mpp;
        string s1="";

        int j=0;
        while(j<s.size()){            
            if(s[j]!=' '){
                s1+=s[j];
            }
            if(s[j]==' ' || j==s.size()-1){
                str.push_back(s1);
                cout<<s1<<endl;
                s1="";
            }
            j++;
        }

        if(str.size()!=pattern.size()) return false;

        for(int i=0;i<pattern.size();i++){

            if(mpp.find(pattern[i])!=mpp.end() && mpp[pattern[i]]!=str[i]) return false;
            else if(mpp.find(pattern[i])==mpp.end() && !unique.insert(str[i]).second) return false; 
            mpp[pattern[i]]=str[i];
        }

        return true;
    }
};