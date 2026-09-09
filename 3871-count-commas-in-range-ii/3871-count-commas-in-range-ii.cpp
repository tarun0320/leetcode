class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000) {
            return 0;
        } else if (n < 1000000) {
            return (n - 999);
        } else if (n < 1000000000) {
            return 999000LL + (n - 999999LL) * 2;
        } else if (n < 1000000000000LL) {
           
            return 1998999000LL + (n - 999999999LL) * 3;
        } else if (n < 1000000000000000LL) {
            return 2998998999000LL + (n - 999999999999LL) * 4;
        } else {
            return 3998998998999000LL + (n - 999999999999999LL) * 5;
        }
    }
};