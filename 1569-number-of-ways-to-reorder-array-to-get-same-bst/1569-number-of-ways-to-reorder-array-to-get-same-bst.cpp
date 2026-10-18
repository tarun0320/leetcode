class Solution {
    const int M = 1000000007;
    
    int add(int x, int y) {
        if ((x += y) >= M) x -= M;
        return x;
    }
    
    int mul(long long x, long long y) {
        return x * y % M;
    }
    
    int rev(int x) {
        int r = 1;
        for (int y = M - 2; y; y >>= 1) {
            if (y & 1) {
                r = mul(r, x);
            }
            x = mul(x, x);
        }
        return r;
    }
    
    int dfs(const vector<int> &v, const vector<int> &f, const vector<int>& rf) {
        if (v.size() <= 2) return 1;
        vector<int> v1, v2;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] < v[0]) {
                v1.push_back(v[i]);
            } else {
                v2.push_back(v[i]);
            }
        }
        return mul(mul(dfs(v1, f, rf), dfs(v2, f, rf)), mul(mul(f[v.size() - 1], rf[v1.size()]), rf[v2.size()]));
    }
public:
    int numOfWays(vector<int>& nums) {
        const int n = nums.size();
        vector<int> f(n + 1), rf(n + 1);
        for (int i = f[0] = rf[0] = 1; i <= n; ++i) {
            f[i] = mul(f[i - 1], i);
            rf[i] = rev(f[i]);
        }
        return add(dfs(nums, f, rf), M - 1);
        
    }
};