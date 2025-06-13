class Solution {
public:
    bool isBST(TreeNode* root , long minvalue , long maxvalue){
        if (!root) return true;

        if (root->val <= minvalue || root->val >= maxvalue) {
            return false;
        }

        return isBST(root->left, minvalue, root->val) &&
               isBST(root->right, root->val, maxvalue);
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};
