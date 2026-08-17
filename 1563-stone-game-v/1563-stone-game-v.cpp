class Solution {
public:
    vector<int> prefix;
    vector<vector<int>> dp;

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++) 
            prefix[i + 1] = prefix[i] + stoneValue[i];

        dp.assign(n, vector<int>(n, -1));
        return solve(0, n - 1);
    }

    int rangeSum(int i, int j) {
        return prefix[j + 1] - prefix[i];
    }

    int solve(int i, int j) {
        if (i == j) return 0;               
        if (dp[i][j] != -1) return dp[i][j];

        int best = 0;
        for (int k = i; k < j; k++) {
            int leftSum  = rangeSum(i, k);
            int rightSum = rangeSum(k + 1, j);

            if (leftSum < rightSum) {
                best = max(best, leftSum + solve(i, k));
            } else if (leftSum > rightSum) {
                best = max(best, rightSum + solve(k + 1, j));
            } else {
                best = max(best, leftSum + max(solve(i, k), solve(k + 1, j)));
            }
        }
        return dp[i][j] = best;
    }
};