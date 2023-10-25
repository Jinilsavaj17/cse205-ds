class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        priority_queue<pair<int,int>> q;

        for(int i=0;i<n;i++) q.push({score[i],i});
        
        for(int i=0;i<n;i++){
            auto it = q.top();
            int value=it.first;
            int index=it.second;
            q.pop();

            if(i==0) ans[index]="Gold Medal";
            else if(i==1) ans[index]="Silver Medal";
            else if(i==2) ans[index]="Bronze Medal";
            else ans[index]=to_string(i+1);
        }

        return ans;
    }
};