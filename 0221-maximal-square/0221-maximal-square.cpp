class Solution {
public:
    int rec(int i, int j, vector<vector<char>>& matrix, vector<vector<int>>& dp, int& maxSquare) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (i >= m || j >= n) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int down = rec(i + 1, j, matrix, dp, maxSquare);
        int right = rec(i, j + 1, matrix, dp, maxSquare);
        int diag = rec(i + 1, j + 1, matrix, dp, maxSquare);

        int ans =0;

        if (matrix[i][j] == '1') {
            ans = 1 + min({down, right, diag});
            maxSquare = max(maxSquare,ans);
        } 

        return dp[i][j]=ans;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int maxSquare = 0;

        rec(0, 0, matrix, dp, maxSquare);

        return maxSquare * maxSquare;
    }
};
