class Solution {
    void better(int &x, int y) {
        if (x < 0 || x > y) x = y;
    }
public:
    int minOperations(vector<int>& nums, int x) {
        int s = 0;
        for (int y : nums) {
            s += y;
        }
        s -= x;
        if (s < 0) return -1;
        if (s == 0) return nums.size();
        int r = 0;
        bool have = false;
        for (int i = 0, j = 0, sum = 0;; sum -= nums[i++]) {
            for (; j < nums.size() && sum < s; sum += nums[j++])
            ;
            if (sum < s) {
                break;
            }
            if (sum == s) {
                r = max(r, j - i);
                have = true;
            } 
        }
        return have ? (nums.size() - r) : (-1);
    }
};