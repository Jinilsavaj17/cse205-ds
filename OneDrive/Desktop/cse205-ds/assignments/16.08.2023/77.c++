class Solution {
public:
   
        vector<vector<int>> a;
        void comb(int x,int k,vector<int>&b,int n)
        {
            if(b.size()==k)
            {
                a.push_back(b);
                return;
            }
            for(int i=x;i<n+1;i++)
            {
                b.push_back(i);
                comb(i+1,k,b,n);
                b.pop_back();
            }
        }
        vector<vector<int>> combine(int n,int k)
        {
            vector<int> b;
            comb(1,k,b,n);
            return a;
        }
};