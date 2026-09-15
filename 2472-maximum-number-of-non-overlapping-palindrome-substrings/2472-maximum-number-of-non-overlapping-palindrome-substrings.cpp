class Solution {
public:
    int maxPalindromes(string s, int k) {
        const int n = s.length();
        vector<vector<int>> all(n);
        for (int i = 0; i < n; ++i) {
            for (int x = i, y = i; x >= 0 && y < n && s[x] == s[y]; --x, ++y) {
                if (y - x + 1 >= k) {
                    all[y].push_back(x);
                }
            }
            for (int x = i - 1, y = i; x >= 0 && y < n && s[x] == s[y]; --x, ++y) {
                if (y - x + 1 >= k) {
                    all[y].push_back(x);
                }
            }
        }
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            for (int j : all[i - 1]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return dp[n];
        
        
    }
};