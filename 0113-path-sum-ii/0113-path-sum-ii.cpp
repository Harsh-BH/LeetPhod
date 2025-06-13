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
    void path(TreeNode* root , int targetsum , vector<vector<int>> &result , vector<int> &currpath){
        if(root==nullptr){
            return ;
        }

        currpath.push_back(root->val);
        if(root->left==nullptr and root->right==nullptr and root->val==targetsum){
           result.push_back(currpath);
        }
        path(root->left , targetsum - root->val , result , currpath);

        path(root->right , targetsum - root->val , result , currpath);

        currpath.pop_back();
         
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currpath;
        path(root , targetSum , result ,currpath );

        return result;
        
    }
};