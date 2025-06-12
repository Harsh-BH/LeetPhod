class Solution {
public:
    // Helper function to precompute leftMax and rightMax arrays
    void f(vector<int> &height, vector<int> &leftMax, vector<int> &rightMax){
        int n = height.size();
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];

        for(int i = 1; i < n - 1; i++){
            // Max height seen so far from left
            leftMax[i] = max(height[i], leftMax[i - 1]);

            // Max height seen so far from right (fill in reverse)
            rightMax[n - i - 1] = max(rightMax[n - i], height[n - i - 1]);
        }
    }

    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftMax(n, 0);   // To store max to the left of each bar
        vector<int> rightMax(n, 0);  // To store max to the right of each bar

        // Precompute leftMax and rightMax
        f(height, leftMax, rightMax);

        int total = 0;
        for(int i = 0; i < n; i++){
            // Only trap water if there's taller wall on both sides
            if(leftMax[i] > height[i] && rightMax[i] > height[i]){
                total += min(leftMax[i], rightMax[i]) - height[i];
            }   
        }
        return total;
    }
};
