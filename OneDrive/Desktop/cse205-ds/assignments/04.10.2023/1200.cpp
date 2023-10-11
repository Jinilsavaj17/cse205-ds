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
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        merge_sort(arr,0,arr.size()-1);
        vector<vector<int>> ans;
        int difference=INT_MAX;

        for(int i=0;i<arr.size()-1;i++){
            difference=min(difference,arr[i+1]-arr[i]);
        }

        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==difference){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};