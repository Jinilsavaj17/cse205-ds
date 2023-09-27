class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi=0;
        for(int row=0;row<accounts.size();row++){
            int sum=0;
            for(int col=0;col<accounts[row].size();col++){
                sum+=accounts[row][col];
            }
            maxi=max(sum,maxi);
            sum=0;
        }
        return maxi;
    }
};