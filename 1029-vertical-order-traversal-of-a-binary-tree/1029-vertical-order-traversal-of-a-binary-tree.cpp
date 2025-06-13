class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; // col -> row -> sorted vals
        queue<tuple<TreeNode*, int, int>> q; // node, col, row
        q.push({root, 0, 0});
        
        while (!q.empty()) {
            auto [node, x, y] = q.front(); q.pop();
            nodes[x][y].insert(node->val);

            if (node->left) q.push({node->left, x - 1, y + 1});
            if (node->right) q.push({node->right, x + 1, y + 1});
        }

        vector<vector<int>> result;
        for (auto &[col, rowmap] : nodes) {
            vector<int> colNodes;
            for (auto &[row, vals] : rowmap) {
                colNodes.insert(colNodes.end(), vals.begin(), vals.end());
            }
            result.push_back(colNodes);
        }

        return result;
    }
};
