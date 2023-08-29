class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=1,j=0,cnt=0;

            while(cnt!=k){
                if(j==arr.size()){
                    i++;
                    cnt++;
                }
                else{
                    if(i==arr[j]){
                        i++;
                        j++; 
                    } 
                    else{
                        i++;
                        cnt++;
                    } 
                }
            }

            return i-1;   
    }
};