class Solution {
public:
    int largestInteger(int num) {
    
        priority_queue<int> even,odd;
        vector<int> arr;
        
        while(num!=0){
            int x=num%10;
            arr.push_back(x);
            num/=10;
        }
        reverse(arr.begin(),arr.end());

        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0) even.push(arr[i]);
            else odd.push(arr[i]);
        }

        // here num is 0
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0){
                num = num*10 + even.top();
                even.pop();
            }
            else{
                num = num*10 + odd.top();
                odd.pop();
            }
        }
        return num;
    }
};