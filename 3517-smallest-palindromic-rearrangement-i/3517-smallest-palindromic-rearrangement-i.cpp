class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int halfLen = n / 2;
        
        string half = s.substr(0, halfLen);
        sort(half.begin(), half.end());
        
        string rev = half;
        reverse(rev.begin(), rev.end());
        
        if (n % 2 == 0) {
            return half + rev;
        } else {
            return half + s[halfLen] + rev;
        }
    }
};