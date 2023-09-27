class MinStack {
public:
    vector<pair<int,int>> minstack;

    MinStack() {
        
    }
    
    void push(int val) {
        if(minstack.empty()) minstack.push_back({val,val});
        else minstack.push_back({val,min(minstack.back().second,val)});
    }
    
    void pop() {
        minstack.pop_back();
    }
    
    int top() {
        if(minstack.size()==0) return NULL;
        else return minstack.back().first;
    }
    
    int getMin() {
        return minstack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */