class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> transpose(matrix[0].size(),vector<int> (matrix.size()));
        for(int row=0;row<matrix.size();row++){
            for(int col=0;col<matrix[row].size();col++){
                transpose[col][row]=matrix[row][col];
            }
        }
        return transpose;
    }
};