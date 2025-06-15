class Solution {
public:

    int rec(int i , int j ,vector<vector<int>>& grid ,vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();

        if(i>=n || j>=m) return 1e9;

        if(i==n-1 and j==m-1){
            return grid[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int right = rec(i , j+1 , grid ,dp);
        int down = rec(i+1 , j , grid ,dp); 

        return dp[i][j] = grid[i][j] + min(right, down);


    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp;
        int n = grid.size();
        int m = grid[0].size();

        dp.assign(n+1,vector<int>(m+1,-1));

        return rec(0,0, grid ,dp);
    }
};