class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> r(k);
        vector<int> dp(k);
        for (int x : nums) {
            x %= k;
            vector<int> temp(k);
            temp[x] = 1;
            for (int i = 0; i < k; ++i) {
                temp[i * x % k] += dp[i];
            }
            for (int i = 0; i < k; ++i) {
                dp[i] = temp[i];
                r[i] += dp[i];
            }
        }
        return r;
    }
};