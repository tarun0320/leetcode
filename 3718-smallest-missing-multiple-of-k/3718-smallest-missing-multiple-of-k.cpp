class Solution {
public:
     int missingMultiple(vector<int>& nums, int k) {
        for (int mul = k; ; mul += k) {
            if (find(nums.begin(), nums.end(), mul) == nums.end()) {
                return mul;
            }
        }
        return -1;
    }
};