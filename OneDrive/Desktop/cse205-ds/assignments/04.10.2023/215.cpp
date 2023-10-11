class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;  //min heap
        for(int i=0;i<k;i++) q.push(-nums[i]);
        for(int i=k;i<nums.size();i++){
            if(q.top()>(-nums[i])){
                q.pop();
                q.push(-nums[i]);
            }
        }
        return -q.top();
    }
};


//with sorting
// int temp=nums.size()-k;
// sort(nums.begin(),nums.end());
// return nums[temp];