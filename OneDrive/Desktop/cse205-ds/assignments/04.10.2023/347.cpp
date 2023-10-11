class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q; //min heap
        unordered_map<int,int> mpp;
        vector<int> ans;

        for(int i=0;i<nums.size();i++) mpp[nums[i]]++;

        for(auto it:mpp){
            q.push({-it.second,it.first});
            if(q.size()>k) q.pop();
        }

        while(k--){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};