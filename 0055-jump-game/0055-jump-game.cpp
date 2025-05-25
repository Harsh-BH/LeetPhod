class Solution {
public:
    bool rec(int level, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if (level >= n - 1) return true;

        if (dp[level] != -1) return dp[level];

        for (int jump = 1; jump <= nums[level]; ++jump) {
            if (rec(level + jump, nums, dp)) {
                return dp[level] = true; // cache and early return
            }
        }

        return dp[level] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return rec(0, nums, dp);  // Single call
    }
};
