class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> stk;
        int sum1=0;
        for(int i=0;i<operations.size();i++){
            
            if(operations[i]=="+" && !stk.empty()){
                int temp=stoi(stk.top());
                stk.pop();
                int sum=temp+stoi(stk.top());
                stk.push(to_string(temp));
                stk.push(to_string(sum));
            }

            else if(operations[i]=="D" && !stk.empty()){
                int d= stoi(stk.top())*2;
                stk.push(to_string(d));
            }

            else if(operations[i]=="C" && !stk.empty()){
                stk.pop();
            }

            else stk.push(operations[i]);
        }
        
        while(!stk.empty()){
            sum1+=stoi(stk.top());
            stk.pop();
        }
        return sum1;
    }
};