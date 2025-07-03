class Solution {
public:
    vector<vector<int>> dp;
    vector<int> nums;

    int rec(int level, int target) {
        if (level == 0) {
            if (target == 0 && nums[0] == 0) return 2;
            if (target == 0 || nums[0] == target) return 1;
            return 0;
        }

        if (dp[level][target] != -1) return dp[level][target];

        int dont_take = rec(level - 1, target);
        int take = 0;
        if (target >= nums[level])
            take = rec(level - 1, target - nums[level]);

        return dp[level][target] = take + dont_take;
    }

    int findTargetSumWays(vector<int>& input_nums, int target) {
        nums = input_nums;
        int total = accumulate(nums.begin(), nums.end(), 0);
        if ((total - target) < 0 || (total - target) % 2 != 0) return 0;

        int subset_sum = (total - target) / 2;
        int n = nums.size();
        dp.assign(n, vector<int>(subset_sum + 1, -1));

        return rec(n - 1, subset_sum);
    }
};
