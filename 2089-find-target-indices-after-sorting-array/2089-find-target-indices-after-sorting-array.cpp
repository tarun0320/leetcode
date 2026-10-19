class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int ind = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
        const int n = nums.size();
        vector<int> r;
        for (int i = ind; i < n && nums[i] == target; ++i) {
            r.push_back(i);
        }
        return r;
    }
};