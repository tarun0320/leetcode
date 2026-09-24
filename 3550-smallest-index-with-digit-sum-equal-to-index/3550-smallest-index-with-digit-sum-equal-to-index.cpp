class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int s = 0;
            for (int x = nums[i]; s <= i && x; s += x % 10, x /= 10)
            ;
            if (s == i) return i;
        }
        return -1;
    }
};