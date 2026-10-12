class Solution {
    const int M = 1000000007;
    int sqr(long long x) {
        return x * x % M;
    }
    
    void add(int &x, int y) {
        if ((x += y) >= M) {
            x -= M;
        }
    }
    
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> v(30);
        for (int x : nums) {
            for (int i = 0; i < 30; ++i) {
                v[i] += (x >> i) & 1;
            }
        }
        vector<int> p(k);
        for (int i = 29; i >= 0; --i) {
            for (int j = 0; j < v[i] && j < k; ++j) {
                p[j] |= 1 << i;
            }
        }
        int r = 0;
        for (int x : p) {
            add(r, sqr(x));
        }
        return r;
    }
};