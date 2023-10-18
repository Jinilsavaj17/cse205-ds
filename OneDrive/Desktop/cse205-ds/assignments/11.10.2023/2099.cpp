class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        vector<int> temp=nums;
        vector<int> ans;
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<k;i++) mpp[nums[i]]++;
        for(int i=0;i<temp.size();i++){
            if(mpp[temp[i]]!=0){
                ans.push_back(temp[i]);
                mpp[temp[i]]--;
            }
        }
        return ans;
    }
};