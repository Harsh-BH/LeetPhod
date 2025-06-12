class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;

        int leftmax = 0;
        int rightmax  = 0;
        int total = 0;

        while(left<right){
            if(height[left]<height[right]){
                (height[left]>=leftmax)?leftmax = height[left] : total+= leftmax - height[left];
                left++;
            }else{
                (height[right]>=rightmax)? rightmax = height[right]: total+= rightmax - height[right];
                right--;

            }
        }

        return total;
    }
};