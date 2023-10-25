class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;  //min heap
        for(int i=0;i<nums.size();i++){
            q.push(-nums[i]);
            if(q.size()>k) q.pop();
        }
        return -q.top();
    }
};


//with sorting
// int temp=nums.size()-k;
// sort(nums.begin(),nums.end());
// return nums[temp];