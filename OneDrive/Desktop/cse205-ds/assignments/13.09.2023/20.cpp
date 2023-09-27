class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        char ch;
        for(int i=0;i<s.size();i++){
            ch=s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                stk.push(ch);
            }
            else{
                if(!stk.empty()){
                    if(stk.top()=='(' && ch==')' || stk.top()=='{' && ch=='}' || stk.top()=='[' && ch==']'){
                        stk.pop();
                    }
                    else return false;
                }
                else return false;
            }
        }
        if(stk.empty()) return true;
        return false;
    }
};