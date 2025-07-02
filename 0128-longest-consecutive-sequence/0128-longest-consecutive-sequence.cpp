class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int curr_count = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] == nums[i - 1] + 1) {
                curr_count++;
            } else {
                longest = max(longest, curr_count);
                curr_count = 1;
            }
        }

        longest = max(longest, curr_count);
        return longest;
    }
};
