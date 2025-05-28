class Solution {
    int rec(int level, int prevIndex, vector<vector<int>>& dp, vector<int>& nums) {
        if (level == nums.size()) return 0;

        if (dp[level][prevIndex + 1] != -1) return dp[level][prevIndex + 1];

       
        int ans = rec(level + 1, prevIndex, dp, nums);

      
        if (prevIndex == -1 || nums[level] > nums[prevIndex]) {
            ans = max(ans, 1 + rec(level + 1, level, dp, nums));
        }

        return dp[level][prevIndex + 1] = ans;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[level][prevIndex + 1] because prevIndex can be -1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return rec(0, -1, dp, nums);
    }
};
