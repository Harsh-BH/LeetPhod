class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> ans(n-k+1, vector<int> (m-k+1,0));

        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                int val = INT_MAX;
                vector<int> temp;

                for(int a=i;a<i+k;a++){
                    for(int b=j;b<j+k;b++){
                        temp.push_back(grid[a][b]);
                    }
                }
                if(temp.size()<2) continue;
                
                sort(temp.begin(),temp.end());
                for(int a=1;a<temp.size();a++){
                    if(abs(temp[a]-temp[a-1]) == 0){
                        continue;
                    }
                    val = min(val, abs(temp[a]-temp[a-1]));
                }

                if(val!=INT_MAX){
                    ans[i][j] = val;
                }
            }
        }

        return ans;
    }
};