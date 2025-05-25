class Solution {
public:
 int rec(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (i >= m || j >= n) return 0; // Out of bounds

        if (i == m - 1 && j == n - 1) return 1; // Reached destination

        if (dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(obstacleGrid[i][j]==0){
            ans = rec(i + 1, j, obstacleGrid, dp) + rec(i, j + 1, obstacleGrid, dp);
        }

        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

          int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1){
            return 0;
        }
         vector<vector<int>> dp(m, vector<int>(n, -1));
        return rec(0, 0, obstacleGrid, dp);
    }
};