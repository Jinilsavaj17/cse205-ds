
class Solution {
public:

    void transpose(vector<vector<int>>& matrix){

        for(int row=0;row<matrix.size();row++){
            for(int col=0;col<row;col++){
                swap(matrix[row][col],matrix[col][row]);
            }
        }

    }

    void rotate(vector<vector<int>>& matrix) {

        transpose(matrix);

        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};