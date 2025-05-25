#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> dp;

    int palindrome(int l, int r, const string &s) {
        if (l >= r) return 1;

        if (dp[l][r] != -1) return dp[l][r];

        if (s[l] == s[r] && palindrome(l + 1, r - 1, s)) {
            return dp[l][r] = 1;
        }

        return dp[l][r] = 0;
    }

public:
    string longestPalindrome(string s) {
        int n = s.length();
        dp.assign(n, vector<int>(n, -1));

        int maxlen = 0;
        string ans;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (palindrome(i, j, s)) {
                    int len = j - i + 1;
                    if (len > maxlen) {
                        maxlen = len;
                        ans = s.substr(i, len);
                    }
                }
            }
        }

        return ans;
    }
};
