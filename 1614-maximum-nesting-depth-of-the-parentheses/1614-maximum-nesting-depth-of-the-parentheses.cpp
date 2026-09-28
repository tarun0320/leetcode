class Solution {
public:
    int maxDepth(string s) {
        int d = 0, m = 0;
        for (char c : s) {
            if (c == '(') {
                m = max(m, ++d);
            } else if (c == ')') {
                --d;
            }
        }
        return m;

        
    }
};