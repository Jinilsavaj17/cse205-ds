class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int temp=0;
        int sum=0;
        int sum1=0;
        for(int i=0;i<nums.size();i++){
            sum1+=i;
            if(i<nums.size()-1 && nums[i]==nums[i+1]){
                temp=nums[i];
            }
            sum+=nums[i];
        }

        sum-=temp;
        sum1+=nums.size();
        cout<<sum1<<" "<<sum;
        sum1-=sum;

        ans.push_back(temp);
        ans.push_back(sum1);
        return ans;
    }
};