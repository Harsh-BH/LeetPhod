#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rec(int level, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if (level >= n - 1) return 0; // Already at or past end

        if (dp[level] != -1) return dp[level];

        int ans = 1e9;
        for (int jump = 1; jump <= nums[level]; ++jump) {
            ans = min(ans, 1 + rec(level + jump, nums, dp));
        }

        return dp[level] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return rec(0, nums, dp);
    }
};

