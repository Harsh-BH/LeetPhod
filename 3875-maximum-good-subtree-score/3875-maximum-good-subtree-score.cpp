class Solution {
public:

    bool canpick(int num, int mask) {
        while (num > 0) {
            int rem = num % 10;
            if ((mask & (1 << rem))) return false;
            mask |= (1 << rem);
            num /= 10;
        }
        return true;
    }

    void dfs(int node, vector<int> &visited, vector<vector<int>> &adj, vector<int> &vals, vector<int> &subTreeNodes) {
        subTreeNodes.push_back(vals[node]);
        visited[node] = 1;
        for (auto v : adj[node]) {
            if (!visited[v]) {
                dfs(v, visited, adj, vals, subTreeNodes);
            }
        }
    }

    int getMaxSum(int level, int mask, vector<int> &subTreeNodes, vector<vector<int>> &dp) {
        if (level >= subTreeNodes.size()) {
            return 0;
        }

        if (dp[level][mask] != -1) {
            return dp[level][mask];
        }

        int notpick = getMaxSum(level + 1, mask, subTreeNodes, dp);
        int pick = 0;

        if (canpick(subTreeNodes[level], mask)) {
            int num = subTreeNodes[level];
            int new_mask = mask;
            while (num) {
                int rem = num % 10;
                new_mask |= (1 << rem);
                num /= 10;
            }
            pick = subTreeNodes[level] + getMaxSum(level + 1, new_mask, subTreeNodes, dp);
        }

        return dp[level][mask] = max(pick, notpick);
    }

    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        int mod = 1e9 + 7;
        int n = vals.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            if (par[i] != -1) {
                adj[par[i]].push_back(i);
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> visited(n, 0);
            vector<int> subTreeNodes;
            dfs(i, visited, adj, vals, subTreeNodes);

            vector<vector<int>> dp(subTreeNodes.size() + 1, vector<int>(1024, -1));
            ans = (ans + getMaxSum(0, 0, subTreeNodes, dp)) % mod;
        }

        return ans;
    }

};
