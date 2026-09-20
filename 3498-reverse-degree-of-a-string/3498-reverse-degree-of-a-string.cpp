class Solution {
public:
    int reverseDegree(string s) {
        int r = 0;
        for (int i = 1; i <= s.length(); ++i) {
            r += i * ('z' - s[i - 1] + 1);
        }
        return r;
    }
};