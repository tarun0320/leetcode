class Solution {
public:
    int countCommas(int n) {
        int r = 0;
        for (int i = 1; i <= n; ++i) {
            r += (to_string(i).length() - 1) / 3;
        }
        return r;
    }
};