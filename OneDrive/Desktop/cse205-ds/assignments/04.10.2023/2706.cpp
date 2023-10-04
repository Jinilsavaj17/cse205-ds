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
    int buyChoco(vector<int>& prices, int money) {
        merge_sort(prices,0,prices.size()-1);
        if(prices[0]+prices[1]>money) return money;
        return money-(prices[0]+prices[1]);
    }
};