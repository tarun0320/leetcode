class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> desc(n);  
        for (int i = 1; i < n; i++) desc[i] = desc[i - 1] + (nums[i - 1] > nums[i]);
        vector<int> premax(n), sufmin(n);
        inclusive_scan(nums.begin(), nums.end(), premax.begin(), [](int a, int b) { return max(a, b); });  
        inclusive_scan(nums.rbegin(), nums.rend(), sufmin.rbegin(), [](int a, int b) { return min(a, b); }); 
        vector<bool> cut(n, true);  
        for (int m = 1; m < n; m++) cut[m] = premax[m - 1] <= sufmin[m];

        auto rotatable = [&](int l, int r) {  
            return desc[r] - desc[l] + (nums[r] > nums[l]) <= 1;
        };
        auto sortable = [&](int k) {  
            for (int l = 0; l < n; l += k)
                if (!cut[l] || !rotatable(l, l + k - 1)) return false;
            return true;
        };

        vector<int> divisors;
        for (int k = 1; k <= n; k++) if (n % k == 0) divisors.push_back(k);
        auto good = divisors | views::filter(sortable);
        return accumulate(good.begin(), good.end(), 0);
    }
};