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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;         //(node,vertical,level)
        q.push({root,{0,0}});
        
        while(!q.empty()){
            auto p=q.front();
            q.pop();

            TreeNode* node= p.first;
            int vertical=p.second.first, level=p.second.second;
            nodes[vertical][level].insert(node->val);
            if(node->left) q.push({node->left,{vertical-1,level+1}});
            if(node->right) q.push({node->right,{vertical+1,level+1}});
        }

        vector<vector<int>> ans;
        for(auto p: nodes){
            vector<int> col;
            for(auto r: p.second){
                col.insert(col.end(),r.second.begin(),r.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};