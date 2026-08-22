class Solution {
public:
    bool checkDivisibility(int n) {
        int s = 0, p = 1;
        for (int i = n; i; i /= 10) {
            const int x = i % 10;
            p *= x;
            s += x;
        }
        return n % (p + s) == 0;
        
    }
};