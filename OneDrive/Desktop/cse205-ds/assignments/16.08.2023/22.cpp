class Solution {
private: 
    void parenthesis(int open, int close, int n, string str, vector<string> &ans){
        if(str.length()==2*n){
            ans.push_back(str);
        }
        else{
            if(open<n){
                parenthesis(open+1,close,n,str+'(',ans);
            }
            if(close<open){
                parenthesis(open,close+1,n,str+')',ans);
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        parenthesis(0,0,n,"",ans);
        return ans;
    }
};