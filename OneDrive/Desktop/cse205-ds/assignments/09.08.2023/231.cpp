class Solution {
public:
    bool isPowerOfTwo(int n) {
        return solve(n);
    }
    bool solve(int &n){
        if(n==0) return false;
        if(n%2==0){
            n=n/2;
            solve(n);
        }
        if(n==1) return true;
        return false;
    }
};