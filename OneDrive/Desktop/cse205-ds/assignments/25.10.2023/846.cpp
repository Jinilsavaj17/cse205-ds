class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;

        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<hand.size();i++) q.push(hand[i]);

        vector<int> temp;
        while(!q.empty()){
            temp.push_back(q.top());
            q.pop();
        }

        
        for(int i=0;i<temp.size();i+=groupSize){
            int cnt=groupSize-1;
            int index=i;
            while(cnt--){
                if(temp[index]+1!=temp[index+1]) return false;
                index++;
            }
        }

        return true;
    }
};