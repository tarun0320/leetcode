class Solution {
public:
    int minAddToMakeValid(string s) {
        int d = 0, r = 0;
        for (char c : s) {
            d += c == '(' ? 1 : -1;
            if (d < 0) {
                d = 0;
                ++r;
            }
        }
        return r + d;
        
    }
};