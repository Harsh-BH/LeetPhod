class Solution {
public:
    int rec(int i, int j, const string& text1, const string& text2, vector<vector<int>>& dp) {
        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = 0;
        if (text1[i] == text2[j]) {
            ans = 1 + rec(i + 1, j + 1, text1, text2, dp);
        } else {
            ans = max(rec(i, j + 1, text1, text2, dp), rec(i + 1, j, text1, text2, dp));
        }
        
        return dp[i][j] = ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return rec(0, 0, text1, text2, dp);
    }
};
