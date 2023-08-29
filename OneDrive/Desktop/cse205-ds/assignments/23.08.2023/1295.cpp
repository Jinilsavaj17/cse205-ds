class Solution {
private:
    int solve(int n){
        int cnt=0;
        while(n!=0){
            n=n/10;
            cnt++;
        }
        return cnt;
    }
public:
    int findNumbers(vector<int>& nums) {
        int even=0;
        for(int i=0;i<nums.size();i++){
            if(solve(nums[i])%2==0) even++;
        }
        return even;
    }
};