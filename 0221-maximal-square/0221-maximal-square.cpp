class Solution {
public:
    int rec(int i, int j, vector<vector<int>> &dp, vector<vector<char>> &matrix) {
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (matrix[i][j] == '0') return dp[i][j] = 0;

        if (i == 0 || j == 0) return dp[i][j] = 1;

        int up = rec(i - 1, j, dp, matrix);
        int left = rec(i, j - 1, dp, matrix);
        int diag = rec(i - 1, j - 1, dp, matrix);

        return dp[i][j] = 1 + min({up, left, diag});
    }

    int maximalSquare(vector<vector<char>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int max_side = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                max_side = max(max_side, rec(i, j, dp, matrix));
            }
        }

        return max_side * max_side;
    }
};
