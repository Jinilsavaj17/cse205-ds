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
class BSTIterator{
    stack<TreeNode*> stk;
    //reverse->true->before
    //reverse->false->next
    bool reverse = true;
public:
    BSTIterator(TreeNode* root, bool reverse){
        this->reverse=reverse;
        pushAll(root);
    }

    bool hasNext(){
        return !stk.empty();
    }

    int next(){
        TreeNode* ans= stk.top();
        stk.pop();
        if(reverse) pushAll(ans->left);
        else pushAll(ans->right);
        return ans->val;
    }

private:
    void pushAll(TreeNode* node){
        while(node!=NULL){
            stk.push(node);
            if(reverse==true) node=node->right;
            else node=node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }

        return false;
    }
};