class Solution {
public:
    int rec(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        if (i == 0) return j;
        if (j == 0) return i;

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i - 1] == word2[j - 1]) {
            return dp[i][j] = rec(i - 1, j - 1, word1, word2, dp);
        }

        int insertOp = rec(i, j - 1, word1, word2, dp);
        int deleteOp = rec(i - 1, j, word1, word2, dp);
        int replaceOp = rec(i - 1, j - 1, word1, word2, dp);

        return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return rec(m, n, word1, word2, dp);
    }
};
