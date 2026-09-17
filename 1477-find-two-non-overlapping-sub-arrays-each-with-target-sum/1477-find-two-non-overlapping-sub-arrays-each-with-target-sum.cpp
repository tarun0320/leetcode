class Solution {
    void better(int &x, int y) {
        if (x < 0 || x > y) x = y;
    }
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        const int n = arr.size();
        unordered_map<int, int> have;
        vector<int> dp(n + 1);
        have[0] = 0;
        dp[0] = -1;
        int r = - 1;
        for (int i = 1, s = 0; i <= n; ++i) {
            s += arr[i - 1];
            const auto t = have.find(s - target);
            dp[i] = dp[i - 1];
            if (t != have.end()) {
                const int len = i - t->second;
                better(dp[i], len);
                if (dp[t->second] >= 0) better(r, dp[t->second] + len);
            }
            have[s] = i;
        }
        return r;
    }
};