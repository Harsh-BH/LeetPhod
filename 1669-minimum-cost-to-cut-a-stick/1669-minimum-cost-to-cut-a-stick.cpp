class Solution {
public:
    int dp[102][102];
    vector<int> cut;

    int rec(int i, int j) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 1e9;
        for (int mid = i; mid <= j; mid++) {
            int cost = cut[j + 1] - cut[i - 1];
            ans = min(ans, rec(i, mid - 1) + rec(mid + 1, j) + cost);
        }

        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cut.resize(m + 2);
        
        for (int i = 0; i < m; i++) {
            cut[i + 1] = cuts[i];
        }
        cut[0] = 0;
        cut[m + 1] = n;
        sort(cut.begin(), cut.end());

        memset(dp, -1, sizeof(dp));

        return rec(1, m);
    }
};
