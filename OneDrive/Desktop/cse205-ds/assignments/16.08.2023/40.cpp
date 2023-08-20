class Solution {
private:
    void combination(int ind, int target, vector<int> arr, vector<int> output, vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(output);
            return;
        }

        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            output.push_back(arr[i]);
            combination(i+1,target-arr[i],arr,output,ans);
            output.pop_back();
        }
    }




public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int> output;
        combination(0,target,candidates,output,ans);
        return ans;
    }
};