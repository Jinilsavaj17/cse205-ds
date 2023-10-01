class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        vector<int> result(n, -1); 

        for (int i = 0; i < 2 * n; i++) {
            while (!stk.empty() && nums[i % n] > nums[stk.top()]) {
                result[stk.top()] = nums[i % n];
                stk.pop();
            }

            if (i < n) {
                stk.push(i);
            }
        }
        return result;
    }
};
