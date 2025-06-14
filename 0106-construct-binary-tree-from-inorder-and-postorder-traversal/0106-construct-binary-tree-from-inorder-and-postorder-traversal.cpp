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

TreeNode* build(int inStart, int inEnd, int postStart, int postEnd,
                vector<int>& inorder, vector<int>& postorder,
                unordered_map<int, int>& mpp) {
    if (inStart > inEnd || postStart > postEnd) return nullptr;

    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);

    int inRootIndex = mpp[rootVal];
    int leftSize = inRootIndex - inStart;

    root->left = build(inStart, inRootIndex - 1,
                           postStart, postStart + leftSize - 1,
                           inorder, postorder, mpp);

    root->right = build(inRootIndex + 1, inEnd,
                            postStart + leftSize, postEnd - 1,
                            inorder, postorder, mpp);

    return root;
}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         unordered_map<int, int> mpp;
    for (int i = 0; i < inorder.size(); ++i) {
        mpp[inorder[i]] = i;
    }
    return build(0, inorder.size() - 1,
                     0, postorder.size() - 1,
                     inorder, postorder, mpp);
    }
};