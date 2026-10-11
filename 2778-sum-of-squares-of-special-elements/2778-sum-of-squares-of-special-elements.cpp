class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        const int n = nums.size();
        int r = 0;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                r += nums[i - 1] * nums[i - 1];
            }
        }
        return r;
    }
};