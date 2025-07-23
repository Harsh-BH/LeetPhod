class Solution {
public:
    int dp[310][310];
    vector<int> numsPadded;

    int rec(int l, int r) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        for (int i = l; i <= r; i++) {
            int cost = numsPadded[l - 1] * numsPadded[i] * numsPadded[r + 1];
            ans = max(ans, rec(l, i - 1) + rec(i + 1, r) + cost);
        }

        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        numsPadded.resize(n + 2);
        numsPadded[0] = numsPadded[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            numsPadded[i] = nums[i - 1];
        }

        memset(dp, -1, sizeof(dp));
        return rec(1, n);
    }
};
