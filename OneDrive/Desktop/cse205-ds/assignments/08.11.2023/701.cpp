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

 //Iterative Soln
// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int x) {
//         if(root==NULL){
//             TreeNode* node = new TreeNode(x);
//             return node;
//         }

//         TreeNode* temp=root;
//         while(root->left!=NULL || root->right!=NULL){
//             if(root->val > x){
//                 if(root->left!=NULL) root=root->left;
//                 else break;
//             }
//             else{
//                 if(root->right!=NULL) root=root->right;
//                 else break;
//             }
//         }
//         TreeNode* node = new TreeNode(x);
//         if(root->val > x) root->left=node;
//         else root->right=node;
        
//         return temp;
//     }
// };

//Recursive Soln
class Solution{
    public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root == NULL){
            TreeNode* temp = new TreeNode(val);
            return  temp;
        }

        if(root -> val > val)   root -> left = insertIntoBST(root -> left, val);
        else    root -> right = insertIntoBST(root -> right, val);

        return root;
    }
};