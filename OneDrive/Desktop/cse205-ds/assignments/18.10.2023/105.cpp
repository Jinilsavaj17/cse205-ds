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
    TreeNode* build(vector<int> &preorder, int pre_start, int pre_end, vector<int> &inorder, int in_start, int in_end, map<int,int> &inMap){
        if(pre_start>pre_end || in_start>in_end) return NULL;

        TreeNode* root= new TreeNode(preorder[pre_start]);

        int in_root=inMap[root->val];
        int numsLeft = in_root - in_start;

        root->left = build(preorder,pre_start+1,pre_start+numsLeft,inorder,in_start,in_root-1,inMap);
        root->right = build(preorder,pre_start+numsLeft+1,pre_end,inorder,in_root+1,in_end,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++) inMap[inorder[i]]=i;
        TreeNode* root= build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }
};