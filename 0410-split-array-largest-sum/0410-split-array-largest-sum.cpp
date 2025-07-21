class Solution {
public:

    bool check(int mid , vector<int> &arr , int k){
        int need = 1;
        int sum = 0;
        for(int v:arr){
            if((sum + v >mid)){
                need++;
                sum = v;
            }else{
                sum+=v;
            }
        }

        return need<=k;
    }
    int splitArray(vector<int>& nums, int k) {
       int low = *max_element(nums.begin(),nums.end());
       int high = accumulate(nums.begin(),nums.end(),0);
        int ans = 0;
       while(low<=high){
        int mid = low + (high-low)/2;
        if(check(mid , nums , k)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
       }

       return ans;
    }
};