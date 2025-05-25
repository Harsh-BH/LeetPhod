class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        if (i >= m || j >= n) return 1e9;  // out of bounds
        if (i == m - 1 && j == n - 1) return grid[i][j];  // base case: destination cell

        if (dp[i][j] != -1) return dp[i][j];

        int down = rec(i + 1, j, grid, dp);
        int right = rec(i, j + 1, grid, dp);

        return dp[i][j] = grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return rec(0, 0, grid, dp);
    }
};
