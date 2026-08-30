class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = 0, maxi = 0;
        const int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[mini]) {
                mini = i;
            } else if (nums[i] > nums[maxi]) {
                maxi = i;
            }
        }
        if (mini > maxi) {
            swap(mini, maxi);
        }
        return min(min(maxi + 1, n - mini), mini + 1 + n - maxi);
    }
};