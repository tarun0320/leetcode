class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        const int n = nums.size();
        map<int, int> have;
        for (int x : nums) {
            ++have[x];
        }
        for (int i = 0, p = 0; i < n; ++i) {
            p = max(p, nums[i]);
            if (p - have.begin()->first <= k) return i;
            if (--have[nums[i]] == 0) {
                have.erase(nums[i]);
            }
        }
        return -1;
        
    }
};