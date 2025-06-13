class Solution {
public:
    bool check(int mid, vector<int>& nums, int p) {
        int count = 0;
        for (int i = 1; i < nums.size(); ) {
            if (nums[i] - nums[i - 1] <= mid) {
                count++;
                i += 2;  
            } else {
                i += 1;  // try next pair
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());  // sort for greedy pairing

        int low = 0, high = nums.back() - nums.front();
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(mid, nums, p)) {
                ans = mid;     // try a smaller max diff
                high = mid - 1;
            } else {
                low = mid + 1; // need larger max diff
            }
        }

        return ans;
    }
};
