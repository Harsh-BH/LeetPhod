class Solution {
public:
    vector<int> arr;
    int dp[201][10001]; // total/2 can go up to 10000 for constraints

    int rec(int i, int left) {
        if (left == 0) return 1; // found a subset
        if (i == arr.size()) return 0;
        if (dp[i][left] != -1) return dp[i][left];

        int take = 0;
        if (left - arr[i] >= 0)
            take = rec(i + 1, left - arr[i]);
        int dont_take = rec(i + 1, left);

        return dp[i][left] = take || dont_take; // return true if any works
    }

    bool canPartition(vector<int>& nums) {
        arr = nums;
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false; // odd sum can't be divided equally

        memset(dp, -1, sizeof(dp));
        return rec(0, total / 2);
    }
};
