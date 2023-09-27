class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*') stk.push(s[i]);
            else stk.pop();
        }
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};