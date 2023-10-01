class MyQueue {
    stack<int> input;
    stack<int> output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int temp;
        if(!output.empty()){
            temp=output.top();
            output.pop();
        } 
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            temp=output.top();
            output.pop();
        }        
        return temp;
    }
    
    int peek() {
        if(!output.empty()) return output.top();
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }  
    }
    
    bool empty() {
        if(!output.empty() || !input.empty()) return false;
        return true;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */