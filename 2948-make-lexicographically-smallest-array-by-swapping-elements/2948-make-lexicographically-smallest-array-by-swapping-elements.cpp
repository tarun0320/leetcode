class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        const multiset<int> s(nums.begin(), nums.end());
        unordered_map<int, int> all;
        vector<list<int>> g;
        for (auto t = s.begin(); t != s.end();) {
            const int ind = g.size();
            all[*t] = ind;
            g.push_back({*t});
            for (++t; t != s.end() && *t - *prev(t) <= limit; ++t) {
                g[ind].push_back(*t);
                all[*t] = ind;
            }
        }
        for (int& x : nums) {
            x = g[all[x]].front();
            g[all[x]].pop_front();
        }
        return nums;
    }
};