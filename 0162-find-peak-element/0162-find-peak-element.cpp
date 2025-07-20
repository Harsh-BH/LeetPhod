class Solution {
public:
    bool check(int peak, vector<int> &nums) {
        int n = nums.size();
        bool leftOK = (peak == 0) || (nums[peak - 1] <= nums[peak]);
        bool rightOK = (peak == n - 1) || (nums[peak + 1] <= nums[peak]);
        return leftOK && rightOK;
    }

    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid, nums)) {
                return mid;
            }

            // If the next element is greater, peak must be in the right half
            if (mid + 1 < nums.size() && nums[mid + 1] > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1; // Should never reach here if input is valid
    }
};
