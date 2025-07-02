const int inf = 1e9;
class Solution {
public:
    vector<vector<int>> arr;
    int dp[205][205];

    int rec(int level ,int i){
        int n = arr.size();
        if(level==n-1){
            return arr[level][i];
        }

        if(dp[level][i]!=-1){
            return dp[level][i];
        }
        int ans = inf;
        int down = rec(level+1 , i);
        int diagonal = rec(level+1 , i+1);

        return dp[level][i] = arr[level][i] + min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        arr = triangle;
        memset(dp,-1,sizeof(dp));
        return rec(0,0);
    }
};