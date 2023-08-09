class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums,ans,temp,0,nums.size());

        return ans;
    }

    void solve(vector<int> &v, vector<vector<int>> &ans, vector<int>& temp, int i, int n)
    {
        if(i>= n)
        {
            ans.push_back(temp);
            return;
        }

        solve(v,ans,temp,i+1,n);

        temp.push_back(v[i]);
        solve(v,ans,temp,i+1,n);
        temp.pop_back();
    }

};