class Solution {
public:
    bool sumGame(string num) {
        const int n = num.length();
        int r = 0;
        for (int i = 0; i < n; ++i) {
            const int c = isdigit(num[i]) ? (num[i] - '0') * 2 : 9;
            r += (i + i < n) ? c : (-c);
        }
        return r;
        
    }
};