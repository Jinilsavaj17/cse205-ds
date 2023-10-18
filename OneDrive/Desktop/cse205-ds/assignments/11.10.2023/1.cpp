class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int remain=target-nums[i];
            //if(mpp.find(remain)!=mpp.end()) return {mpp[remain],i};
            if(mpp.count(remain)) return {mpp[remain],i}; //better option
            mpp[nums[i]]=i;
        }
        return {};  //no soln
    }
};

//map.count() is a better choice when you only need to know if an element with a specific key exists in the map. 
//map.find() is a better choice when you need to access the element with a specific key.