class Solution {
public:
    vector<vector<int>> dp;

    int rec(int i, int j, string &word1, string &word2) {
        // base case
        if (i == 0) return j;  // insert all j characters
        if (j == 0) return i;  // remove all i characters

        // cache check
        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i - 1] == word2[j - 1]) {
            return dp[i][j] = rec(i - 1, j - 1, word1, word2); // no operation needed
        }

        // compute all 3 options
        int insert_op = rec(i, j - 1, word1, word2);     // insert
        int remove_op = rec(i - 1, j, word1, word2);     // remove
        int replace_op = rec(i - 1, j - 1, word1, word2); // replace

        // take minimum of the three + 1 operation
        return dp[i][j] = 1 + min({insert_op, remove_op, replace_op});
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return rec(n, m, word1, word2);
    }
};
