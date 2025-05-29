class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>sortednums = nums;
        sort(sortednums.begin(),sortednums.end());
        int minval = sortednums[0];

        bool match = false;
        int n = nums.size();
        for(int i=0;i<n;i++){
            match = true;
            for(int j=0;j<n;j++){
                if(nums[(i+j)%nums.size()]!=sortednums[j]){
                    match = false;
                    break;
                }
            }
             if(match) return true;
        }

        return false;
    }
};