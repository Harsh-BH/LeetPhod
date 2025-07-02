class Solution {
public:
    vector<int> dp;

    int rec(vector<int>& coins, int left) {
        if (left < 0) return INT_MAX;
        if (left == 0) return 0;
        if (dp[left] != -1) return dp[left];

        int ans = INT_MAX;
        for (int coin : coins) {
            int res = rec(coins, left - coin);
            if (res != INT_MAX) {
                ans = min(ans, 1 + res);
            }
        }

        return dp[left] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.assign(amount + 1, -1);
        int result = rec(coins, amount);
        return result == INT_MAX ? -1 : result;
    }
};
