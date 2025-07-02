class Solution {
public:
    int dp[10001];

    bool rec(int level, vector<int> &nums) {
        int n = nums.size();
        if (level >= n - 1) return true;

        if (dp[level] != -1) return dp[level];

        for (int jump = 1; jump <= nums[level]; ++jump) {
            if (rec(level + jump, nums)) {
                return dp[level] = true;
            }
        }

        return dp[level] = false;
    }

    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return rec(0, nums);
    }
};
