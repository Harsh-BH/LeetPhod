class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        for(int i=1;i<n;i++){
            arr.push_back(abs(nums[i]-nums[i-1]));
        }   
        arr.push_back(abs(nums[n-1]-nums[0]));

        int ans = *max_element(arr.begin(),arr.end());

        return ans;
    }
};