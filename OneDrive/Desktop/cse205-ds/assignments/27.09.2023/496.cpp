class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> mpp;
        stack<int> stk;
        int n=nums2.size();

        for(int i=n-1;i>=0;i--){
            int ele=nums2[i];
            while(!stk.empty() && stk.top() < ele) stk.pop();
            int res=stk.empty() ? -1:stk.top();
            mpp.insert({ele,res});
            stk.push(ele);
        }

        vector<int> ans;
        for(auto it:nums1) ans.push_back(mpp[it]);
        return ans;
    }
};