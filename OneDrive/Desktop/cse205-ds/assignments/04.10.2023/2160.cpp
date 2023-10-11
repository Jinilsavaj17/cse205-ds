class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high){
        vector<int> temp;
        int left=low;
        int right=mid+1;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }

        for(int i=low;i<=high;i++)  arr[i]=temp[i-low];

    }
    void merge_sort(vector<int> &arr, int low, int high){
        if(low>=high) return;
        int mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }


public:
    int minimumSum(int num) {
        vector<int> nums;
        while(num!=0){
            int i=num%10;
            nums.push_back(i);
            num/=10;
        }
        merge_sort(nums,0,nums.size()-1);
        int ans= (nums[0]*10+nums[2])+(nums[1]*10+nums[3]);
        return ans;
    }
};