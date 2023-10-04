class Solution {
public:
    void cycle_sort(vector<int> &arr){
        int i=0;
        while(i<arr.size()){
            int check=arr[i];
            if(check<arr.size() && arr[i]!=arr[check]) swap(arr[i],arr[check]);
            else i++;
        }
    }
public:
    int missingNumber(vector<int>& nums) {
        cycle_sort(nums);
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i) return i;
        }
        return nums.size();
    }
};

// // cycle sort
// public:
//     void cycle_sort(vector<int> &arr){
//         int i=0;
//         while(i<arr.size()){
//             int check=arr[i]-1;
//             if(arr[i]!=arr[check]) swap(arr[i],arr[check]);
//             else i++;
//         }
//     }