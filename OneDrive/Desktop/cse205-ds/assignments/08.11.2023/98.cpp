/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool solve(TreeNode* root,long long int min_val ,long long int max_val){
        if(root == NULL)    return true;
        bool chk = true;

        if(root -> val > min_val && root -> val < max_val){
            //left call
            bool left = solve(root -> left, min_val,root->val);
            //right call
            bool right = solve(root -> right, root -> val, max_val);

            chk = left && right;
        }
        else    chk = false;
     return chk;   
    }

    bool isValidBST(TreeNode* root) 
    {
        if(root == NULL || (root -> left == NULL && root -> right == NULL))
            return true;

        long long int lb = -2147483649;
        long long int ub = 2147483648;
        return solve(root,lb,ub);
    }
};