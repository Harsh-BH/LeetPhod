class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        if(mpp[0]>1){
            for(int i=0;i<n;i++){
                ans.push_back(0);
            }
            return ans;
        }

        int p=1;
        bool contain_zero = false;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                contain_zero = true;
                continue;
            } 
            p*=nums[i];
        }  
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ans.push_back(p);
                continue;
            }
            if(contain_zero){
                ans.push_back(0);
            }else{
                ans.push_back(p/nums[i]);
            }
        } 




        return ans;
    }
};