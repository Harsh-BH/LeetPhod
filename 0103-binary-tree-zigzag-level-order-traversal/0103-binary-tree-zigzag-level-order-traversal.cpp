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
    void zigzag(TreeNode* root , vector<vector<int>> &result , int level){
        if(root==nullptr){
            return;
        }

        if(level==result.size()){
            result.push_back({});
        }
        if(level%2==0){
        result[level].push_back(root->val);

        }else{
            result[level].insert(result[level].begin(),root->val);
        }
            zigzag(root->left , result , level+1);
         zigzag(root->right , result , level+1);
        
        
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        zigzag(root, result ,0);
        return result;
    }
};