class Solution {
public:
    bool check(int len, int target, const vector<int>& prefix) {
        for (int i = len; i < prefix.size(); i++) {
            if (prefix[i] - prefix[i - len] >= target) {
                return true;
            }
        }
        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        int low = 1, high = n, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, target, prefix)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
