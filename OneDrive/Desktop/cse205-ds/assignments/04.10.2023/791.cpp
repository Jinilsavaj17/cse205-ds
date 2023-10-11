class Solution {
public:
    string customSortString(string order, string s) {

        string ans="";
        unordered_map<char,int> mpp;
        for(int i=0;i<s.size();i++) mpp[s[i]]++;

        for(int i=0;i<order.size();i++){
            if(mpp[order[i]]>0){
                while(mpp[order[i]]!=0){
                    ans+=order[i];
                    mpp[order[i]]--;
                }
            }
        }

        // elements which are not present in string order
        for(int i=0;i<s.size();i++){
            if(mpp[s[i]]!=0){
                while(mpp[s[i]]!=0){
                    ans+=s[i];
                    mpp[s[i]]--;
                }
            }
        }

        return ans;
    }
};