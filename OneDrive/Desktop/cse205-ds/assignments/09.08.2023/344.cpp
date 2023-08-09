class Solution {
public:
    void reverseString(vector<char>& s) {
        rev(s,0);
    }
    void rev(vector<char>& s,int i){
        int n=s.size();
        if(i>=n/2) return;
        swap(s[i],s[n-i-1]);
        rev(s,i+1);
        }
};
