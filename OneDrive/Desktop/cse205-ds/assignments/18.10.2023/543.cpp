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
    int diameter(TreeNode* root, int &maxi){
        if(root==NULL) return 0;
        int left_half=diameter(root->left,maxi);
        int right_half=diameter(root->right,maxi);
        maxi=max(maxi,left_half+right_half);
        return 1+max(left_half,right_half);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        diameter(root,maxi);
        return maxi;
    }
};