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
    TreeNode* minValue(TreeNode *root){
        while(root->left!=NULL) root=root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val==key){
            //0 child
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            //1 child
            if(root->left!=NULL && root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            else if(root->left==NULL && root->right!=NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            //2 child
            if(root->left!=NULL && root->right!=NULL){
                int mini = minValue(root->right)->val;
                root->val=mini;
                root->right=deleteNode(root->right,mini);
            }
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        } 
        else{
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
};