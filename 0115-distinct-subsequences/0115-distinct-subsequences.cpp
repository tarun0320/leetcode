class Solution {
public:
    int numDistinct(string S, string T) {
       
        int m = S.length(), n = T.length();
        vector<vector<int> > dp;
        dp.resize(m + 1);
        for (int i = 0; i <= m; ++i) {
            dp[i].resize(n + 1, 0);
        }
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = 1;
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (S[i - 1] == T[j - 1]) {
                    
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= 1000000007;
                }
            }
        }
        return dp[m][n];
        
    }
};