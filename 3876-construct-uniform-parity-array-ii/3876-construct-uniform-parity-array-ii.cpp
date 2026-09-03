class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        const int n = nums1.size();
        int odd = 0, even = 0, m = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (nums1[i] & 1) {
                ++odd;
            } else {
                ++even;
            }
            m = min(m, nums1[i]);
        }

        return odd == n || even == n || (m & 1);
        
    }
};