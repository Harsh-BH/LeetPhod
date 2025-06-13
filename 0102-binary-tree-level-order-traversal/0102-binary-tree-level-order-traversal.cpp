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

    void levelorder(TreeNode* root , vector<vector<int>> &result , int level)
    {
        if(root==nullptr){
            return ;
        }

        if (level == result.size()) {
            result.push_back({});
        }
        result[level].push_back(root->val);
        levelorder(root->left , result , level+1);
        levelorder(root->right , result , level+1);


    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelorder(root , result , 0);
        return result;
    }
};