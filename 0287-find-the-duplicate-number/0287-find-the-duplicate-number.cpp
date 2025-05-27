class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }

        for (auto& [key, value] : mpp) {
            if (value > 1) {
                return key;
            }
        }

        return -1; 
    }
};
