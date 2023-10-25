class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> q;
        for(int i=0;i<nums.size();i++){
            q.push(-nums[i]);
            if(q.size()>2) q.pop();
        }
        int product=1;
        product*=q.top()+1;
        q.pop();
        product*=q.top()+1;
        return product;
    }
};