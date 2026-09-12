class Solution {
    pair<long long, vector<int>> dfs(int i, int k, const vector<vector<int>>& v, const vector<int> &ind,
                                      vector<vector<long long>>& dp, vector<vector<vector<int>>> &s) {
        if (!s[i][k].empty()) return {dp[i][k], s[i][k]};
        if (i == 0) {
            dp[0][k] = v[ind[0]][2];
            s[0][k] = {ind[0]};
            return {dp[0][k], s[0][k]};
        }
        const auto& p = dfs(i - 1, k, v, ind, dp, s);
        dp[i][k] = p.first;
        s[i][k] = p.second;
        
        vector<int> mays = {ind[i]};
        long long mayw = v[ind[i]][2];
        if (k > 1) {
            int left = 0, right = i - 1;
            while (left <= right) {
                const int mid = (left + right) >> 1;
                if (v[ind[mid]][1] < v[ind[i]][0]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            const int j = left - 1;
            if (j >= 0) {
                const auto& p = dfs(j, k - 1, v, ind, dp, s);
                mays = p.second;
                mays.push_back(ind[i]);
                mayw += p.first;
            }
        }
        sort(mays.begin(), mays.end());
        if (dp[i][k] < mayw || (dp[i][k] == mayw && s[i][k] > mays)) {
            dp[i][k] = mayw;
            s[i][k] = mays;
        }
        return {dp[i][k], s[i][k]};
    }
    
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        vector<int> ind(n);
        for (int i = 0; i < n; ++i) {
            ind[i] = i;
        }
        sort(ind.begin(), ind.end(), [&](const int x, const int y) {
            return intervals[x][1] < intervals[y][1];
        });
        vector<vector<long long>> dp(n, vector<long long>(5));
        vector<vector<vector<int>>> s(n, vector<vector<int>>(5));
        return dfs(n - 1, 4, intervals, ind, dp, s).second;
    }
};
