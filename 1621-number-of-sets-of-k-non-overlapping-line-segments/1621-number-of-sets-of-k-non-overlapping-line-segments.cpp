class Solution {
    const int M = 1000000007;
    
    void add(int &x, int y) {
        if ((x += y) >= M) x -= M;
    }
    
public:
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1));
        dp[0] = vector<int>(n + 1, 1);
        for (int j = 1; j <= k; ++j) {
            for (int i = j + 1, s = 1; i <= n; ++i) {
                dp[j][i] = dp[j][i - 1];
                add(dp[j][i], s);
                add(s, dp[j - 1][i]);
            }
        }
        return dp[k][n];
        
    }
};