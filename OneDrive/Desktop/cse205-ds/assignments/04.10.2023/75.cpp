// Optimal: Dutch National FLag ALGO
// 0 to low-1 : 0
// low to mid-1 : 1
// mid to high-1 : unsorted array
// high to size-1: 2
// TC : O(N) & SC: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){

            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }

            else if(nums[mid]==1) mid++;

            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};