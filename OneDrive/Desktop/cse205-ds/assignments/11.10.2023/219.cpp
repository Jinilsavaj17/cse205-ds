class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            if(mpp.find(nums[i]) != mpp.end() && abs(mpp[nums[i]]-i) <= k)    return true;
            mpp[nums[i]] = i;
        }
        return false;
    }
};



//mpp.find(nums[i]): This part of the condition attempts to find the element nums[i] in the unordered map mpp. The find function searches for a key in the map and returns an iterator pointing to the found element if it exists, or an iterator pointing to the end of the map if the key is not found.

//mpp.end(): The mpp.end() is an iterator pointing to the position just after the last element in the map. It represents the end of the map.