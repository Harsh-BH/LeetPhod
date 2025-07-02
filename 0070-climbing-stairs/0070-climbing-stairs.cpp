class Solution {
public:
    int dp[45];
    
    int rec(int level, int n) {
        if (level > n) return 0;
        if (level == n) return 1;
        if (dp[level] != -1) return dp[level];

        return dp[level] = rec(level + 1, n) + rec(level + 2, n);
    }

    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return rec(0, n);
    }
};
