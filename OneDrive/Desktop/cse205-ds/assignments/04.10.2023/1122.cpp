class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        vector<int> ans1;
        unordered_map<int,int> mpp;
        for(int i=0;i<arr1.size();i++){
            mpp[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++){
            if(mpp[arr2[i]]>=1){
                while(mpp[arr2[i]]!=0){
                    ans.push_back(arr2[i]);
                    mpp[arr2[i]]--;
                }
            }
        }
        for(int i=0;i<arr1.size();i++){
            if(mpp[arr1[i]]>0) ans1.push_back(arr1[i]);
        }
        sort(ans1.begin(),ans1.end());

        for(int i=0;i<ans1.size();i++){
            ans.push_back(ans1[i]);
        }
        return ans;
    }
};