class Solution {
    long long gcd(long long x, long long y) {
        return y ? gcd(y, x % y) : x;
    }
    
    long long lcm(long long x, long long y) {
        return x / gcd(x, y) * y;
    }
    
    void dfs(const vector<int> &v, long long s, long long x, int ind, int num, long long &ans) {
        if (x > s) return;
        if (ind >= v.size()) {
            if (num == 0) return;
            ans += num & 1 ? (s / x) : (-s / x);
            return;
        }
        dfs(v, s, x, ind + 1, num, ans);
        dfs(v, s, lcm(x, v[ind]), ind + 1, num + 1, ans);
    }
public:
    long long findKthSmallest(vector<int>& coins, int k) {   
        assert(coins.size() > 0 && coins.size() <= 15);
        for (int x : coins) {
            assert(x >= 1 && x <= 25);
        }
        assert(unordered_set<int>(coins.begin(), coins.end()).size() == coins.size());
        assert(k > 0 && k <= 2000000000);
        
        long long left = k, right = static_cast<long long>(*max_element(coins.begin(), coins.end())) * k;
        while (left <= right) {
            const long long mid = (left + right) >> 1;
            long long c = 0;
            dfs(coins, mid, 1, 0, 0, c);
            if (c >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right + 1;
    }
};