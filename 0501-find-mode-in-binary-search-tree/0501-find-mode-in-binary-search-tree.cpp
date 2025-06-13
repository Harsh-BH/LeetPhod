class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        inorder(root, result);

        unordered_map<int, int> freq;
        int maxFreq = 0;

        for (int val : result) {
            freq[val]++;
            maxFreq = max(maxFreq, freq[val]);
        }

        vector<int> modes;
        for (auto& [val, cnt] : freq) {
            if (cnt == maxFreq) {
                modes.push_back(val);
            }
        }

        return modes;
    }
};
